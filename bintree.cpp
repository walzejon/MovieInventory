/*
Cindy Acevedo
CSS 343 
Assignment 4
*/

#include "bintree.h"

//default constructor 
BinTree::BinTree() : root(NULL) {}



//copy constructor
BinTree::BinTree(const BinTree& rightSide) {
	this->root = nullptr;
	*this = rightSide;
}


//destructor
BinTree::~BinTree() 
{
	if (root != NULL)
		makeEmpty();
}


//insert
// Inserts the given/taken movie to the tree. No duplicate allowed.
// Avoid duplicates and create a bst.
bool BinTree::insert(Movie* insertMovie, int copiesIn)
{
	Node* ptr = new Node();
	ptr->movie = insertMovie; 
	ptr->movie->setMaxStock(copiesIn);

	//insertMovie = NULL;
	ptr->left = ptr->right = NULL;

	if (isEmpty())
	{
		root = ptr; //Empty, set as root
	}

	else
	{
		Node* current = root;
		bool inserted = false;

		while (!inserted)
		{
			//no duplicate allowed
			if (*ptr->movie == *current->movie)
			{
				delete ptr;
				ptr = NULL;
				return false;
			}

			//if less than current movie, insert left
			else if (*ptr->movie < *current->movie)
			{
				if (current->left == NULL)
				{
					current->left = ptr;
					inserted = true;
				}
				else
				{
					current = current->left;
				}
					
			}

			//otherwise insert right
			else
			{
				if (current->right == NULL)
				{
					current->right = ptr;
					inserted = true;
				}
				else
				{
					current = current->right;
				}					
			}
		}
	}
	return true;
} 


//isEmpty

bool BinTree::isEmpty() const
{
	return (root == NULL);
} 


//makeEmpty
 
void BinTree::makeEmpty()
{
	destroyTree(root);
} 


//destroyTree
void BinTree::destroyTree(Node*& tree)
{
	if (tree != NULL)
	{
		destroyTree(tree->left); //destroy left
		destroyTree(tree->right); //destroy right
		delete tree->movie; //delete NodeData
		tree->movie = NULL;
		delete tree; //Delete Node
		tree = NULL;
	}
} 


// retrieve 
// Finds the provided object in this tree. Returns NULL if the item
bool BinTree::retrieve(const Movie* dataItem, Movie*& dataFound) const
{
	retrieveHelper(root, dataItem, dataFound);
	if (dataFound != NULL) {
        return true;
    }
	else return false;
}
// retrieveHelper
// A helper method for retrieve. It recursively finds the provided 
// object in this tree. Returns NULL if the item is not found.	
void BinTree::retrieveHelper(Node* curPtr, const Movie* dataItem, Movie*& dataFound) const
{
    //cout<<"dataItem: " << dataItem->getTitle() << " curPTR TIt:" << curPtr->movie->getTitle() << " "  <<endl;
	if (curPtr == NULL) {
        dataFound = NULL;
    }
	else if (*dataItem == *(curPtr->movie)) {
        dataFound = curPtr->movie;
        return;
    }
	else if (*dataItem < *(curPtr->movie)) retrieveHelper(curPtr->left, dataItem, dataFound);
	else retrieveHelper(curPtr->right, dataItem, dataFound);
}

//display pre-order

void BinTree::preorderDisplay() const
{
    preorderDisplayHelper(root);
}

//helper function for pre-order display

void BinTree::preorderDisplayHelper(Node* current) const
{
	if (current != NULL)
	{
        preorderDisplayHelper(current->left);
        current->movie->display();
		preorderDisplayHelper(current->right);
	}
}


// Displays a binary tree as though you are viewing it from the side;
// hard-coded displaying to standard output.

// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
    sideways(root, 0);
}


// Helper method for displaySideways

// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
    if (current != nullptr) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }
        cout << *current->movie << endl;      // displays object info
        sideways(current->left, level);
    }
}

//gets the root 
BinTree::Node *BinTree::getRoot() {
    return root;
}