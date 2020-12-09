#include "drama.h"

//---------------------------- operator<< -----------------------------------
// Overloaded operator<< to output Movie info.
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
ostream& operator<<(ostream& outputStream, Drama& drama) {
	outputStream << drama.getFormat() << ", " << drama.getCurrentStock() << ", "
		<< drama.getDirector() << ", " << drama.getTitle() << ", "
		<< drama.getYearReleased();
	return outputStream;
}

//---------------------------- Constructor ----------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Drama::Drama() {

}

//---------------------------- Constructor ----------------------------------
// Constructor taking in 3 arguments
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Drama::Drama(string direc, string tit, int yearR) {
	director = direc;
	title = tit;
	year = yearR;
}

//---------------------------- getTitle -------------------------------------
// Returns the title
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
string Drama::getTitle() const {
	return this->title;
}

//---------------------------- display --------------------------------------
// Displays Comedy movie info
// Preconditions: operator<<
// Postconditions: NONE
// --------------------------------------------------------------------------
void Drama::display() {
	cout << *this << endl;
}

//---------------------------- getYearReleased ------------------------------
// Returns the year
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Drama::getYearReleased() const {
	return this->year;
}

//---------------------------- setYearReleased ------------------------------
// Sets the year
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Drama::setYearReleased(int year) {
	this->year = year;
}

//---------------------------- operator< ------------------------------------
// Overloaded operator< to compare Movie info
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::operator<(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false; // check to make sure it is a drama
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	if (this->director.compare(otherDrama->getDirector()) != 0) {
		return this->director.compare(otherDrama->getDirector()) < 0;
		if (this->title.compare(otherDrama->getTitle()) != 0) {
			return this->title.compare(otherDrama->getTitle()) < 0;
		}
	}
	return false;
}

//---------------------------- operator> ------------------------------------
// Overloaded operator> to compare Movie info
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::operator>(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false;
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	if (this->director.compare(otherDrama->getDirector()) != 0) {
		return this->director.compare(otherDrama->getDirector()) > 0;
		if (this->title.compare(otherDrama->getTitle()) != 0) {
			return this->title.compare(otherDrama->getTitle()) > 0;
		}
	}
	return false;
}

//---------------------------- operator== -----------------------------------
// Overloaded operator== to compare Movie info
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::operator==(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false;
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	return (this->getDirector().compare(otherDrama->getDirector()) == 0 &&
		this->getTitle().compare(otherDrama->getTitle()) == 0);
}

//---------------------------- operator!= -----------------------------------
// Overloaded operator!= to compare Movie info.
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::operator!=(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false;
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	return !(*this == *otherDrama);
}

//---------------------------- isClassic ------------------------------------
// Checks to see if movie genre is classic
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::isClassic() const {
    return false;
}

//---------------------------- isDrama --------------------------------------
// Checks to see if movie genre is drama
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::isDrama() const {
    return true;
}

//---------------------------- isComedy -------------------------------------
// Checks to see if movie genre is comedy
// Preconditions: Movie& 
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Drama::isComedy() const {
    return false;
}