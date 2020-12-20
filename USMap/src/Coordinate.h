/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * Coordinate.h
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate {
public:

	/**
	 * Get the latitude of the coordinate
	 * @returns latitude
	 */
	double get_latitude() const;

	/**
	 * Get the longitude of the coordinate
	 * @returns longitude
	 */
	double get_longitude() const;

	/**
	 * Set a value to the latitude of the coordinate
	 * @params latitude the latitude value
	 */
	void set_latitude(double latitude);

	/**
	 * Set a value to the longitude of the coordinate
	 * @params longitude the longitude value
	 */
	void set_longitude(double longitude);

	/**
	 * Overloaded input stream extraction operator
	 * to read a coordinate from an input stream.
	 * @param ins the input stream.
	 * @param coordinate the coordinate to read.
	 * @return the input stream.
	 */
	friend istream& operator >>(istream &ins, Coordinate &coordinate);

	// Constants for this app's input data.
	static const double MAX_LATITUDE;
	static const double MIN_LONGITUDE;

private:
	double latitude;
	double longitude;
};

#endif /* COORDINATE_H_ */
