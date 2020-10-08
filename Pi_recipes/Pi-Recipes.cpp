//============================================================================
// Name        : Pi-Recipes.cpp
// Author      : Bharathi Vidhya Chandrasekaran
// Version     : 0.0
// Copyright   : Your copyright notice
// Description : Pi Recipes in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_ITERATIONS = 20;
const double TOLERANCE      = 1.0e-17;

/**
 * Compute the factorial of an integer value.
 * @param n the value.
 * @return n! as a double.
 */
double factorial(int n);

/**
 * Compute the arctangent of a double value.
 * @param x the value.
 * @return an estimate of arctan(x).
 */
double arctangent(double x);

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_0();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_1();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_2();

/**
 * Compute an estimate of pi using a formula by the Chudnovsky brothers.
 * @return an estimate of pi.
 */
void Chudnovsky();

/**
 * Compute an estimate of pi using an arctangent formula by Machin.
 * @return an estimate of pi.
 */
void Machin();

int main()
{
    cout << fixed << setprecision(16);

    cout << endl;
    cout << "Ramanujan pi recipe #0:" << endl << endl;
    Ramanujan_0();

    cout << endl;
    cout << "Ramanujan pi recipe #1:" << endl << endl;
    Ramanujan_1();

    cout << endl;
    cout << "Ramanujan pi recipe #2:" << endl << endl;
    Ramanujan_2();

    cout << endl;
    cout << "Chudnovsky pi recipe:" << endl << endl;
    cout << "  Iteration  Estimate" << endl;
    Chudnovsky();

    cout << endl;
    cout << "Machin pi recipe:" << endl << endl;
    Machin();

    return 0;
}

/**
 * Factorial computation
 * @param n: the value
 * @return n! = 1∙2∙3∙ ⋯ ∙(n-2)∙(n-1)∙n
 */

double factorial(int n)
{
    double nf = 1;
    for (int i = 2; i <= n; i++) nf *= i;
    return nf;
}

/**
 * C++ built-in square root and natural logarithm functions are used
   to calculate Pi value using Ramanujan Formula #0
 * @return pi = 3.1415926535897936
*/

void Ramanujan_0()
{
	double factor0 = 12 / sqrt(190);
	double factor1 = log(((2 * sqrt(2)) + sqrt(10)) * (3 + sqrt(10)));
	double pi = factor0 * factor1;
	cout << "  Estimate:  " << pi << endl;

}

/**
 * Pi value calculation using Ramanujan Formula #1
 * do.. while() is performed so as to ensure that the pi value
   is calculated at least through a single iteration
 * @return pi values until two consecutive pi estimates differ
   by less than 10^-17 or until the iteration count reaches 20
*/

void Ramanujan_1()
{
    cout << "  Iteration  Estimate" << endl;

    double one_over_pi;
    double factor0 = sqrt((double) 8) / (99 * 99);
    double sum  = 0.0;
    double prev = 0.0;
    double diff = 0.0;

    int n = 0;

    do
    {
        double factor1 = factorial(4 * n) / pow((pow(4.0, n) * factorial(n)), 4);
        double factor2 = ((double) 1103 + 26390 * n) / pow((double) 99, 4 * n);

        sum += factor1 * factor2;

        one_over_pi = factor0 * sum;
        cout << setw(11) << n+1 << "  " << 1.0/one_over_pi << endl;

        diff = abs(prev - one_over_pi);
        prev = one_over_pi;
        n++;
    } while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

/**
 * Pi value calculation using Ramanujan Formula #2
 * @return pi values until two consecutive pi estimates
   differ by less than 10^-17 or until the iteration count reaches 20
*/

void Ramanujan_2()
{
	cout << "  Iteration Estimate" << endl;

	double four_over_pi;
	double factor0 = 1.0 / 882.0;
	double sum = 0.0;
	double prev = 0.0;
	double diff = 0.0;
	int n = 0;

	do
	{
		double factor1 = pow(-1.0, n) * factorial(4 * n);
		double factor2 = pow(((pow(4.0, n)) * factorial(n)), 4);
		double factor3 = 1123.0 + (21460.0 * n);
		double factor4 = pow(882.0, (2*n));

		sum += (((double) factor1 / (double) factor2) * ((double) factor3 / (double) factor4));
		four_over_pi = (double) factor0 * sum;

		cout << setw(11) << n+1 << "  " << 4.0/four_over_pi << endl;

		diff = abs(prev - four_over_pi);
		prev = four_over_pi;
		n++;

	} while((diff > TOLERANCE) && (n <= MAX_ITERATIONS));

}

/**
 * Pi value calculation using Chudnovsky Formula
 * @return pi values until two consecutive pi estimates
   differ by less than 10^-17 or until the iteration count reaches 20
*/

void Chudnovsky()
{
	double one_over_pi;
	double sum = 0.0;
	double diff = 0.0;
	double prev = 0.0;
	int n = 0;

	do
	{
		double factor1 = pow(-1.0, n) * factorial(6 * n);
		double factor2 = factorial(3.0 * n) * pow(factorial(n), 3);
		double factor3 = 13591409.0 + (545140134.0 * n);
		double factor4 = pow(pow(640320.0, 3), (n + 0.5));

		sum += (((double) factor1 / (double) factor2) * ((double) factor3 / (double) factor4));
		one_over_pi = 12.0 * sum;

		cout << setw(11) << n+1 << "  " << 1.0/one_over_pi << endl;

		diff = abs(prev - one_over_pi);
		prev = one_over_pi;
		n++;

	} while((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

/**
 * Arctangent computation using the Taylor series
 * @param x: to compute the arctangent
 * @return arctangent value to the Machin function
*/

double arctangent(double x)
{
    double arctan = x;
    double diff = 0.0;
    double prev = x;
    double n = 3;
    int i = 1;

    do
	{

    	arctan += pow(-1,i) * (pow(x, n) / (double) n);
    	diff = abs(prev - arctan);
    	prev = arctan;
    	n += 2;
    	i++;

	} while(diff > TOLERANCE);


    return arctan;
}

/**
 * Pi value calculation using Machin Formula
 * Pi values are computed by invoking the arctangent funstion
*/

void Machin()
{
    double pi_over_4 = 4 * arctangent(0.2) - arctangent(1.0 / 239.0);
    cout << "  Estimate:  " << 4 * pi_over_4 << endl;
}
