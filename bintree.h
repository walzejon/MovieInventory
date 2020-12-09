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
	bool insert(Movie* insertMovie, int copiesIn);
	//check if empty
	bool isEmpty() const;

	void makeEmpty(); 
	//retrieve movie
	bool retrieve(const Movie*, Movie*) const; // look at later
	//displays order
	void preorderDisplay() const;

	//gets the root
	BinTree::Node* getRoot();
	void displaySideways() const;

private:
	void retrieveHelper(Node* curPtr, const Movie* dataItem, Movie* dataFound) const;
	//helper method to destroy the tree
	void destroyTree(Node*&);
	void preorderDisplayHelper(Node* current) const;
	void sideways(Node* current, int level) const;
};
#endif