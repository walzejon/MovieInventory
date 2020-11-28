#include "movie.h"

ostream& operator<<(ostream& outputStream, Movie& movie) {
	outputStream << movie.getFormat() << ", " << movie.getCurrentStock() << ", "
		<< movie.getTitle() << ", " << movie.getDirector();
	return outputStream;
}

Movie::Movie() {
	this->movieFormat = "";
	this->title = "";
	this->currentStock = 0;
	this->stockOwned = 0;
	this->director = "";
}

Movie::~Movie() {

}

string Movie::getFormat() {
	return this->movieFormat;
}

void Movie::setFormat(string movieFormat) {
	this->movieFormat = movieFormat;
}

int Movie::getCurrentStock() {
	return this->currentStock;
}

void Movie::setCurrentStock(int currentStock) {
	this->currentStock = currentStock;
}

int Movie::getStockOwned() {
	return this->stockOwned;
}

void Movie::setStockOwned(int stockOwned) {
	this->stockOwned = stockOwned;
}

string Movie::getTitle() {
	return this->title;
}

void Movie::setTitle(string title) {
	this->title = title;
}

string Movie::getDirector() {
	return this->director;
}

void Movie::setDirector(string director) {
	this->director = director;
}