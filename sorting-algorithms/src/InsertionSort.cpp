/*
 *  InsertionSort.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "InsertionSort.h"

//Reference: D.S. Malik textbook
void InsertionSort::run_sort_algorithm() throw (string)
{
   for(int i = 1 ; i<size; i++)
   {
	   int j;
       Element temp = data[i];

       //swap if the previous element is larger than the i-th element
       for(j = i; (j>0 && data[j-1]> temp); j--)
       {
           data[j] = data[j-1];
           compare_count ++;
           move_count ++;
       }
       data[j]=temp;
   }
}
