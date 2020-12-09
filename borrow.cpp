#include "borrow.h"
#include "bintree.h"
#include "movie.h"

//------------------------------ Constructor --------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Borrow::Borrow() { transactionType = 'B'; }

//------------------------------ Copy Constructor ---------------------------
// Copy constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Borrow::Borrow(const Borrow& rightSide) {
	transactionID = rightSide.transactionID;
	transactionType = rightSide.transactionType;
	movieType = rightSide.movieType;
	hasBeenBorrowed = rightSide.hasBeenBorrowed;
}

//------------------------------ Destructor ---------------------------------
// Destructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Borrow::~Borrow() { }

//------------------------------ borrowMovie --------------------------------
// Borrows the movie
// Preconditions: Movie exists in inventory
// Postconditions: Customer now has movie
// --------------------------------------------------------------------------
bool Borrow::borrowMovie(string media, Movie* movie, Customer* cust) {
	if (movie->getCurrentStock() > 0) {
		movie->setCurrentStock(movie->getCurrentStock() - 1);
		movie->setStockOwned(movie->getStockOwned() + 1);
		Transaction* trans = new Transaction();
		trans->setTransactionType('B');
		cust->addTransaction(*trans);
		cust->addMovie(movie);
		movieType = media;
		hasBeenBorrowed = true;
		return true;
	} //error message displays if movie not available 
	else {
		cout << "Error: No available stock" << endl;
		return false;
	}
}

//------------------------------ display ====--------------------------------
// Display function
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Borrow::display() {
	cout << movieType << " " << transactionType << " " << endl;
}

//------------------------------ create -------------------------------------
// Creates new instance of Borrow
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Transaction* Borrow::create() {
	return new Borrow();
}