#include "movie.h"
//---------------------------- operator<< -----------------------------------
// Overloaded operator<< to output Movie info.
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
ostream& operator<<(ostream& outputStream, Movie& movie) {
	outputStream << movie.getFormat() << ", " << movie.getCurrentStock() << ", "
		<< movie.getStockOwned() << ", " << movie.getTitle() << ", " 
		<< movie.getDirector();
	return outputStream;
}

//------------------------------ Constructor --------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Movie::Movie() {
	this->movieFormat = "";
	this->currentStock = 0;
	this->stockOwned = 0;
	this->title = "";
	this->director = "";
	this->maxStock = 0;
}

//------------------------------ Constructor --------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Movie::Movie(string director, string title) {
	this->director = director;
	this->title = title;
}

//------------------------------ Constructor --------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Movie::Movie(string title, int year) {
	this->title = title;
	this->year = year;
}

//------------------------------ Destructor ---------------------------------
// Destructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Movie::~Movie() { }

//------------------------------ getFormat ----------------------------------
// Returns format of movie
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
string Movie::getFormat() {
	return this->movieFormat;
}

//------------------------------ display ------------------------------------
// virtual display function
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::display() {

}

//------------------------------ setFormat ----------------------------------
// Sets format of movie
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setFormat(string movieFormat) {
	this->movieFormat = movieFormat;
}

//------------------------------ getYear ------------------------------------
// Returns year
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Movie::getYear() const {
	return this->year;
}

//------------------------------ setYear ------------------------------------
// Sets year
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setYear(int year) {
	this->year = year;
}

//------------------------------ getCurrentStock ----------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Movie::getCurrentStock() {
	return this->currentStock;
}

//------------------------------ setCurrentStock ----------------------------
// sets the current stock
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setCurrentStock(int currentStock) {
	this->currentStock = currentStock;
}

//------------------------------ getStockOwned ------------------------------
// Returns stock owned
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Movie::getStockOwned() {
	return this->stockOwned;
}

//------------------------------ getStockDifference -------------------------
// Returns stock difference
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Movie::getStockDifference() {
	return this->maxStock - this->currentStock;
}

//------------------------------ setStockOwned ------------------------------
// Sets stock owned
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setStockOwned(int stockOwned) {
	this->stockOwned = stockOwned;
}

//------------------------------ getTitle -----------------------------------
// Returns title
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
string Movie::getTitle() const {
	return this->title;
}

//------------------------------ setTitle -----------------------------------
// Sets title
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setTitle(string title) {
	this->title = title;
}

//------------------------------ getDirector --------------------------------
// Returns director
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
string Movie::getDirector() const {
	return this->director;
}

//------------------------------ setDirector --------------------------------
// Sets director
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setDirector(string director) {
	this->director = director;
}

//--------------------------------- getMA -----------------------------------
// Returns major actor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
string Movie::getMA() {
	return this->MA;
}

//--------------------------------- setMA -----------------------------------
// Sets major actor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setMA(string ma) {
	this->MA = ma;
}

//------------------------------ getMaxStock --------------------------------
// Returns max stock
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Movie::getMaxStock() {
	return this->maxStock;
}

//------------------------------ setMaxStock --------------------------------
// Sets max stock
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Movie::setMaxStock(int maxStock) {
	this->maxStock = maxStock;
}