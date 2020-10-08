/*	180-A Assignment #6
 *  BookApp.cpp
 *
 *  Created on: Oct 3, 2020
 *  Author: Bharathi Vidhya Chandraasekaran
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Book.h"

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};


/**
 * Insert a new book entry into the catalog.
 * @param new_entry the new book.
 * @param catalog the vector of book records.
 */
void insert_entry(Book& new_entry, vector<Book>& catalog);

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, vector<Book>& catalog);

/**
 * Remove a book entry from the catalog.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 */
void remove_record(int isbn_index, vector<Book>& catalog);

/**
 * Perform linear search to search for books with a particular filter.
 * @param line the filer (ISBN, Author name or Category).
 * @param catalog the vector of book records.
 */
void linear_search_by_filter(string line, vector<Book>& catalog);

/**
 * Print the book records based on the status code.
 * @param code the StatusCode object.
 * @param value the index value
 * @param book the book entry
 * @param catalog the vector of book records.
 */
void print_by_status(StatusCode code, string value, Book book, vector<Book>& catalog);


//Input File.
const string INPUT_FILE_NAME = "commands.in";


/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;

    vector<Book> catalog;  // book catalog

    input.open(INPUT_FILE_NAME);

    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    cout << endl;

    /**
     * Loop to read commands until the end of file.
     */
    while (!input.eof())
    {
    	//Create a new book object;
    	Book new_entry;

    	char command = ' ';
    	input >> command;

        switch(command)
        {
        	case '+':
        	{
        		//Read the book details for a + command by overloading the >> operator.
        		input >> new_entry;
        		insert_entry(new_entry, catalog);
        	}
        	break;

        	case '-':
        	{
        		string isbn;
        		getline(input, isbn);

        		//Trim the leading blank space.
				if(isbn[0] == ' ')
					isbn.erase(0,1);

				//Search for ISBN in the catalog using Binary search algorithm.
        		int isbn_index = find(isbn, catalog);

        		//If the book exists, remove the record.
        		if(isbn_index != -1)
        			remove_record(isbn_index, catalog);

        		//If the book does not exist:
        		else
        		{
        			print_by_status(StatusCode::NOT_FOUND, isbn,  new_entry, catalog);
        		}
        	}
        	break;

        	case '?':
        	{
        		string line;
        		getline(input, line);

        		//If the operator is just '?', print all the records.
        		if(line.length() == 0)
        		{
        			cout << "? All books in the catalog:" << endl;
        			for(int i = 0; i < catalog.size(); i++)
        			{
        				cout << catalog[i] << endl;
        			}
        			cout << endl;
        		}

        		//Else, print all the books by filter.
        		else
        		{
        			linear_search_by_filter(line, catalog);
        		}
        	}
        	break;

        	//Ignore a blank line.
        	case ' ':	break;

        	//Penalize the invalid commands.
        	default:
        	{
        		string line;
        		string symbol(1,command);
        		print_by_status(StatusCode::INVALID_COMMAND, symbol, new_entry, catalog);
        		getline(input, line);
        	}
        }
    }

    //Close the input file.
    input.close();
    return 0;
}

void insert_entry(Book& new_entry,vector<Book>& catalog)
{
	bool insert_flag = false;
	bool duplicate_flag = false;
	int i;

	//If there are no books, create a new entry.
	if(catalog.size() == 0)
	{
		catalog.push_back(new_entry);
		cout << "+ Inserted at index 0: " << new_entry << endl;
		cout << endl;
	}

	else
	{
		for(i = 0; i < catalog.size(); i++)
		{
			//If the book already exists:
			if(new_entry.get_isbn() == catalog[i].get_isbn())
			{
				duplicate_flag = true;
				break;
			}

			//Else, create an entry in the catalog in a sorted manner.
			else if(new_entry.get_isbn() < catalog[i].get_isbn())
			{
				catalog.insert((catalog.begin() + i), new_entry);
				insert_flag = true;
				duplicate_flag = false;
				break;
			}
		}

		if(insert_flag == false && duplicate_flag == false)
		{
			//Append the new entry if its ISBN is greater than the ones already in the catalog.
			catalog.push_back(new_entry);
			insert_flag = true;
		}

		if(duplicate_flag == true)
		{
			print_by_status(StatusCode::DUPLICATE, to_string(i), new_entry, catalog);
		}

		else if(insert_flag == true && duplicate_flag == false)
		{
			print_by_status(StatusCode::OK, to_string(i), new_entry, catalog);
		}
	}
}

