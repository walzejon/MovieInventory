#include "borrow.h"
#include "bintree.h"
#include "movie.h"

//default constructor
Borrow::Borrow() { transactionType = 'B'; }

//copy constructor
Borrow::Borrow(const Borrow& rightSide) {
	transactionID = rightSide.transactionID;
	transactionType = rightSide.transactionType;
	movieType = rightSide.movieType;
	hasBeenBorrowed = rightSide.hasBeenBorrowed;
}

//destructor
Borrow::~Borrow() { }

//getters and setters, transaction creation, display
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
//displays the transaction type and the type of movie
void Borrow::display() {
	cout << movieType << " " << transactionType << " " << endl;
}
//creates a new borrow transaction 
Transaction* Borrow::create() {
	return new Borrow();
}