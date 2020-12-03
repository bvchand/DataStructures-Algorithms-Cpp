/*
 *  QuickSortOptimal.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "QuickSortOptimal.h"

//Reference: https://forums.codeguru.com/showthread.php?465373-RESOLVED-Quicksort-using-median

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    int middle = (left + right) / 2;

    //If middle element is less than the first element, swap them.
    if(data[middle] < data[left])	swap(middle, left);

    //If middle element is greater than the last element, swap them.
    if(data[middle] > data[right])	swap(middle, right);

    //If first element is greater than the last element, swap them.
    if(data[left] > data[right])	swap(left, right);
    compare_count += 3;

    //The pivot would have reached the middle of the vector.
    //Swap the first element with the pivot.
    swap(left, middle);

    int pivot = left;
    return data[pivot];
}
