#include "movie.h"

ostream& operator<<(ostream& outputStream, Movie& movie) {
	outputStream << movie.getFormat() << ", " << movie.getCurrentStock() << ", "
		<< movie.getStockOwned() << ", " << movie.getTitle() << ", " 
		<< movie.getDirector();
	return outputStream;
}

Movie::Movie() {
	this->movieFormat = "";
	this->currentStock = 0;
	this->stockOwned = 0;
	this->title = "";
	this->director = "";
	this->maxStock = 0;
}

Movie::Movie(string director, string title) {
	this->director = director;
	this->title = title;
}

Movie::Movie(string title, int year) {
	this->title = title;
	this->year = year;
}

Movie::~Movie() { }

string Movie::getFormat() {
	return this->movieFormat;
}

void Movie::display() {

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

int Movie::getStockDifference() {
	return this->maxStock - this->currentStock;
}

void Movie::setStockOwned(int stockOwned) {
	this->stockOwned = stockOwned;
}

string Movie::getTitle() const {
	return this->title;
}

void Movie::setTitle(string title) {
	this->title = title;
}

string Movie::getDirector() const {
	return this->director;
}

void Movie::setDirector(string director) {
	this->director = director;
}

int Movie::getMaxStock() {
	return this->maxStock;
}

void Movie::setMaxStock(int maxStock) {
	this->maxStock = maxStock;
}