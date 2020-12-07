#pragma once
#ifndef MOVIEINVENTORY_RETURN_H
#define MOVIEINVENTORY_RETURN_H
#include "movie.h"
#include "customer.h"

class Return : public Transaction {
public:
	Return();
	Return(const Return&);
	~Return();
	bool returnMovie(string, Movie*, Customer*);
	string display() const;
	virtual Transaction* create();
};
#endif