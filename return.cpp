#include "return.h"
//------------------------------ Constructor --------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Return::Return() { transactionType = 'R'; }

//------------------------------ Copy Constructor ---------------------------
// Copy constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Return::Return(const Return& rightSide) {
	transactionID = rightSide.transactionID;
	transactionType = rightSide.transactionType;
	movieType = rightSide.movieType;
	hasBeenBorrowed = rightSide.hasBeenBorrowed;
}

//------------------------------ Destructor --------------------------------
// Destructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Return::~Return() { }

//------------------------------ returnMovie --------------------------------
// Returns the movie
// Preconditions: Have movie to return
// Postconditions: Movie returned
// --------------------------------------------------------------------------
bool Return::returnMovie(string media, Movie* movie, Customer* cust) {
	if (cust->checkMovie(movie) == true) {
		movie->setCurrentStock(movie->getCurrentStock() + 1);
		movie->setStockOwned(movie->getStockOwned() - 1);
		Transaction* trans = new Transaction();
		trans->setTransactionType('R');
		cust->addTransaction(*trans);
		cust->removeMovie(movie);
		mediaType = media;
		hasBeenBorrowed = false;
		return true;
	}
	else {
		cout << "You cannot return a movie that you don't have." << endl;
		return false;
	}
}

//------------------------------ display ------------------------------------
// Display function
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Return::display() {
	cout << movieType << " " << transactionType << " " << endl;
}

//------------------------------ create -------------------------------------
// Create new instance of return
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Transaction* Return::create() {
	return new Return();
}