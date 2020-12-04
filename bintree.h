/*
Cindy Acevedo
CSS 343 
Assignment 4
*/

#ifndef BINTREE_H
#define BINTREE_H
#include "movie.h" //make sure to name it movie

template <typename T>

class BinTree
{
	
	struct Node;

public:
    //constructor
	BinTree();
	// copy constructor
	BinTree(const BinTree&); 
	//destructor
	~BinTree();

	//insert movie 
	bool insert(T* insertMovie, const int copiesIn);
	//check if empty
	bool isEmpty() const;

	void makeEmpty(); 
	//retrieve movie
	bool retrieve(const T&, T*&) const;
	void retrieveHelper(Node* curPtr,
	const T& dataItem, T*& dataFound) const;
	//displays in order
	void inorderDisplay(Node* current) const;
	//gets the root
	Node* getRoot() const;
private:
	
	struct Node
	{
		//Movie* movie;
		Node* left, * right; 
	};

	Node* root; 

	//helper method to destroy the tree
	void destroyTree(const T&);
};
#endif