/*
 * Title: Trees
 * Author: Alperen CAN
 * ID: 21601740
 * Section: 1
 * Assignment: 2
*/
#include "BinarySearchTree.h"
#include <stdio.h>

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    root = NULL;
}
BinaryNode *BinarySearchTree::retrieveItem(BinaryNode *treePtr, int searchKey) {
        if (treePtr == NULL)
			return NULL;
		else if (searchKey == treePtr -> dataValue)
			return treePtr;
		else if (searchKey < treePtr -> dataValue)
			return retrieveItem(treePtr->leftChildPtr, searchKey);
		else
			return retrieveItem(treePtr->rightChildPtr, searchKey);
}

bool BinarySearchTree::insertItem(BinaryNode *&parent, const int newEntry){
    if (parent == NULL) {
        parent = new BinaryNode(newEntry);
        return true;
    }
    else if (newEntry < parent -> dataValue){
        parent -> subSize += 1;
        if(parent ->leftChildPtr == NULL){
            BinaryNode *newNode = new BinaryNode(newEntry);
            parent -> leftChildPtr = newNode;
            newNode -> parentPtr = parent;
            return newNode;
        }
        return insertItem(parent -> leftChildPtr, newEntry);
    }
    else{
        parent -> subSize += 1;
        if(parent -> rightChildPtr == NULL){
            BinaryNode *newNode = new BinaryNode(newEntry);
            parent -> rightChildPtr = newNode;
            newNode -> parentPtr = parent;
            return newNode;
        }
        return insertItem(parent -> rightChildPtr, newEntry);
    }
}

bool BinarySearchTree::deleteItem(BinaryNode *&treePtr, int searchKey){
    if (treePtr == NULL) // Empty tree
		return false;

	// Position of deletion found
	else if (searchKey == treePtr -> dataValue){
		deleteNodeItem(treePtr);
        return true;
    }
	// Else search for the deletion position
	else if (searchKey < treePtr-> dataValue){
        treePtr -> subSize -= 1;
		return deleteItem(treePtr -> leftChildPtr, searchKey);
    }
    else{
        treePtr -> subSize -= 1;
		return deleteItem(treePtr -> rightChildPtr, searchKey);
    }
}

void BinarySearchTree::deleteNodeItem(BinaryNode *&treePtr) {
	BinaryNode *delPtr;
	int replacementItem;
	// (1)  Test for a leaf

	if ( (treePtr -> leftChildPtr == NULL) && (treePtr -> rightChildPtr == NULL) ) {
        treePtr -> parentPtr = NULL;
		delete treePtr;
		treePtr = NULL;
    }

	// (2)  Test for no left child
	else if (treePtr -> leftChildPtr == NULL){
		delPtr = treePtr;
		treePtr = treePtr -> rightChildPtr;
		delPtr -> rightChildPtr = NULL;
        delPtr -> parentPtr = NULL;
		delete delPtr;
	}

    // (3)  Test for no right child
	else if (treePtr -> rightChildPtr == NULL) {
		delPtr = treePtr;
		treePtr = treePtr -> leftChildPtr;
		delPtr -> leftChildPtr = NULL;
        delPtr -> parentPtr = NULL;
		delete delPtr;
	}

	// (4)  There are two children:
	//      Retrieve and delete the inorder successor
	else {
        treePtr -> subSize -= 1;
		deleteNextInorderItem(treePtr -> rightChildPtr, replacementItem);
		treePtr -> dataValue = replacementItem;
	}

}

void BinarySearchTree::deleteNextInorderItem(BinaryNode *&treePtr, int &treeItem) {
        if (treePtr -> leftChildPtr == NULL){
            treeItem = treePtr -> dataValue;
			BinaryNode *delPtr = treePtr;
			treePtr = treePtr -> rightChildPtr;
			delPtr -> rightChildPtr = NULL; // defense
            delPtr -> parentPtr = NULL;
			delete delPtr;
        }
		else{
            treePtr -> subSize -= 1;
			deleteNextInorderItem(treePtr -> leftChildPtr, treeItem);
        }
}

bool BinarySearchTree::isEmpty(){
    if(root == NULL)
        return true;

    return false;
}

int BinarySearchTree::calculateHeight(BinaryNode *treePtr){
    if(treePtr == NULL){
        return 0;
    }
    int leftSubtreeHeight = calculateHeight(treePtr -> leftChildPtr);
    int rightSubtreeHeight = calculateHeight(treePtr -> rightChildPtr);
    if(leftSubtreeHeight >= rightSubtreeHeight)
        return leftSubtreeHeight + 1;
    else
        return rightSubtreeHeight + 1;
}

int BinarySearchTree::getHeight(){
    return calculateHeight(root);
}

