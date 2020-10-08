/*	180-A Assignment #5
 *  RomanNumeral.h
 *
 *  Created on: Sep 26, 2020
 *  Author: Bharathi Vidhya Chandraasekaran
 */

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
using namespace std;

class RomanNumeral
{
	//Pubilc member functions.
	public:
		/**
		 * Default constructor
		 */
		RomanNumeral();

		/**
		 * Constructor - gets a decimal and calls a private member.
		 * function 'to_roman' to compute its roman numeral equivalent.
		 * @param num the decimal number.
		 */
		RomanNumeral(int num);

		/**
		 * Constructor - gets a roman numeral and calls a private member.
		 * function 'to_decimal' to compute its decimal equivalent.
		 * @param r_num the roman numeral.
		 */
		RomanNumeral(string r_num);

		/**
		 * Makes the private member variable 'decimal' accessible.
		 * @returns the value of the private member variable 'decimal'.
		 */
		int get_num() const;

		/**
		 * Makes the private member variable 'roman' accessible.
		 * @returns the value of the private member variable 'roman'.
		 */
		string get_rnum() const;

		/**
		 * Computes the sum of the roman numerals by overloading '+' operator.
		 * @param r1 an object of RomanNumeral class.
		 * @param r2 an object of RomanNumeral class.
		 * @returns the sum of the roman numerals.
		 */
		friend string operator+(const RomanNumeral& r1, const RomanNumeral& r2);

		/**
		 * Computes the difference betweeen the roman numerals by overloading '-' operator.
		 * @param r1 an object of RomanNumeral class.
		 * @param r2 an object of RomanNumeral class.
		 * @returns the difference betweeen the roman numerals.
		 */
		friend string operator-(const RomanNumeral& r1, const RomanNumeral& r2);

		/**
		 * Computes the product of the roman numerals by overloading '*' operator.
		 * @param r1 an object of RomanNumeral class.
		 * @param r2 an object of RomanNumeral class.
		 * @returns the product of the roman numerals.
		 */
		friend string operator *(const RomanNumeral& r1, const RomanNumeral& r2);

		/**
		 * Divides a roman numeral by another by overloading '/' operator.
		 * @param r1 an object of RomanNumeral class.
		 * @param r2 an object of RomanNumeral class.
		 * @returns the quotient after dividing a roman numeral by another.
		 */
		friend string operator /(const RomanNumeral& r1, const RomanNumeral& r2);

		/**
		 * Compares the roman numerals for equality.
		 * @param r1 an object of RomanNumeral class.
		 * @param r2 an object of RomanNumeral class.
		 * @returns True/False depending on the equality.
		 */
		friend bool operator ==(const RomanNumeral& r1, const RomanNumeral& r2);

		/**
		 * Compares the roman numerals for inequality.
		 * @param r1 an object of RomanNumeral class.
		 * @param r2 an object of RomanNumeral class.
		 * @returns True/False depending on the inequality.
		 */
		friend bool operator !=(const RomanNumeral& r1, const RomanNumeral& r2);

		/**
		 * Inputs RomanNumeral objects.
		 * @param object of input stream.
		 * @param r1 an object of RomanNumeral class.
		 * @returns Input a Roman numeral value as a string.
		 */
		friend istream& operator >>(istream& ins, RomanNumeral& r1);

		/**
		 * Outputs RomanNumeral objects.
		 * @param object of output stream.
		 * @param r1 an object of RomanNumeral class.
		 * @returns Prints the RomanNumeral value in the output stream.
		 */
		friend ostream& operator <<(ostream& outs, const RomanNumeral& r1);

	//Private member functions and member variables.
	private:
		string roman;
		int decimal;

		/**
		 * Convert a decimal into a roman numeral.
		 * @param decimal the number.
		 * @returns the roman numeral equivalent.
		 */
		string to_roman(int decimal) const;

		/**
		 * Convert a roman numeral into a decimal.
		 * @param roman the roman string.
		 * @returns the decimal equivalent.
		 */
		int to_decimal(string roman) const;
};

#endif /* ROMANNUMERAL_H_ */
