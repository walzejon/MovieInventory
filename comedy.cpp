#include "comedy.h"

//---------------------------- operator<< -----------------------------------
// Overloaded operator<< to output Movie info.
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
ostream& operator<<(ostream& outputStream, Comedy& com) {
	outputStream << com.getFormat() << ", " << com.getCurrentStock() << ", "
		<< com.getDirector() << ", " << com.getTitle() << ", " 
		<< com.getYearReleased();
	return outputStream;
}

//---------------------------- Constructor ----------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Comedy::Comedy() {
	this->director = "";
	this->title = "";
	this->year = 0;
}

//---------------------------- Constructor ----------------------------------
// Constructor taking in 3 arguments
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Comedy::Comedy(string direc, string tit, int yearR) {
	director = direc;
	title = tit;
	year = yearR;
}

//---------------------------- display --------------------------------------
// Displays Comedy movie info
// Preconditions: operator<<
// Postconditions: NONE
// --------------------------------------------------------------------------
void Comedy::display() {
	cout << *this << endl;
}

//---------------------------- getYearReleased ------------------------------
// Returns the year
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Comedy::getYearReleased() const {
	return this->year;
}

//---------------------------- setYearReleased ------------------------------
// Sets the year
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Comedy::setYearReleased(int year) {
	this->year = year;
}

//---------------------------- operator< ------------------------------------
// Overloaded operator< to compare Movie info
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::operator<(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	if (this->title.compare(otherComedy->getTitle()) != 0) {
		return this->title.compare(otherComedy->getTitle()) < 0;
		if (this->year == (otherComedy->getYearReleased()) != 0) {
			return this->year == (otherComedy->getYearReleased()) < 0;
		}
	}
	return false;
}

//---------------------------- operator> ------------------------------------
// Overloaded operator> to compare Movie info
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::operator>(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	if (this->title.compare(otherComedy->getTitle()) != 0) {
		return this->title.compare(otherComedy->getTitle()) > 0;
		if (this->year == (otherComedy->getYearReleased()) != 0) {
			return this->year == (otherComedy->getYearReleased()) > 0;
		}
	}
	return false;
}

//---------------------------- operator== -----------------------------------
// Overloaded operator== to compare Movie info
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::operator==(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return (this->title.compare(otherComedy->getTitle()) == 0 && this->year == otherComedy->getYear());
}

//---------------------------- operator!= -----------------------------------
// Overloaded operator!= to compare Movie info.
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::operator!=(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return !(*this == *otherComedy);
}

//---------------------------- isClassic ------------------------------------
// Checks to see if movie genre is classic
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::isClassic() const {
    return false;
}

//---------------------------- isDrama --------------------------------------
// Checks to see if movie genre is drama
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::isDrama() const {
    return false;
}

//---------------------------- isComedy -------------------------------------
// Checks to see if movie genre is comedy
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Comedy::isComedy() const {
    return true;
}

