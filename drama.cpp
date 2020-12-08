#include "drama.h"

ostream& operator<<(ostream& outputStream, Drama& drama) {
	outputStream << drama.getFormat() << ", " << drama.getCurrentStock() << ", "
		<< drama.getTitle() << ", " << drama.getDirector() << ", "
		<< drama.getYearReleased();
	return outputStream;
}

void Drama::display() const {
	cout << *this << endl;
}

int Drama::getYearReleased() const {
	return this->yearReleased;
}

void Drama::setYearReleased(int year) {
	this->yearReleased = year;
}

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
	return (this->director.compare(otherDrama->getDirector()) == 0 && this->title.compare(otherDrama->getTitle())
		== 0 && this->yearReleased == otherDrama->getYearReleased());
}

bool Drama::operator!=(const Movie& rightSide) const {
    if(!rightSide.isDrama()) return false;
    const auto otherDrama = dynamic_cast<const Drama*>(&rightSide);
	return !(*this == *otherDrama);
}

bool Drama::isClassic() const {
    return false;
}

bool Drama::isDrama() const {
    return true;
}

bool Drama::isComedy() const {
    return false;
}

Drama::Drama(string direc, string tit, int yearR) {
    director = direc;
    title = tit;
    yearReleased = yearR;
}
