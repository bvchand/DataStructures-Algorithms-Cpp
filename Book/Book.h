/*	180-A Assignment #6
 *  Book.h
 *
 *  Created on: Oct 3, 2020
 *  Author: Bharathi Vidhya Chandraasekaran
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * The Book class.
 */
class Book {
public:
	/**
	 * Default constructor.
	 */
	Book();

	/**
	 * Constructor.
	 * Initialize the values of the private member variables.
	 * @param isbn the ISBN
	 * @param last Author's last name
	 * @param first Author's first name.
	 * @param title Book title
	 * @param category Book's genre.
	 */
	Book(string isbn, string last, string first, string title, string category);

	//Get the private variables.
	string get_isbn() const
	{
		return isbn;
	}
	string get_last() const
	{
		return last;
	}
	string get_first() const
	{
		return first;
	}
	string get_title() const
	{
		return title;
	}
	string get_category() const
	{
		return category;
	}

	/**
	 * Overload the extraction operator >>
	 * @param in the istream object.
	 * @param new_entry the new book entry.
	 */
	friend istream& operator >>(istream &in, Book &new_entry);

	/**
		 * Overload the insertion operator <<
		 * @param in the ostream object.
		 * @param new_entry the new book entry.
		 */
	friend ostream& operator <<(ostream &out, const Book &new_entry);

	/**
	 * Destructor.
	 */
    ~Book() {}

private:
    //Book attributes.
	string isbn;
	string last;
	string first;
	string title;
	string category;
};

#endif
