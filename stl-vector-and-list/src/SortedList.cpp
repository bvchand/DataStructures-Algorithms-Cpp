/**
 * Assignment 10. STL Vector and List
 *
 * SortedList.cpp
 *
 * Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

void SortedList::prepend(const long value)
{
	list<Node>::iterator it = lst.begin();
	lst.insert(it, Node(value));
}

void SortedList::append(const long value)
{
	lst.push_back(Node(value));
}

void SortedList::insert(const long value)
{

	list<Node>::iterator it = lst.begin();
	while(it != lst.end())
	{
		if(value > it->get_value())
			it++;
		else
			break;
	}
    lst.insert(it, Node(value));
}

list<Node>::iterator SortedList::node_position(int idx)
{
	if (idx < lst.size()/2)
	{
		list<Node>::iterator it = lst.begin();
		advance(it, idx);
		return it;
	}

	else
	{
		list<Node>::reverse_iterator rit = lst.rbegin();
		advance(rit, (lst.size() - idx - 1));
		return --(rit.base());
	}
}

void SortedList::remove(const int index)
{
	list<Node>::iterator it = node_position(index);
	lst.erase(it);
}

void SortedList::reverse()
{
	list<Node>::iterator it = lst.begin();
	while(it != lst.end())
	{
		it++;
		lst.insert(lst.begin(), *it);
		it = lst.erase(it);
	}
}

bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

Node& SortedList::operator[](const int index)
{
	list<Node>::iterator it = node_position(index);
	return *it;
}
