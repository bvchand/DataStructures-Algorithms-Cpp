/*
 *  MergeSort.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include <string>
#include "MergeSort.h"
#include "LinkedList.h"

void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

void MergeSort::mergesort(LinkedList& list)
{
	LinkedList sublist1, sublist2;

	//If the list is empty or has only one element, it cannot be split further.
	if(list.get_head() == nullptr || list.get_head()->next == nullptr)
	{
		return;
	}

	//split the lists
	list.split(sublist1, sublist2);

	//split the lists further recursively
	mergesort(sublist1);
	mergesort(sublist2);

	merge(list, sublist1, sublist2);
}

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{

	// if one of the two sublists is empty, append the other sublist to the master list
	if(sublist1.get_head() == nullptr)
		list.concatenate(sublist2);

	else if(sublist2.get_head() == nullptr)
		list.concatenate(sublist1);

	//If both lists are not empty, compare the heads of both the sublists and
	//add them to the master list in a sorted fashion
	while(sublist1.get_head() != nullptr && sublist2.get_head() != nullptr)
	{
		if(sublist1.get_head()->element < sublist2.get_head()->element)
			list.add(sublist1.remove_head());

		else	list.add(sublist2.remove_head());
		move_count++;
		compare_count++;
	}

	//Once one of the lists is empty, append the remaining elements of the other sublist
	//to the master list
	if(sublist1.get_head() == nullptr && sublist2.get_head()!=nullptr)
	{
		move_count++;
		list.concatenate(sublist2);
	}
	else if(sublist1.get_head()!=nullptr && sublist2.get_head()==nullptr)
	{
		move_count++;
		list.concatenate(sublist1);
	}
}

void MergeSort::clear() { data.clear(); }
