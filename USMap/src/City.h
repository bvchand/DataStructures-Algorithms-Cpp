/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * City.h
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */


#ifndef CITY_H_
#define CITY_H_

#include "Coordinate.h"

using namespace std;/*

/**
 * City data.
 */
class City
{

public:

	/**
	 * Name of the city
	 * @param name the city name
	 */
    void set_name(string name);

    /**
	 * State where the city belongs
	 * @param state the state where the city belongs
	 */
    void set_state(string state);

    /**
	 * Coordinates of the city
	 * @param coord the coordinates of the city
	 */
    void set_coord(Coordinate& coord);

	/**
	 * Get the name of the city
	 * @return name the city name
	 */
    string get_name() const;

    /**
	 * Get the state where the city belongs
	 * @return state the state where the city belongs
	 */
    string get_state() const;

    /**
	 * Get the coordinates of the city
	 * @return coord the coordinates of the city
	 */
    Coordinate& get_coord();


    /**
     * Overloaded input stream operator to read a city
     * from an input stream.
     * @param ins the input stream.
     * @param city the city to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, City& city);

private:
    string name; //City name
    string state; //State
    Coordinate coordinate; //City coordinates - latitude and longitude
};

#endif /* CITY_H_ */
