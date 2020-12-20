/*
 * WordMap.cpp
 *
 *  Created on: Nov 6, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

int WordMap::get_count(const string text) const
{
	map<string, Word>::const_iterator it = find(text);

	// Get the word count from the concordance.
	if(it != end())		return it->second.get_count();

	else	return 0;
}

void WordMap::insert(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	map<string, Word>::iterator it = find(text);

	// Insert the word if not already inserted
	if(it != end())		it->second.increment_count();

	// If the word is found, increment the word count.
	else	(*this)[text] = Word(text);

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	// Search the word in the concordance.
	map<string, Word>::iterator it = find(text);

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);

	return it;
}
