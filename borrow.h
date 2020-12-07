#pragma once
#ifndef MOVIEINVENTORY_BORROW_H
#define MOVIEINVENTORY_BORROW_H
#include "movie.h"
#include "transaction.h"
#include "customer.h"
#include <iostream>

class Borrow : public Transaction {
public:
	Borrow();
	Borrow(const Borrow&);
	~Borrow();
	bool borrowMovie(string, Movie, Customer*);
	string display() const;
	virtual Transaction* create();
};
#endif
