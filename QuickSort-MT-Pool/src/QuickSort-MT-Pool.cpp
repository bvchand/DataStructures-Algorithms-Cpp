//============================================================================
// Name        : QuickSort-MT.cpp
// Author      : Bharathi Vidhya Chandraskearan
// Description : 180A - Assignment 14 - Part 2 - Multi-threaded Quick sort
// Reference for Quick Sort	: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
// Reference for thread pool: https://riptutorial.com/cplusplus/example/15806/create-a-simple-thread-pool
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <time.h>
#include <fstream>

using namespace std;
using namespace std::chrono;


const int PRODUCE_RATE = 2;
const int CONSUME_RATE = 5;
const int MAX_THREAD_COUNT = 10;
const int MAX_SIZE = 100;
const int DATA_SIZE = 1000000;
const string output_file = "QuickSort-MT-withpool-output.txt";

bool shouldExit = false;

mutex queue_mutex;
condition_variable condition_not_full;
condition_variable condition_done_or_not_empty;
queue<pair <int, int>> qs_queue;	// Jobs
vector<std::thread> thread_pool;
bool sorted = false;
bool sub_array_not_sorted = true;

bool queue_done_or_not_empty() { return sorted || !qs_queue.empty(); }
bool queue_not_full()	{ return qs_queue.size() < MAX_SIZE; }

int choose_pivot_strategy(vector<int>& data,  int left,  int right);
void quicksort(vector<int>& data,  int left,  int right);
int partition(vector<int>& data,  int left,  int right,  int pivot);
void print_array(vector<int>& data, int size, ofstream &out);
void swap(int* a, int* b);
bool is_sorted(vector<int>& data);
void thread_task(vector<int>& data);
void start(vector<int>& data);


int main()
{
	srand(time(NULL));
	bool sorted;
	vector<int> data;
	ofstream out(output_file);

//    int data[] = {10, 7, 8, 9, 1, 5, 67, 45, 25};
	data.reserve(DATA_SIZE);
	for (int i = 0; i < DATA_SIZE; i++)		data.push_back(i);
	random_shuffle(data.begin(), data.end());

	int n = data.size();

    out << "Unsorted Array: ";
	print_array(data, n, out);

	auto start_time = steady_clock::now();
    qs_queue.push({0, n-1});
    start(data);
	auto end_time = steady_clock::now();
	long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();

	sorted = is_sorted(data);

	if(sorted)
	{
		out << "Sorted array: ";
		print_array(data, n, out); out << endl;
		out << "Time taken for multi-threaded quicksort : " << elapsed_time << " ms" << endl;
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

// start N threads in the thread thread_pool.
void start(vector<int>& data)
{
   for (int i = 0; i < MAX_THREAD_COUNT; i++)
	   thread_pool.push_back(std::thread(thread_task, std::ref(data)));
   for(size_t i = 0;i<thread_pool.size();i++)
	   thread_pool[i].join();
}

void thread_task(vector<int>& data)	// consumer
 {
     while(true)
     {
    	 this_thread::sleep_for(std::chrono::seconds(rand()%CONSUME_RATE));
    	 unique_lock<mutex> lock(queue_mutex);
    	 condition_done_or_not_empty.wait(lock, queue_done_or_not_empty);

    	 if(!qs_queue.empty())
    	 {
    		 pair<int, int> item =  qs_queue.front();
    		 qs_queue.pop();

    		 quicksort(data, item.first, item.second);

    		 if(qs_queue.size() < MAX_SIZE-1 && qs_queue.size() > 0)
    			 condition_done_or_not_empty.notify_one();
    		 lock.unlock();
    	 }
    	 else
    	 {
    		 lock.unlock();
    		 break;
    	 }
     }
 }

int choose_pivot_strategy(vector<int>& data,  int left,  int right)
{
    int middle = (left + right) / 2;

    if(data[middle] < data[left])	swap(&data[middle], &data[left]);
    if(data[middle] > data[right])	swap(&data[middle], &data[right]);
    if(data[left] > data[right])	swap(&data[left], &data[right]);
    swap(&data[left], &data[middle]);

    int pivot = left;
    return data[pivot];
}

void quicksort(vector<int>& data, int left, int right)	//producer
{
	this_thread::sleep_for(std::chrono::seconds(rand() % PRODUCE_RATE));
	unique_lock<mutex> lock(queue_mutex);
	condition_not_full.wait(lock, queue_not_full);

	sub_array_not_sorted = false;
	if (left <= right)
	{
		int pivot = choose_pivot_strategy(data, left, right);
		int p = partition(data, left, right, pivot);

		qs_queue.push({left, p-1});
		qs_queue.push({p+1, right});
	}
	else
	{
		sorted = true;
		condition_done_or_not_empty.notify_all();
	}
	if (qs_queue.size() >= 1) condition_done_or_not_empty.notify_one();
	sub_array_not_sorted = true;
	lock.unlock();
}

int partition(vector<int>& data,  int left,  int right,  int pivot)
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

void print_array(vector<int>& data, int size, ofstream &out)
{
    int i;
    for (i=0; i < size; i++)
        out << data[i] << " ";
    out << endl;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
