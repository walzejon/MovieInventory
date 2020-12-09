#include "comedy.h"

ostream& operator<<(ostream& outputStream, Comedy& com) {
	outputStream << com.getFormat() << ", " << com.getCurrentStock() << ", "
		<< com.getDirector() << ", " << com.getTitle() << ", " 
		<< com.getYearReleased();
	return outputStream;
}

Comedy::Comedy() {
	this->director = "";
	this->title = "";
	this->yearReleased = 0;
}

Comedy::Comedy(string direc, string tit, int yearR) {
	director = direc;
	title = tit;
	yearReleased = yearR;
}


void Comedy::display() {
	cout << *this << endl;
}

int Comedy::getYearReleased() const {
	return this->yearReleased;
}

void Comedy::setYearReleased(int year) {
	this->yearReleased = year;
}

bool Comedy::operator<(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	if (this->title.compare(otherComedy->getTitle()) != 0) {
		return this->title.compare(otherComedy->getTitle()) < 0;
		if (this->yearReleased == (otherComedy->getYearReleased()) != 0) {
			return this->yearReleased == (otherComedy->getYearReleased()) < 0;
		}
	}
	return false;
}

bool Comedy::operator>(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	if (this->title.compare(otherComedy->getTitle()) != 0) {
		return this->title.compare(otherComedy->getTitle()) > 0;
		if (this->yearReleased == (otherComedy->getYearReleased()) != 0) {
			return this->yearReleased == (otherComedy->getYearReleased()) > 0;
		}
	}
	return false;
}

bool Comedy::operator==(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return (this->title.compare(otherComedy->getTitle()) == 0 && this->yearReleased == otherComedy->getYear());
}

bool Comedy::operator!=(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return !(*this == *otherComedy);
}

bool Comedy::isClassic() const {
    return false;
}

bool Comedy::isDrama() const {
    return false;
}

bool Comedy::isComedy() const {
    return true;
}

