/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * City.cpp
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "City.h"

using namespace std;

void City::set_name(string n)
{
	name = n;
}
void City::set_state(string s)
{
	state = s;
}

void City::set_coord(Coordinate& coord)
{
	coordinate = coord;
}

string City::get_name() const
{
	return name;
}

string City::get_state() const
{
	return state;
}

Coordinate& City::get_coord()
{
	return coordinate;
}

istream& operator >>(istream& ins, City& city)
{
	string name, state, lat, lon;

	//extract city name from the file
	getline(ins, name, ',');
	city.set_name(name);

	//extract state from the file
	getline(ins, state, ',');
	city.set_state(state);

	//extract latitude of the city from the file
	getline(ins, lat, ',');
	city.coordinate.set_latitude(std::stod(lat));

	//extract longitude of the city from the file
	getline(ins, lon);
	city.coordinate.set_longitude(std::stod(lon));

	return ins;
}
