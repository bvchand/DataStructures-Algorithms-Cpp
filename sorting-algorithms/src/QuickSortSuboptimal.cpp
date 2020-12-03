/*
 *  QuickSortSuboptimal.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "QuickSortSuboptimal.h"

Element& QuickSortSuboptimalRight::choose_pivot_strategy(const int left, const int right)
{
	//First element is the pivot
    int pivot = left;
    return data[pivot];
}
