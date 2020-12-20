/**
 * Assignment 10. STL Vector and List
 *
 * TImer.cpp
 *
 * Author: Bharathi Vidhya Chandrasekaran
 */

#include "Timer.h"

long Timer::time_it(void f()) throw(string)
{
	auto start_time = steady_clock::now();
   f();
	decltype(start_time) end_time = steady_clock::now();
   long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
   return elapsed_time;
}

long Timer::time_it(SortedVector& sv, const int size,
                    void f(SortedVector&, const int)) throw(string)
{
	auto start_time = steady_clock::now();
	f(sv, size);
	decltype(start_time) end_time = steady_clock::now();
   long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
   return elapsed_time;
}

long Timer::time_it(SortedList& sl, const int size,
                    void f(SortedList&, const int)) throw(string)
{
	auto start_time = steady_clock::now();
	f(sl, size);
	decltype(start_time) end_time = steady_clock::now();
   long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
   return elapsed_time;
}
