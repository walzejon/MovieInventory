#include "return.h"

Return::Return() { transactionType = 'R'; }

Return::Return(const Return& rightSide) {
	transactionID = rightSide.transactionID;
	transactionType = rightSide.transactionType;
	movieType = rightSide.movieType;
	hasBeenBorrowed = rightSide.hasBeenBorrowed;
}

Return::~Return() { }

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

void Return::display() {
	cout << movieType << " " << transactionType << " " << endl;
}

Transaction* Return::create() {
	return new Return();
}