/*
Cindy Acevedo
CSS 343 
Assignment 4
*/

#ifndef BINTREE_H
#define BINTREE_H
#include "movie.h" //make sure to name it movie

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
	bool insert(Inventory* insertMovie, const int copiesIn);
	//check if empty
	bool isEmpty() const;

	void makeEmpty(); 
	//retrieve movie
	bool retrieve(const Inventory& dataItem, Inventory*& dataFound) const;
	void retrieveHelper(Node* curPtr,
	const Inventory& dataItem, Inventory*& dataFound) const;
	//displays in order
	void inorderDisplay(Node* current) const;
	//gets the root
	//Node* getRoot() const;
private:
	
	struct Node
	{
		Inventory* movie; 
		Node* left, * right; 
	};

	Node* root; 

	//helper method to destroy the tree
	void destroyTree(Node*& tree);
};
#endif