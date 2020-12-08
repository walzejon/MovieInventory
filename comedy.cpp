#include "comedy.h"

ostream& operator<<(ostream& outputStream, Comedy& com) {
	outputStream << com.getFormat() << ", " << com.getCurrentStock() << ", "
		<< com.getTitle() << ", " << com.getDirector() << ", " 
		<< com.getYearReleased();
	return outputStream;
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
	if (this->director.compare(otherComedy->getDirector()) != 0) {
		return this->director.compare(otherComedy->getDirector()) < 0;
		if (this->title.compare(otherComedy->getTitle()) != 0) {
			return this->title.compare(otherComedy->getTitle()) < 0;
		}
	}
	return false;
}

bool Comedy::operator>(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	if (this->director.compare(otherComedy->getDirector()) != 0) {
		return this->director.compare(otherComedy->getDirector()) > 0;
		if (this->title.compare(otherComedy->getTitle()) != 0) {
			return this->title.compare(otherComedy->getTitle()) > 0;
		}
	}
	return false;
}

bool Comedy::operator==(const Movie& rightSide) const {
    if(!rightSide.isComedy()) return false;
    const auto otherComedy = dynamic_cast<const Comedy*>(&rightSide);
	return (this->director.compare(otherComedy->getDirector()) == 0 && this->title.compare(otherComedy->getTitle())
		== 0 && this->yearReleased == otherComedy->getYearReleased());
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

Comedy::Comedy(string direc, string tit, int yearR) {
    director = direc;
    title = tit;
    yearReleased = yearR;
}

