/*
 * Title: Trees
 * Author: Alperen CAN
 * ID: 21601740
 * Section: 1
 * Assignment: 2
*/
#ifndef BinaryNode_h
#define BinaryNode_h
#define NULL 0

class BinaryNode {
private:
	BinaryNode() { }
	BinaryNode(const int value, BinaryNode *left = NULL, BinaryNode *right = NULL, BinaryNode *parent = NULL, int size = 0)
            : dataValue(value), leftChildPtr(left), rightChildPtr(right), parentPtr(parent), subSize(size){ }


    int dataValue;
	BinaryNode *leftChildPtr;
	BinaryNode *rightChildPtr;
    BinaryNode *parentPtr;
    int subSize;

	friend class BinarySearchTree;
};
#endif
