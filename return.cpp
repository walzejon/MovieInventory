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

string Return::display() const {
	cout << movieType << " " << transactionType << " " << endl;
}

Transaction* Return::create() {
	return new Return();
}