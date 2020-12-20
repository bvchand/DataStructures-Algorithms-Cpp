/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * Node.cpp
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "Node.h"
#include "Coordinate.h"
#include "City.h"

int row = 0;
int col = 0;

Node::Node(Coordinate& coordinate)
{
	//convert the coordinate object into row and col.
	convert_coordinate(coordinate);
	next = nullptr;
}

Node::Node(City& city)
{
	//convert the city object into name, state, row and col.
	convert_city(city);
	next = nullptr;
}

void Node::convert_city(City& city)
{
    name = city.get_name();
    state = city.get_state();
    convert_coordinate(city.get_coord());
}

void Node::convert_coordinate(Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

ostream& operator <<(ostream& outs, const Node& node)
{
	if(row == node.row)
	{
		//if the city is printed inside the boundary
		int difference = node.col - col;
		if(difference > 0)
		{
			while(difference > 1)
			{
				outs << " ";
				difference--;
			}

			//print the city name and state
			if(node.name != "" && node.state != "")
			{
				outs << "*" << node.name << " " << node.state;
				int len = node.name.length() + node.state.length() + 1;
				col = node.col + len;
			}

			//print the boundary
			else
			{
				outs << "#";
				col = node.col;
			}
		}
	}
	else //traverse through the rows
	{
		col = 0;
		while(node.row != row)
		{
			outs << endl;
			row++;
		}

		int difference = node.col - col;
		while(difference > 1)
		{
			outs << " ";
			difference--;
		}

		//print the city name and state
		if(node.name != "" && node.state != "")
		{
			outs << "*" << node.name << " " << node.state;
			int len = node.name.length() + node.state.length() + 1;
			col = node.col + len;
		}

		//print the boundary
		else
		{
			outs << "#";
			col = node.col;
		}
	}

	//if the pointer reaches the end of the row and column, reset the values to 0.
	if(node.next == nullptr)
	{
		row = 0;
		col = 0;
	}

	return outs;
}

bool Node::operator <(const Node& other)
{
	//if row is equal and col is smaller
	if((this->row == other.row) && (this->col < other.col))
		return true;

	//if row is smaller
	else if(this->row < other.row)
		return true;

	return false;
}

bool Node::operator >(const Node& other)
{
	//if row is equal and col is greater
	if((this->row == other.row) && (this->col > other.col))
		return true;

	//if row is greater
	else if(this->row > other.row)
		return true;

	return false;
}
