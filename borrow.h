#pragma once
#ifndef MOVIEINVENTORY_BORROW_H
#define MOVIEINVENTORY_BORROW_H
#include "movie.h"
#include "transaction.h"
#include "customer.h"
#include <iostream>

class Borrow : public Transaction {
public:
	//constructor
	Borrow();
	//copy constructor
	Borrow(const Borrow&);
	//destructor
	~Borrow();

	bool borrowMovie(string, Movie*, Customer*);
	bool borrowDrama(string, string);
	//displays borrowed transactions
	void display();
	//creates borrow transactions
	virtual Transaction* create();
};
#endif
