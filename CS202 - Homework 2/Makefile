hw2: analyze.o BinarySearchTree.o main.o
	g++ -o hw2 analyze.o BinarySearchTree.o main.o
main.o: main.cpp BinarySearchTree.h analyze.h
	g++ -c main.cpp
analyze.o: analyze.cpp BinarySearchTree.h analyze.h
	g++ -c analyze.cpp -std=c++11
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
	g++ -c BinarySearchTree.cpp 
clean:
	rm analyze.o BinarySearchTree.o main.o hw2