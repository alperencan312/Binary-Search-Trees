/*
 * Title: Trees
 * Author: Alperen CAN
 * ID: 21601740
 * Section: 1
 * Assignment: 2
*/
#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#define NULL 0
#include "BinaryNode.h"

class BinarySearchTree {
private:
    BinaryNode *root;
    BinaryNode *retrieveItem(BinaryNode *treePtr, int searchKey);
    bool insertItem(BinaryNode *&parent, const int newEntry);
    bool deleteItem(BinaryNode * &treePtr, int searchKey);
    void deleteNodeItem(BinaryNode * &treePtr);
    void deleteNextInorderItem(BinaryNode *&treePtr, int &treeItem);
    int countItems(BinaryNode *treePtr, const int min, const int max);
    int calculateHeight(BinaryNode *treePtr);
    BinaryNode *retrieveLeftmost(BinaryNode *treePtr);
    void inorderTraverse(BinaryNode *treePtr);
    int findSmallerCount(BinaryNode *treePtr, int searchEntry, bool &found);
    int getDepthWidth(BinaryNode *treePtr, int depth);
    void findInorderSuccessor(BinaryNode *treePtr, int searchValue, bool &found, int &successor);

public:
    //constructor
    BinarySearchTree();

    //destructor
    ~BinarySearchTree();

    //methods
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(int newEntry);
    bool remove(int anEntry);
    bool contains(int anEntry);
    void inorderTraverse();
    int getWidth();
    int count(int a, int b);
    int select(int anEntry);
    int successor(int anEntry);
};

#endif
