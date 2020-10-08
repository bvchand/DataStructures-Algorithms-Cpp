/*	180-A Assignment #6
 *  Book.cpp
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

//Default constructor
Book::Book() : isbn(""), last(""), first(""), title(""), category("") {}

//Initialize the values of the private member variables.
Book::Book(string isbn, string last, string first, string title, string category)
	 : isbn(isbn), last(last), first(first), title(title), category(category) {}

//Overload the extraction operator >>
istream& operator >>(istream& in, Book& book)
{
	string line;
	string word;
	vector<string> book_record;

	//Read the book details.
	getline(in, line);
	stringstream s(line);


	while(getline(s, word, ','))
	{
		//Break the book information into fields.
		book_record.push_back(word);
	}

	for(int i = 0; i < book_record[0].length(); i++)
	{
		//Trim the leading blank space in the ISBN value.
		if(book_record[0][i] == ' ')
			book_record[0].erase(i,1);
	}

	//Assign values to the object's member variables.
	book.isbn = book_record[0];
	book.last = book_record[1];
	book.first = book_record[2];
	book.title = book_record[3];

	//Check if the category is one of the three.
	if(book_record[4] == "fiction" || book_record[4] == "history" ||
			book_record[4] == "technical")
	book.category = book_record[4];

	return in;
}

//Overload the insertion operator <<
ostream& operator <<(ostream& out, const Book& new_entry)
{
	//Print the Book details
	out << "Book{ISBN=" << new_entry.get_isbn() << ", last=" << new_entry.get_last() << ", first="
			<< new_entry.get_first() << ", title=" << new_entry.get_title() <<  ", category=" << new_entry.get_category() << "}";
	return out;
}
