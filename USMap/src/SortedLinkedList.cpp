/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * SortedLinkedList.cpp
 *
 *  Created on: Oct 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include "SortedLinkedList.h"

SortedLinkedList::SortedLinkedList() : head(nullptr)
{}

void SortedLinkedList::insert(Node *node)
{
	//pointer to traverse the linked list
	Node *p = head;

	//pointer for the previous node
	Node *prev = head;

	//inserting the first element into the sorted linked list
	if(p == nullptr)
	{
		head = node;
	}

	//inserting at the beginning of the existing sorted linked list
	else if(*node < *head)
	{
		node->next = head;
		head = node;
	}
	else
	{
		//inserting into the middle of the existing sorted linked list
		while(p != nullptr && (*node > *p))
		{
			prev = p;
			p = p->next;
		}
		prev->next = node;
		node->next = p;
	}
}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	//point to the head of the linked list
	Node* node = list.head;

	//traverse until the list ends
	while(node != nullptr)
	{
		//print each node (boundary or city)
		outs << *node;
		node = node->next;
	}

	return outs;
}
