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
	struct Node
	{
		Movie* movie;
		Node* left, * right;
	};

	Node* root;
public:
    //constructor
	BinTree();
	// copy constructor
	BinTree(const BinTree&); 
	//destructor
	~BinTree();

	//insert movie 
	bool insert(Movie* insertMovie, const int copiesIn);
	//check if empty
	bool isEmpty() const;

	void makeEmpty(); 
	//retrieve movie
	bool retrieve(Movie&, Movie*&) const; // look at later
	void retrieveHelper(Node* curPtr, Movie& dataItem, Movie*& dataFound) const;
	//displays order
	void preorderDisplay(Node* current) const;
	//gets the root
	BinTree::Node* getRoot();
	void displaySideways() const;
private:
	//helper method to destroy the tree
	void destroyTree(Node*&);
	void sideways(Node* current, int level) const;
};
#endif