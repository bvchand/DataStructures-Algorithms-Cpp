/*
 *  QuickSorter.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include "QuickSorter.h"
using namespace std;

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

void QuickSorter::quicksort(const int left, const int right)
{
    // Continue the recursive calls until the indexes cross.
    if (left <= right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements <  pivot
        quicksort(p+1, right); // Sort elements >= pivot
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

// Reference: D.S. Malik textbook
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	int smallIndex = left;

	for(int i = left+1; i <= right; i++)
	{
		compare_count++;
		if(data[i] < pivot)
		{
			smallIndex++;
			swap(smallIndex, i);
		}
	}
	swap(left, smallIndex);
	return smallIndex;
}
