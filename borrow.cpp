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
	}
	else {
		cout << "Error: No available stock" << endl;
		return false;
	}
}

string Borrow::display() const {
	cout << movieType << " " << transactionType << " " << endl;
}

Transaction* Borrow::create() {
	return new Borrow();
}