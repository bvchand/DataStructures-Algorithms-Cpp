/**
 * Assignment 10. STL Vector and List
 *
 * SortedVector.cpp
 *
 * Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

void SortedVector::prepend(const long value)
{
	vector<Node>::iterator it = vec.begin();
	vec.insert(it, Node(value));
}

void SortedVector::append(const long value)
{
	vec.push_back(Node(value));
}

void SortedVector::insert(const long value)
{
	vector<Node>::iterator it = vec.begin();
	while(it != vec.end())
	{
		if(value > it->get_value())
			it++;
		else
			break;
	}
    vec.insert(it, Node(value));
}

void SortedVector::remove(const int index)
{
	vector<Node>::iterator it = vec.begin()+index;
	vec.erase(it);
}

void SortedVector::reverse()
{
	vector<Node>::iterator it = vec.begin();
	while(it != vec.end())
	{
		it++;
		vec.insert(vec.begin(), *it);
		it = vec.erase(it);
	}
}

bool SortedVector::check() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

Node& SortedVector::operator[](const int index)
{
	return vec[index];
}