int BinarySearchTree::getNumberOfNodes(){
    if( root == NULL )
        return 0;
    else
        return root -> subSize + 1;
}

bool BinarySearchTree::add(int newEntry){
    if(newEntry > 0 && !contains(newEntry))
        return insertItem(root, newEntry);

    return false;
}

bool BinarySearchTree::remove(int anEntry){
    if(contains(anEntry)){
        return deleteItem(root, anEntry);
    }
    return false;
}

bool BinarySearchTree::contains(int anEntry){
    return retrieveItem(root, anEntry) != NULL;
}

void printItem(int item){
    printf(" -%d- ", item);
}

void BinarySearchTree::inorderTraverse(BinaryNode *treePtr) {
	if (treePtr != NULL) {
		inorderTraverse(treePtr -> leftChildPtr);
        printItem(treePtr -> dataValue);
		inorderTraverse(treePtr->rightChildPtr);
	}
}

void BinarySearchTree::inorderTraverse() {
    printf("Tree elements: \n[");
    inorderTraverse(root);
    printf("]\n");
}

int BinarySearchTree::getWidth(){
    int maxWidth = 0;
    int maxHeight = getHeight();
    for (int depth = 1; depth <= maxHeight; depth++) {
        int width = getDepthWidth(root, depth);
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}

int BinarySearchTree::getDepthWidth(BinaryNode *treePtr, int depth){
    if (treePtr == NULL)
        return 0;

    else if (depth == 1)
        return 1;

    else
        return getDepthWidth(treePtr -> leftChildPtr, depth - 1) + getDepthWidth(treePtr -> rightChildPtr, depth - 1);
}


int BinarySearchTree::count(int a, int b){
    if(root == NULL)
        return 0;
    else
        return countItems(root, a, b);
}

int BinarySearchTree::countItems(BinaryNode *treePtr, const int min, const int max) {
		if (treePtr == NULL) {
            return 0;
		}
        if(treePtr -> dataValue < min){
            return countItems(treePtr -> rightChildPtr, min, max);
        }
        else if(treePtr -> dataValue > max){
            return countItems(treePtr -> leftChildPtr, min, max);
        }
        else{
            int count1 = countItems(treePtr -> leftChildPtr, min, max);
            int count2 = countItems(treePtr -> rightChildPtr, min, max);
            return count1 + count2 + 1 ;
        }
}

BinaryNode *BinarySearchTree::retrieveLeftmost(BinaryNode *treePtr) {
        if (treePtr -> leftChildPtr == NULL){
			return treePtr;
        }
		else{
			return retrieveLeftmost(treePtr->leftChildPtr);
        }
}

int BinarySearchTree::select(int anEntry){
    bool found = false;
    int index = findSmallerCount(root, anEntry, found);
    if(found)
        return index;
    else
        return -1;
}

int BinarySearchTree::findSmallerCount(BinaryNode *treePtr, int searchEntry, bool &found){
    int count = 0;
    if(treePtr == NULL){
        return count;
    }
    if(treePtr -> dataValue < searchEntry){
        if(treePtr -> leftChildPtr != NULL)
            count = treePtr -> leftChildPtr -> subSize + 1;
        return  count + findSmallerCount(treePtr -> rightChildPtr, searchEntry, found) + 1;
    }
    else if(treePtr -> dataValue > searchEntry){
        return findSmallerCount(treePtr -> leftChildPtr, searchEntry, found);
    }
    else{
        found = true;
        if(treePtr -> leftChildPtr != NULL)
            return treePtr -> leftChildPtr -> subSize + 1;
        else
            return count;
    }
}


int BinarySearchTree::successor(int anEntry){
    BinaryNode *foundNode = retrieveItem(root, anEntry);
    if(foundNode == NULL){
        return -1;
    }
    if(foundNode -> rightChildPtr != NULL){
        BinaryNode *successor = retrieveLeftmost(foundNode -> rightChildPtr);
        return successor -> dataValue;
    }
    bool found = false;
    int successor = -2;
    findInorderSuccessor(root, anEntry, found, successor);
    if(!found)
        return -1;
    else
        return successor;
}


void BinarySearchTree::findInorderSuccessor(BinaryNode *treePtr, int searchValue, bool &found, int &successor){
    if(treePtr == NULL){
         return;
    }else{
        if(searchValue < treePtr -> dataValue){
            successor = treePtr -> dataValue;
            findInorderSuccessor(treePtr -> leftChildPtr, searchValue, found, successor);
        }else if(searchValue > treePtr -> dataValue){
            findInorderSuccessor(treePtr -> rightChildPtr, searchValue, found, successor);
        }else{
            found = true;
            return;
        }
    }
}
