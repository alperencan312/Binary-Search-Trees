#include "BinarySearchTree.h"
#include "analyze.h"
#include <string>
#include "iostream"
#include <ctime>
#include <cstdlib>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
using namespace std;

const int ARRAY_SIZE = 10000;
void createRandomArray(int *&arr, int size){
    arr = new int[size];
    srand((unsigned) time(0));
    for(int i = 0; i < size; i++){
       arr[i] = rand();
    }
}

void createBST(BinarySearchTree &bst, int *arr, int size){
    bst = BinarySearchTree();
    printf("Random BST size vs. height (Insertion)\n");
    printf("-----------------------------------------\n");
    for(int i = 0; i < size; i++){
       if(i % 100 == 0){
           printf("%d\t\t%d\n", bst.getNumberOfNodes(), bst.getHeight());
       }
       bst.add(arr[i]);
    }
    printf("%d\t\t%d\n", bst.getNumberOfNodes(), bst.getHeight());
}

void deleteBST(BinarySearchTree bst, int *arr, int size){
    printf("Random BST size vs. height (Deletion)\n");
    printf("-----------------------------------------\n");
    for(int i = 0; i < size; i++){
       if(i % 100 == 0){
           printf("%d\t\t%d\n", bst.getNumberOfNodes(), bst.getHeight());
       }
       bst.remove(arr[i]);
    }
    printf("%d\t\t%d\n", bst.getNumberOfNodes(), bst.getHeight());
}

void shuffleArray(int *arr, int size) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(arr, &arr[size - 1], std::default_random_engine(seed));
}

void printArray(int *arr){
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d - ", arr[i]);
    }
    printf("\n\n");
}

void analyzeBST(){
    int *randomArray;
    BinarySearchTree binarySearchTree = BinarySearchTree();
    createRandomArray(randomArray, ARRAY_SIZE);
    createBST(binarySearchTree, randomArray, ARRAY_SIZE);
    shuffleArray(randomArray, ARRAY_SIZE);
    deleteBST(binarySearchTree, randomArray, ARRAY_SIZE);
    delete randomArray;
}

