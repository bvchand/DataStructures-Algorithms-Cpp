/*
 *  LinkedList.cpp
 *
 *  Created on: Nov 15, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
   int list_size = size;

   for (int i = 0; i < list_size; i++)
   {
	  if ( i % 2 == 0)
		 list1.add(remove_head());
	  else
		 list2.add(remove_head());
   }
}

// Reference: D.S. Malik textbook.
void LinkedList::concatenate(LinkedList& other_list)
{
	tail->next = other_list.head;
	tail = other_list.tail;
	size = size + other_list.size;
}
