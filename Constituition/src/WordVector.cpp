/*
 * WordVector.cpp
 *
 *  Created on: Nov 6, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */


#include <iostream>
#include <iterator>
#include "WordVector.h"

using namespace std;
using namespace std::chrono;

int WordVector::find(const string text, int low, int high) const
{
	vector<Word>::const_iterator it = begin();

	// Binary search.
	while(low < high)
	{
		int mid = (high + low) / 2;
		if((it+mid) -> get_text() == text)	return mid;
		if((it+mid) -> get_text() < text)	low = mid + 1;
		else	high = mid;
	}

	return -(low+1);
}

void WordVector::insert(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	if(size() == 0)	push_back(Word(text));
	else
	{
		// Find the index where the word is already present or to be inserted.
		int index = find(text, 0, size());

		if(index < 0)
		{

			// Insert the Word in the position that the iterator is pointing to.
			index *= -1;
			vector<Word>::iterator it = begin()+index-1;
			vector<Word>::insert(it, Word(text));

		}
		else
		{
			// Word is already present -  increment the count.
			vector<Word>::iterator it = begin()+index;
			it -> increment_count();
		}
	}

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}

int WordVector::get_count(const string text) const
{
	// Find the index where the word is already present.
	if(size() == 0) return 0;
	else
	{
		int index = find(text, 0, size());
		if(index < 0)	return 0;
		else
		{
			// Get the word count from the concordance.
			vector<Word>::const_iterator it = begin()+index;
			return it -> get_count();
		}
	}
}

vector<Word>::iterator WordVector::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	// Find the index where the word is already present.
	int index = find(text, 0, size());

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);

	if(index < 0) return end();
	else	return begin()+index;
}




