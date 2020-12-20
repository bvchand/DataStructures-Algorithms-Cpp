//============================================================================
// Name        : QuickSort-ST.cpp
// Author      : Bharathi Vidhya Chandrasekaran
// Description : 180A - Assignment 14 - Part 2 - Single threaded Quick sort
// Reference for Quick Sort	: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <chrono>
#include <time.h>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int DATA_SIZE = 1000000;
const string output_file = "QuickSort-ST-output.txt";

int choose_pivot_strategy(vector<int> &data,  int left,  int right);
void quicksort(vector<int> &data,  int left,  int right);
int partition(vector<int> &data,  int left,  int right,  int pivot);
void print_array(vector<int> &data, int size, ofstream &out);
void swap(int* a, int* b);
bool is_sorted(vector<int>& data);


int main()
{
	srand(time(NULL));
	bool sorted;

	ofstream out(output_file);

//    int data[] = {10, 7, 8, 9, 1, 5, 67, 45, 25};

	vector<int> data;
	data.reserve(DATA_SIZE);
	for (int i = 0; i < DATA_SIZE; i++)		data.push_back(i);
	random_shuffle(data.begin(), data.end());

    int n = data.size();

//    out << "Unsorted Array: ";
//    print_array(data, n, out);

    auto start_time = steady_clock::now();
    quicksort(data, 0, n-1);
    auto end_time = steady_clock::now();
    long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();

    sorted = is_sorted(data);

    if(sorted)
    {
        out << "Sorted array: ";
        print_array(data, n, out);
        out << "Time taken for single threaded quicksort : " << elapsed_time << " ms" << endl;
    }
    else
	{
		out << "Not sorted!" << endl;
		print_array(data, n, out);
	}

    cout << "DONE!";
    return 0;
}

bool is_sorted(vector<int>& data) {
for (int i = 1; i < data.size(); i++) {
if (data[i] < data[i-1]) return false; }
    return true;
}

int choose_pivot_strategy(vector<int> &data,  int left,  int right)
{
    int middle = (left + right) / 2;

    if(data[middle] < data[left])	swap(data[middle], data[left]);
    if(data[middle] > data[right])	swap(data[middle], data[right]);
    if(data[left] > data[right])	swap(data[left], data[right]);
    swap(data[left], data[middle]);

    int pivot = left;
    return data[pivot];
}

void quicksort(vector<int> &data, int left, int right)	//producer
{
	if (left <= right)
	{
		int pivot = choose_pivot_strategy(data, left, right);
		int p = partition(data, left, right, pivot);

		quicksort(data, left, p-1);
		quicksort(data, p+1, right);
	}
}

int partition(vector<int> &data,  int left,  int right,  int pivot)
{
		int smallIndex = left;

		for(int i = left+1; i <= right; i++)
		{
			if(data[i] < pivot)
			{
				smallIndex++;
				swap(&data[smallIndex], &data[i]);
			}
		}
		swap(&data[left], &data[smallIndex]);

	return smallIndex;
}

void print_array(vector<int> &data, int size, ofstream &out)
{
    int i;
    int j = 0;
    for (i=0; i < size; i++)
    {
    	j++;
        out << data[i] << " ";
    	if(j == 50)
		{
    		out << endl;
    		j = 0;
		}
    }
    out << endl;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
