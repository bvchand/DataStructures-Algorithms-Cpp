/*
 *  ShellSortSuboptimal.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "ShellSortSuboptimal.h"

// ShellSortSuboptimal logic inspired from https://www.geeksforgeeks.org/shellsort/

void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
	//Split the vector into 2 halves.
    for(int h = size/2; h > 0; h /= 2)
    {
    	for(int i = h; i < size; i++)
    	{
    		int j;
    		Element temp = data[i];

            //compare the elements that are h elements away and swap
            //if the larger value is before the smaller value
    		for (j = i; j >= h; j -= h)
    		{
				compare_count++;
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
    }
}
