#include "drama.h"
//output
ostream& operator<<(ostream& outputStream, Drama& drama) {
	outputStream << drama.getFormat() << ", " << drama.getCurrentStock() << ", "
		<< drama.getDirector() << ", " << drama.getTitle() << ", "
		<< drama.getYearReleased();
	return outputStream;
}
//constructor
Drama::Drama() {
	this->director = "";
	this->title = "";
	this->year = 0;
}
//copy constructor
Drama::Drama(string direc, string tit, int yearR) {
	director = direc;
	title = tit;
	year = yearR;
}
//getters 
string Drama::getTitle() const {
	return this->title;
}
//display
void Drama::display() {
	cout << *this << endl;
}
//getters and setters
int Drama::getYearReleased() const {
	return this->year;
}

void Drama::setYearReleased(int year) {
	this->year = year;
}

//comsparison operators
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

bool Drama::operator==(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false;
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	return (this->getDirector().compare(otherDrama->getDirector()) == 0 &&
		this->getTitle().compare(otherDrama->getTitle()) == 0);
}

bool Drama::operator!=(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false;
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	return !(*this == *otherDrama);
}

//returns true if it's drama or false if it's not

bool Drama::isClassic() const {
    return false;
}

bool Drama::isDrama() const {
    return true;
}

bool Drama::isComedy() const {
    return false;
}