int find(const string isbn, vector<Book>& catalog)
{
	//If the catalog is empty:
	if(catalog.size() == 0)
	{
		return -1;
	}

	else
	{
		int low = 0;
		int high = catalog.size();

		while(low <= high)
		{
			//Middle element of the vector.
			int mid = (low+high)/2;

			if(catalog[mid].get_isbn() == isbn)
				return mid;

			//If the ISBN of the book to be searched is not equal to the ISBN in the middle,
			//tweak the value of the mid.
			else if(catalog[mid].get_isbn() > isbn)
				high = mid-1;

			else
				low = mid+1;
		}
	}

	return -1;
}

void remove_record(int isbn_index,vector<Book>& catalog)
{
	cout << "- Removed " << catalog[isbn_index] << endl;
	cout << endl;

	//Remove the specified record.
	catalog.erase(catalog.begin() + isbn_index);
}

void linear_search_by_filter(string line, vector<Book>& catalog)
{
	string word;
	vector<string> filter;
	stringstream ss(line);

	//Get the filter and the value to be searched.
	while(getline(ss, word, '='))
	{
		filter.push_back(word);
	}

	//Trim the leading blank spaces.
	if(filter[0][0] == ' ')
		filter[0].erase(0,1);

	//Filter = ISBN:
	if(filter[0] == "isbn")
	{
		cout << "? Book with ISBN " << filter[1] << ":" << endl;
		for(int i = 0; i < catalog.size(); i++)
		{
			if(catalog[i].get_isbn() == (filter[1]))
			{
				//Print the book with the specified ISBN.
				cout << catalog[i] << endl;
			}
		}
		cout << endl;
	}

	//Filter = AUTHOR:
	else if(filter[0] == "author")
	{
		cout << "? Books by author " << filter[1] << ":" << endl;
		for(int i = 0; i < catalog.size(); i++)
		{
			if(catalog[i].get_last() == filter[1])
			{
				//Print the book(s) of the specified author.
				cout << catalog[i] << endl;
			}
		}
		cout << endl;

	}

	//Filter = CATEGORY:
	else if(filter[0] == "category")
	{
		cout << "? Books in category " << filter[1] << ":" << endl;
		for(int i = 0; i < catalog.size(); i++)
		{
			if(catalog[i].get_category() == filter[1])
			{
				//Print the book(s) from the specified category.
				cout << catalog[i] << endl;
			}
		}
		cout << endl;
	}
}

void print_by_status(StatusCode code, string value,  Book book, vector<Book>& catalog)
{
	switch(code)
	{
		//Print the newly inserted record.
		case StatusCode::OK:
		{
			cout << "+ Inserted at index " << value << ": " << book
				 << endl; // value = index
			cout << endl;
		}
		break;

		//Indicate that the specified record is not found.
		case StatusCode::NOT_FOUND:
		{
			cout << "- Removed Book{ISBN=" << value
				 <<", last=, first=, title=, category=none}" << endl; // value = isbn
			cout << "*** Book not found ***" << endl;
			cout << endl;
		}
		break;

		//Indicate that the command is invalid.
		case StatusCode::INVALID_COMMAND:
		{
			cout << value << " *** Invalid command ***" << endl;
			cout << endl;
		}
		break;

		//Indicate that the record already exists.
		case StatusCode::DUPLICATE:
		{
			cout << "+ Inserted at index " << value << ": "
				 << book << endl; // value = index
			cout << "*** Duplicate ISDN ***" << endl;
			cout << endl;
		}
	}
}
