/*
Cindy Acevedo
CSS 343 
Assignment 4
*/

#include "bintree.h"

//default constructor 
BinTree::BinTree() : root(NULL) {}



//copy constructor
BinTree::BinTree(const BinTree& rightSide) {}


//destructor
BinTree::~BinTree() 
{
	if (root != NULL)
		makeEmpty();
}


//insert
// Inserts the given/taken movie to the tree. No duplicate allowed.
// Avoid duplicates and create a bst.
template<typename T>
bool BinTree<T>::insert(T* insertMovie, const int copiesIn)
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
			//no dublicate allowed
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
template<typename T>
void BinTree<T>::destroyTree(const T& tree)
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
template<typename T>
bool BinTree<T>::retrieve(const T& dataItem, T*& dataFound) const
{
	retrieveHelper(root, dataItem, dataFound);

	if (dataFound != NULL)
		return true;
	else
		return false;
} 


// retrieveHelper
// A helper method for retrieve. It recursively finds the provided 
// object in this tree. Returns NULL if the item is not found.
template<typename T>	
void BinTree<T>::retrieveHelper(Node* curPtr, const Inventory& dataItem,Inventory*& dataFound) const
{
	//iff current point is null and data is null
	if (curPtr == NULL) 
		dataFound = NULL;

	//if found, then assign it 
	else if (dataItem == *curPtr->movie)
		dataFound = curPtr->movie;

	//otherwise check recursivly every child
	else if (dataItem < *curPtr->movie)
		retrieveHelper(curPtr->left, dataItem, dataFound);

	else
		retrieveHelper(curPtr->right, dataItem, dataFound);
}


//inorderDisplay
// A helper method that recursively prints the tree in-order traversal	
 
void BinTree::inorderDisplay(Node* current) const
{
	//if at the root, then show root
	if (current == root)
	{
		current->movie->displayHeader();
	}

	//if not null, go ascending order(in order) recursively
	if (current != NULL) 
	{
		inorderDisplay(current->left);

		cout << right << setw(2) << current->movie->getAmountIn() << "  " <<
			left << setw(3) << current->movie->getAmountOut() << " ";
		current->movie->display();

		inorderDisplay(current->right);
	}
}


// getRoot
// Show the root.
 
BinTree::Node* BinTree::getRoot() const 
{
	return this->root;
}