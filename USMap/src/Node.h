/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * Node.h
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:

    Node *next;

    /**
     * Constructor with coordinate object
     */
    Node(Coordinate& coordinate);

    /**
     * Constructor with city object
     */
    Node(City& city);

    /**
     * Overloaded > operator to compare two nodes.
     */
    bool operator >(const Node& other);

    /**
     * Overloaded > operator to compare two nodes.
     */
    bool operator <(const Node& other);

    /**
     * Overloaded stream output insertion operator
     * to output a node to the output stream.
     * @param outs the output stream.
     * @param node the node to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const Node& node);

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column


    /**
     * Convert a coordinate to a row and a column.
     * @param coordinate the coordinate to convert.
     */
    void convert_coordinate(Coordinate& coordinate);


    /**
     * Convert a city to a name, state, row and column.
     * @param city the city to convert.
     */
    void convert_city(City& city);
};

#endif /* NODE_H_ */
