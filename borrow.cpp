#include "borrow.h"
#include "bintree.h"
#include "movie.h"

Borrow::Borrow() { transactionType = 'B'; }

Borrow::Borrow(const Borrow& rightSide) {
	transactionID = rightSide.transactionID;
	transactionType = rightSide.transactionType;
	movieType = rightSide.movieType;
	hasBeenBorrowed = rightSide.hasBeenBorrowed;
}

Borrow::~Borrow() { }

bool Borrow::borrowMovie(string media, Movie* movie, Customer* cust) {
	movie->setCurrentStock(movie->getCurrentStock() - 1);
	movie->setStockOwned(movie->getStockOwned() + 1);
	Transaction* trans = new Transaction();
	trans->setTransactionType('B');
	cust->addTransaction(*trans);
	movieType = media;
	hasBeenBorrowed = true;
	return true;
}

string Borrow::display() const {
	cout << movieType << " " << transactionType << " " << endl;
}

Transaction* Borrow::create() {
	return new Borrow();
}