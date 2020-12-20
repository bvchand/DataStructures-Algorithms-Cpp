/**
 * Assignment 10. STL Vector and List
 *
 * ---
 *
 * Node.cpp
 *
 * Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include "Node.h"

long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;
long Node::assign_count;

Node::Node(const long the_value)
{
   this->value = the_value;
	constructor_count++;
}

Node::Node(const Node& other)
{
	this->value = other.get_value();
	copy_count++;
}

Node& Node::operator =(const Node& rhs)
{
	assign_count++;
	this->value = rhs.get_value();
   return *this;
}

Node::~Node()
{
	destructor_count++;
}

long Node::get_value() const {return this->value;}

long Node::get_constructor_count() {return constructor_count;}

long Node::get_copy_count() {return copy_count;}

long Node::get_assign_count() {return assign_count;}

long Node::get_destructor_count() {return destructor_count;}

void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	assign_count = 0;
	destructor_count = 0;
}

bool Node::operator ==(const Node& other) const
{
	return this->value == other.value;
}

bool Node::operator <=(const Node& other) const
{
	return this->value <= other.value;
}

bool Node::operator >=(const Node& other) const
{
	return this->value >= other.value;
}

