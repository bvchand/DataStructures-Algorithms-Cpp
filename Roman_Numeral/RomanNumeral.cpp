/*	180-A Assignment #5
 *  RomanNumeral.cpp
 *
 *  Created on: Sep 26, 2020
 *  Author: Bharathi Vidhya Chandraasekaran
 */

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include "RomanNumeral.h"

using namespace std;

//Roman string is initalized to an empty string and decimal is initalized to zero.
RomanNumeral::RomanNumeral() : roman(""), decimal(0)	{}

//The member variables are intialized to the input roman numeral and its corresponding decimal equivalent.
RomanNumeral::RomanNumeral(string r_num) :roman(r_num), decimal(to_decimal(r_num))	{}

//The member variables are intialized to the input decimal and its corresponding roman numeral equivalent.
RomanNumeral::RomanNumeral(int num) : roman(to_roman(num)), decimal(num)	{}

//The getter functions are declared as const since they do not change the member variable values.
int RomanNumeral::get_num() const
{
	return decimal;
}

string RomanNumeral::get_rnum() const
{

	return roman;
}

//The private member function 'to_roman' is declared as const
//since it does not change the member variable values.
string RomanNumeral::to_roman(int num) const
{
	//Initialize the numbers and their corresponding roman numerals
	vector<int> numbers = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	vector<string> r_sym = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

	string r_num = "";

	//Convert each digit of the decimal to a roman character incrementally.
	for(int i = 12; num > 0; i--)
	{
		//Divide the input decimal by each deimal in the numbers vector.
		int remain = num/numbers[i];

		//The remainder will now be converted to a roman numeral
		num %= numbers[i];

		//Compute the equivalent roman string of the quotient
		//from the r_sym character vector.
		while(remain != 0)
		{
			r_num += r_sym[i];
			remain--;
		}
	}

	//Return the roman numeral
	return r_num;
}

/**
 * Convert each roman charater to its decimal equivalent
 * @param ch the roman numeral character
 * @returns the decimal equivalent
 */
int decimal_value(char ch)
{
	switch(ch)
	{
		case 'I': 	return 1;
		case 'V': 	return 5;
		case 'X':	return 10;
		case 'L':	return 50;
		case 'C':	return 100;
		case 'D':	return 500;
		case 'M':	return 1000;
		default:	return -1;
	}
}

//The private member function 'to_decimal' is declared as const
//since it does not change the member variable values.
int RomanNumeral::to_decimal(string r_num) const
{
	int num = 0;
	int temp1, temp2;

	//Convert each character of the roman numeral to a decimal incrementally.
	for(int i = 0; i < r_num.length(); i++)
	{
		//Find the decimal value of the roman numeral character
		temp1 = decimal_value(r_num[i]);

		if(i+1 < r_num.length())
		{
			//Find the decimal value of the following roman numeral character
			temp2 = decimal_value(r_num[i+1]);

			//If the successive character is greater than the preceding character,
			//the add the decimal value of the preceding character to the final decimal.
			if(temp1 >= temp2)
			{
				num += temp1;
			}
			else
			{
				//else add the difference of both the deicmal values to the final decimal .
				num += (temp2 - temp1);
				i++;
			}
		}
		else
		{
			num += temp1;
		}
	}
	return num;
}

string operator +(const RomanNumeral& r1, const RomanNumeral& r2)
{
	//Obtain the decimal equivalent of the input roman numerals.
	int d1 = r1.decimal;
	int d2 = r2.decimal;

	//Add the decimal values.
	int sum = d1 + d2;

	RomanNumeral r(sum);

	//Return the roman equivalent of the result.
	return r.roman;
}

string operator -(const RomanNumeral& r1, const RomanNumeral& r2)
{
	//Obtain the decimal equivalent of the input roman numerals.
	int d1 = r1.decimal;
	int d2 = r2.decimal;

	//Compute the absolute difference between the decimal values.
	int diff = abs(d1 - d2);

	RomanNumeral r(diff);

	//Return the roman equivalent of the result.
	return r.roman;

}

string operator *(const RomanNumeral& r1, const RomanNumeral& r2)
{
	//Obtain the decimal equivalent of the input roman numerals.
	int d1 = r1.decimal;
	int d2 = r2.decimal;

	//Compute the product of the decimal values.
	int product = d1 * d2;

	RomanNumeral r(product);

	//Return the roman equivalent of the result.
	return r.roman;
}

string operator /(const RomanNumeral& r1, const RomanNumeral& r2)
{
	//Obtain the decimal equivalent of the input roman numerals.
	int d1 = r1.decimal;
	int d2 = r2.decimal;

	//Compute the quotient when one decimal is divided by the other.
	int quotient = d1 / d2;

	RomanNumeral r(quotient);

	//Return the roman equivalent of the result.
	return r.roman;
}

bool operator ==(const RomanNumeral& r1, const RomanNumeral& r2)
{
	//Obtain the decimal equivalent of the input roman numerals.
	int d1 = r1.decimal;
	int d2 = r2.decimal;

	//Return True if they are equal.
	if(d1 == d2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const RomanNumeral& r1, const RomanNumeral& r2)
{
	//Obtain the decimal equivalent of the input roman numerals.
	int d1 = r1.decimal;
	int d2 = r2.decimal;

	//Return True if they are not equal.
	if(d1 != d2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream& operator >>(istream &ins, RomanNumeral& r1)
{
	char ch;
	string roman;

	ins >> ch;

	//Read the roman string from the input file.
	if((ch != '+')  && (ch != '-')  && (ch != '*')  && (ch != '/'))
	{
		ins >> roman;
		r1.roman = roman;
		r1.decimal = r1.to_decimal(roman);
	}
	return ins;
}

ostream& operator <<(ostream& outs, const RomanNumeral& r1)
{
	//Output the results in this format: [decimal:string]
	outs << "[" << r1.decimal << ":" << r1.roman << "]";
	return outs;
}




//int RomanNumeral::to_decimal(string r_num) const
//{
//	vector<int> numbers = {1,5,10,50,100,500,1000};
//	vector<char> r_sym = {'I','V','X','L','C','D','M'};
////	string r_num = r1.roman;
//
//	int num = 0;
//	vector<char>::iterator index;
//	int temp1, temp2;
//
//	for(int i = 0; i <= r_num.length(); i++)
//	{
//		if(std::find(r_sym.begin(), r_sym.end(), r_num[i]) != r_sym.end())
//		{
//			index = std::find(r_sym.begin(), r_sym.end(), r_num[i]);
//			temp1 = numbers[index - r_sym.begin()];
//
//			if(i+1 < r_num.length())
//			{
//				index = std::find(r_sym.begin(), r_sym.end(), r_num[i+1]);
//				temp2 = numbers[index - r_sym.begin()];
//
//				if(temp1 >= temp2)
//				{
//					num += temp1;
//				}
//				else
//				{
//					num += (temp2 - temp1);
//					i++;
//				}
//			}
//			else
//			{
//				num += temp1;
//			}
//		}
//	}
//	return num;
//}
