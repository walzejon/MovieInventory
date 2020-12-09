#include "comedy.h"
//displays comedy movies with their director, title, and year 
ostream& operator<<(ostream& outputStream, Comedy& com) {
	outputStream << com.getFormat() << ", " << com.getCurrentStock() << ", "
		<< com.getDirector() << ", " << com.getTitle() << ", " 
		<< com.getYearReleased();
	return outputStream;
}
//constructor
Comedy::Comedy() {
	this->director = "";
	this->title = "";
	this->year = 0;
}
//copy constructor
Comedy::Comedy(string direc, string tit, int yearR) {
	director = direc;
	title = tit;
	year = yearR;
}

//display
void Comedy::display() {
	cout << *this << endl;
}
//getter
int Comedy::getYearReleased() const {
	return this->year;
}
//setter
void Comedy::setYearReleased(int year) {
	this->year = year;
}

//comparison operators 

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

bool Comedy::operator==(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return (this->title.compare(otherComedy->getTitle()) == 0 && this->year == otherComedy->getYear());
}

bool Comedy::operator!=(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return !(*this == *otherComedy);
}

//returns true if it's this genre or false if it's not

bool Comedy::isClassic() const {
    return false;
}

bool Comedy::isDrama() const {
    return false;
}

bool Comedy::isComedy() const {
    return true;
}

