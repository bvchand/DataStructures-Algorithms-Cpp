/*
 * WordList.cpp
 *
 *  Created on: Nov 6, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include "WordList.h"

using namespace std;
using namespace std::chrono;


void WordList::insert(const string text)
{
	list<Word>::iterator it = begin();
	bool already_inserted = false;

	// Start time.
	steady_clock::time_point start_time = steady_clock::now();

	if(size() == 0)	push_back(Word(text));
	else
	{
		while(it != end())
		{
			// If text in concordance < given text, keep traversing.
			if(it->get_text() < text)
			{
				it++;
				continue;
			}

			// If text in concordance == given text, increment the word count.
			if(it->get_text() == text)
			{
				it -> increment_count();
				already_inserted = true;
				break;
			}

			// If text in concordance > given text, break from the loop.
			else	break;
		}

		// Insert the word if not already inserted
		if(!already_inserted)	list<Word>::insert(it, Word(text));
	}

	// End time.
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}


int WordList::get_count(const string text)
{
	for(list<Word>::iterator it = begin(); it != end(); it++)
	{
		// Get the word count from the concordance.
		if(it->get_text() == text)	return it->get_count();
	}
	return 0;
}


list<Word>::iterator WordList::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	for(list<Word>::iterator it = begin(); it != end(); it++)
	{
		// Search the word in the concordance.
		if(it->get_text() == text)
		{
			steady_clock::time_point end_time = steady_clock::now();
			increment_elapsed_time(start_time, end_time);

			return it;
		}
	}

	return end();
}
