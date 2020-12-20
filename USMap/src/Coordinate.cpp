/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * Coordinate.cpp
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "Coordinate.h"

using namespace std;

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

void Coordinate::set_latitude(double lat)
{
	latitude = lat;
}

void Coordinate::set_longitude(double lon)
{
	longitude = lon;
}

double Coordinate::get_latitude() const
{
	return latitude;
}

double Coordinate::get_longitude() const
{
	return longitude;
}

istream& operator >>(istream &ins, Coordinate &coordinate)
{
	string lat, lon;

	//extract the latitude from the file
	getline(ins, lat, ',');
	//covert string value to double
	coordinate.set_latitude(std::stod(lat));

	//extract the longitude from the file
	getline(ins, lon);
	//covert string value to double
	coordinate.set_longitude(std::stod(lon));

	return ins;
}
