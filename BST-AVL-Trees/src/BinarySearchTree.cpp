/*
 *  BinarySearchTree.cpp
 *
 *  Created on: Nov 20, 2020
 *  Author: Bharathi Vidhya Chandrasekaran
 */

#include <string>
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

// Reference: D.S. Malik textbook
int BinarySearchTree::height(const BinaryNode *ptr) const
{
	int height = 1;
	if(ptr == nullptr)		return 0;

	int depth_left = BinarySearchTree::height(ptr->left);
	int depth_right = BinarySearchTree::height(ptr->right);

	height += max(depth_left, depth_right);

	return height;
}

// Reference: Class slides
BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
    if(ptr == nullptr)		return nullptr;

    while(ptr->left != nullptr)		ptr = ptr->left;
    return ptr;
}


// Reference: Class slides
BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
    if(ptr == nullptr)		return nullptr;

    while(ptr->right != nullptr)		ptr = ptr->right;
    return ptr;
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{
    while(ptr != nullptr)
    {
        if(data > ptr->data)	ptr = ptr->right;
        else if(data < ptr->data)	ptr = ptr->left;
        else	return true;
    }

    return false;
}

// Reference: Class slides
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
	if(ptr == nullptr)	ptr = new BinaryNode(data);
	else if(data > ptr->data)	insert(data, ptr->right);
	else if(data < ptr->data)	insert(data, ptr->left);
	cout << "insert" << data << endl;
}

// Reference: Class slides
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
    if(ptr == nullptr)	return;

    if(data < ptr->data)	remove(data, ptr->left);
    else if(data > ptr->data)	remove(data, ptr->right);
    else if((ptr->left != nullptr) && (ptr->right != nullptr))
    {
    	ptr->data = find_min(ptr->right)->data;
    	remove(ptr->data, ptr->right);
    }
    else
    {
    	BinaryNode *old_node = ptr;
    	ptr = (ptr->left != nullptr) ? ptr->left : ptr->right;
    	delete old_node;
    }
}
