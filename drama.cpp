#include "drama.h"

ostream& operator<<(ostream& outputStream, Drama& drama) {
	outputStream << drama.getFormat() << ", " << drama.getCurrentStock() << ", "
		<< drama.getTitle() << ", " << drama.getDirector() << ", "
		<< drama.getYearReleased();
	return outputStream;
}

void Drama::display() {
	cout << *this << endl;
}

int Drama::getYearReleased() {
	return this->yearReleased;
}

void Drama::setYearReleased(int year) {
	this->yearReleased = year;
}

bool Drama::operator<(const Drama& rightSide) const {
	if (this->director.compare(rightSide.director) != 0) {
		return this->director.compare(rightSide.director) < 0;
		if (this->title.compare(rightSide.title) != 0) {
			return this->title.compare(rightSide.title) < 0;
		}
	}
	return false;
}

bool Drama::operator>(const Drama& rightSide) const {
	if (this->director.compare(rightSide.director) != 0) {
		return this->director.compare(rightSide.director) > 0;
		if (this->title.compare(rightSide.title) != 0) {
			return this->title.compare(rightSide.title) > 0;
		}
	}
	return false;
}

bool Drama::operator==(const Drama& rightSide) const {
	return (this->director.compare(rightSide.director) == 0 && this->title.compare(rightSide.title)
		== 0 && this->yearReleased == rightSide.yearReleased);
}

bool Drama::operator!=(const Drama& rightSide) const {
	return !(*this == rightSide);
}