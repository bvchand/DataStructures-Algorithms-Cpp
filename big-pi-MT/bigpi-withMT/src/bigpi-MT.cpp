//============================================================================
// Name        : bipi-MT.cpp
// Author      : Bharathi Vidhya Chandrasekaran
// Description : 180A - Assignment 14 - Part 1
// Reference: https://en.cppreference.com/w/cpp/thread/condition_variable
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <mpir.h>
#include <mpirxx.h>
#include <chrono>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;
using namespace std::chrono;

std::mutex m;
std::condition_variable cv;
bool ready = false;
bool processed = false;

const int MAX_ITERATIONS = 10;				//number of iterations for 1 million digits of Pi
const int PLACES         = 1000000;        // desired decimal places for extra credit
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int GROUP_SIZE = 5;                 // line grouping size

const string OUTPUT_FILE = "bigpi_withMT.txt";		// the output file

void compute_pi_cpp(ofstream &out);
void print(const mpf_t& pi, ofstream &out, double sec, long nsec);
string commafy(long i);
void power4(mpf_t& xxxx, const mpf_t& x);
void y_root4(mpf_t& y_root4, mpf_t& x);

void yi_num_den(mpf_t& result,mpf_t& one,mpf_t& fsqrt, bool num);

void one_plus_yi(mpf_t& sum,mpf_t& one,mpf_t& yi);

int main()
{

	auto timenow =
	      chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Output file
    ofstream out;
    out.open(OUTPUT_FILE);

    // Computes the big pi using the mpf_ functions from the C library.
	out<< "C API: pi to 1,000,000 places:" << endl;
	out << endl;
	compute_pi_cpp(out);
	cout << "Done!";
	return 0;
}

void y_root4(mpf_t& y_root4, mpf_t& x)
{
    mpf_t root2;
    mpf_init(root2);

    mpf_sqrt(root2, x);
    mpf_sqrt(y_root4, root2);
}

void power4(mpf_t& xxxx, const mpf_t& x)
{
    mpf_t xx;
    mpf_init(xx);

    mpf_mul(xx, x, x);
    mpf_mul(xxxx, xx, xx);
}

void yi_num_den(mpf_t& result,mpf_t& one,mpf_t& fsqrt, bool num)
{
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});

	if(num)	mpf_sub(result,one,fsqrt);
	else	mpf_add(result,fsqrt,one);

	processed = true;
    lk.unlock();
    cv.notify_one();
}

void one_plus_yi(mpf_t& sum, mpf_t& yi, mpf_t& one)
{
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});

	mpf_add(sum,yi,one);

	processed = true;
    lk.unlock();
    cv.notify_one();
}

void compute_pi_cpp(ofstream &out)
{

    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

    mpf_t  a_init, y_init, f1,f2, num,  den, yi4, fsqrt, holdYi, oneMinueI, ai, factor1, factor2, yi, sqrt2;
    mpf_t one, six, two, four;
    mpf_init(a_init);
    mpf_init(sqrt2);
    mpf_init(y_init);
    mpf_init(yi);
	mpf_init(f1);
	mpf_init(f2);
	mpf_init(num);
	mpf_init(den);
	mpf_init(yi4);
	mpf_init(fsqrt);
	mpf_init(holdYi);
	mpf_init(oneMinueI);
  	mpf_init(ai);
  	mpf_init(factor1);
  	mpf_init(factor2);

    mpf_init(one);  mpf_set_str(one,  "1", BASE);
    mpf_init(two);  mpf_set_str(two,  "2", BASE);
    mpf_init(four); mpf_set_str(four, "4", BASE);
    mpf_init(six);  mpf_set_str(six,  "6", BASE);

	mpf_sqrt(sqrt2,two);
	mpf_mul(f1, four, sqrt2);
	mpf_sub(f1,six,f1);

	mpf_sqrt(f2,two);
	mpf_sub(f2,sqrt2,one);

	mpf_set(a_init,f1);
	mpf_set(y_init,f2);

    mpf_t pi;
    mpf_init(pi);

	auto start_time = steady_clock::now();

    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
	    	power4(yi4, y_init);
	    	mpf_sub(oneMinueI,one,yi4);
		    y_root4(fsqrt, oneMinueI);


		    //y_i

		    std::thread num_thread(yi_num_den, std::ref(num), std::ref(one), std::ref(fsqrt), true);
		    std::thread den_thread(yi_num_den, std::ref(den), std::ref(one), std::ref(fsqrt), false);

		    {
				std::lock_guard<std::mutex> lk(m);
				ready = true;
			}

		    cv.notify_one();

			{
				std::unique_lock<std::mutex> lk(m);
				cv.wait(lk, []{return processed;});
			}

		    num_thread.join();
		    den_thread.join();

		    mpf_div(y_init,num,den);


		    //a_i part2
		    mpf_set(holdYi,y_init);
		    mpf_pow_ui(factor2,y_init,2u);
		    mpf_add(factor2,y_init,factor2);
		    thread sum_thread1(one_plus_yi, ref(factor2), ref(factor2), ref(one));
		    mpf_mul(factor2,factor2,y_init);				//mul

		    double two = (2*i)+1;
		    double twoP=pow(2,two);

		    mpf_mul_ui(factor2,factor2,twoP);


		    //a_i part1
		    thread sum_thread2(one_plus_yi, ref(factor1), ref(y_init), ref(one));

		    {
				std::lock_guard<std::mutex> lk(m);
				ready = true;
			}

			cv.notify_one();

			{
				std::unique_lock<std::mutex> lk(m);
				cv.wait(lk, []{return processed;});
			}

			sum_thread1.join();
			sum_thread2.join();

		    power4(factor1, factor1);
		    mpf_mul(factor1,factor1,a_init);

		    mpf_sub(a_init,factor1,factor2);
    }

    decltype(start_time) end_time = steady_clock::now();

	// Time in nanosectonds and seconds.
    long nsec = duration_cast<nanoseconds>(end_time-start_time).count();
    double sec = std::chrono::duration<double>(end_time-start_time).count();

	mpf_div(pi,one,a_init);
    print(pi, out, sec, nsec);
}

void print(const mpf_t& pi, ofstream &out, double sec, long nsec)
{


	int group_count=0;
	char *ptr=NULL;
	char *newPtr;
	mp_exp_t exp;
	newPtr = mpf_get_str(ptr,&exp,BASE,PLACES+1,pi);
	out<<newPtr[0]<<"."<<setw(1);

	for(int i =1;i<PLACES+1;i++)
	{
		out<<newPtr[i];
		if(i%BLOCK_SIZE==0)
		{
			out<<setw(2)<<" ";
			if(i%LINE_SIZE==0)
			{
				out<<endl;
				out<<" "<<setw(2);
				group_count++;
				if(group_count%GROUP_SIZE==0)
				{
					out<<endl;
					out<<" "<<setw(1);
				}
			}
		}

	}

    out << endl;

    // Print the elapsed time
	out << "  Elapsed time : " << commafy(nsec) << " nsecs = " << setprecision(9) << fixed << sec << " seconds" << endl;


	out.close();
}

string commafy(long i)
{
    string str = to_string(i);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
