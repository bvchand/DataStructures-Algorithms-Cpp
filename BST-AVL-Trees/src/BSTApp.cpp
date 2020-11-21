/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"

using namespace std;

const bool DUMP = false;

/**
 * Run the test with a binary search tree.
 */
void testBST();

/**
 * Run the test with an AVL tree.
 */
void testAVL();

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param maxNodes the maximum number of nodes to generate.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param kind either "BST" or "AVL".
 */
void buildTree(BinarySearchTree& tree,
               BinaryTreeChecker& checker,
               BinaryTreePrinter& printer,
               string kind);

/**
 * Dismantle a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param kind either "BST" or "AVL".
 */
void dismantleTree(BinarySearchTree& tree,
                   BinaryTreeChecker& checker,
                   BinaryTreePrinter& printer,
                   string kind);

/**
 * Main.
 */
int main( )
{
    testBST();
//    testAVL();
}

void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree  bst;
    BinaryTreeChecker checker(bst);
    BinaryTreePrinter printer(bst);

    buildTree(bst, checker, printer, "BST");
    cout << "getting here???" << endl;
    dismantleTree(bst, checker, printer, "BST");
}

//void testAVL()
//{
//    cout << endl;
//    cout << "************" << endl;
//    cout << "* AVL TREE *" << endl;
//    cout << "************" << endl;
//
//    AvlTree avl;
//    BinaryTreeChecker checker(avl);
//    BinaryTreePrinter printer(avl);
//
//    buildTree(avl, checker, printer, "AVL");
//    dismantleTree(avl, checker, printer, "AVL");
//}

static const int VALUES[] =
{
    62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,
	49,82,37,94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28
};

void buildTree(BinarySearchTree& tree,
              BinaryTreeChecker& checker,
              BinaryTreePrinter& printer,
              string kind)
{
	cout << "buidTree  "<<"getting here???" << endl;
    int status = BinaryTreeChecker::NO_ERROR;

    for (int n : VALUES)
    {
        cout << endl << "Insert node " << n << ":" << endl;

        tree.insert(n);  // insert into tree
//        cout <<"getting here?" << endl;
        checker.add(n);  // store with the tree checker

        cout << endl;
        printer.print();

        status = checker.check(DUMP);
//        cout << "************" << endl;
//        cout << status << endl;
        if (status != BinaryTreeChecker::NO_ERROR) break;
    }

    // What was the status?
    switch (status)
    {
        case BinaryTreeChecker::NO_ERROR:
        {
            cout << endl;
            cout << "*****" << endl;
            cout << "***** COMPLETED " << kind << " TREE:" << endl;
            cout << "*****" << endl << endl;
            printer.print();

            break;
        }

        case BinaryTreeChecker::DATA_MISMATCH:
        {
            cout << ">>>>> Data mismatch." << endl;
            break;
        }

        case BinaryTreeChecker::INSUFFICIENT_DATA:
        {
            cout << ">>>>> Data missing from tree." << endl;
            break;
        }

        case BinaryTreeChecker::REMAINING_DATA:
        {
            cout << ">>>>> Data remaining in tree." << endl;
            break;
        }
    }
}

void dismantleTree(BinarySearchTree& tree,
                   BinaryTreeChecker& checker,
                   BinaryTreePrinter& printer,
                   string kind)
{
    int status = BinaryTreeChecker::NO_ERROR;

    // Delete the root node each time through the loop.
    // Print the tree after each deletion.
    while (!tree.is_empty())
    {
        BinaryNode *root = tree.get_root();
        int data = root->data;
        cout << endl << "Delete root node " << data << ":" << endl;

        tree.remove(data);
        checker.remove(data);

        cout << endl;
        printer.print();

        status = checker.check(DUMP);
        if (status != BinaryTreeChecker::NO_ERROR) break;
    }

    // What was the status?
    switch (status)
    {
        case BinaryTreeChecker::NO_ERROR:
        {
            cout << "*****" << endl;
            cout << "***** THE " << kind << " TREE IS NOW EMPTY." << endl;
            cout << "*****" << endl << endl;

            break;
        }

        case BinaryTreeChecker::DATA_MISMATCH:
        {
            cout << ">>>>> Data mismatch.";
            break;
        }

        case BinaryTreeChecker::INSUFFICIENT_DATA:
        {
            cout << ">>>>> Data missing from tree.";
            break;
        }

        case BinaryTreeChecker::REMAINING_DATA:
        {
            cout << ">>>>> Data remaining in tree.";
            break;
        }
    }
}
