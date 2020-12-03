/*
 *  ShellSortOptimal.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "ShellSortOptimal.h"

void ShellSortOptimal::run_sort_algorithm() throw (string)
{
	int h=1;

	//Using Knuth's formula to calculate the intervals
    while (h <= size/3)
    {
        h = h*3 + 1;
    }

    while (h > 0)
    {
        for (int i = h; i< size ; i++)
        {
        	int j;
            Element temp = data[i];

            compare_count++;

            //compare the elements that are h elements away and swap
            //if the larger value is before the smaller value
            for (j = i; j >= h && (data[j-h] > temp); j = j - h)
            {
				if(data[j - h] > temp)
				{
					data[j] = data[j - h];
					move_count++;
				}
				else
				{
					data[j] = temp;
					move_count++;
					break;
				}
            }
        }
        h = (h-1)/3;
    }
}
