#pragma once
#ifndef MOVIEINVENTORY_BORROW_H
#define MOVIEINVENTORY_BORROW_H
#include "movie.h"

class Borrow : public Transaction {
public:
	Borrow();
	~Borrow();
	bool borrowMovie(Movie movie);
	String displayBorrows();
	bool hasMovie();
private:
	char type;
};
#endif
