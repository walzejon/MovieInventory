#pragma once
#ifndef MOVIEINVENTORY_RETURN_H
#define MOVIEINVENTORY_RETURN_H
#include "movie.h"

class Return : Transaction {
public:
	bool returnMovie(Movie movie);
	String displayReturned();
private:
	char type;
};
#endif