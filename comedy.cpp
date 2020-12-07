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

int Comedy::getYearReleased() {
	return this->yearReleased;
}

void Comedy::setYearReleased(int year) {
	this->yearReleased = year;
}

bool Comedy::operator<(const Comedy& rightSide) const {
	if (this->director.compare(rightSide.director) != 0) {
		return this->director.compare(rightSide.director) < 0;
		if (this->title.compare(rightSide.title) != 0) {
			return this->title.compare(rightSide.title) < 0;
		}
	}
	return false;
}

bool Comedy::operator>(const Comedy& rightSide) const {
	if (this->director.compare(rightSide.director) != 0) {
		return this->director.compare(rightSide.director) > 0;
		if (this->title.compare(rightSide.title) != 0) {
			return this->title.compare(rightSide.title) > 0;
		}
	}
	return false;
}

bool Comedy::operator==(const Comedy& rightSide) const {
	return (this->director.compare(rightSide.director) == 0 && this->title.compare(rightSide.title)
		== 0 && this->yearReleased == rightSide.yearReleased);
}

bool Comedy::operator!=(const Comedy& rightSide) const {
	return !(*this == rightSide);
}
