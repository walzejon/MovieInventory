#include "borrow.h"
#include "bintree.h"

Borrow::Borrow() { transactionType = 'B'; }

Borrow::Borrow(const Borrow& rightSide) {
	transactionID = rightSide.transactionID;
	transactionType = rightSide.transactionType;
	movieType = rightSide.movieType;
	hasBeenBorrowed = rightSide.hasBeenBorrowed;
	
}

Borrow::~Borrow() { }

bool Borrow::borrowMovie(string media, Movie movie, Customer* cust) {
	if (hasMovie(movie) == true) {
		movie.setCurrentStock(movie.getCurrentStock() - 1);
		movie.setStockOwned(movie.getStockOwned() + 1);
		movieType = media;
		hasBeenBorrowed = true;
		return true;
	}
	else {
		cout << "Movie not available";
		return false;
	}
}

string Borrow::display() const {
	cout << movieType << " " << transactionType << " " << endl;
}

bool Borrow::hasMovie(Movie movie) {
	BinTree<Movie>* ch = new BinTree<Movie>();
	if (ch->isEmpty()) return false;
	else {

	}
}

Transaction* Borrow::create() {
	return new Borrow();
}