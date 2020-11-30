#include "comedy.h"

ostream& operator<<(ostream& outputStream, Comedy& com) {
	outputStream << com.getFormat() << ", " << com.getCurrentStock() << ", "
		<< com.getTitle() << ", " << com.getDirector() << ", " 
		<< com.getYearReleased();
	return outputStream;
}

int Comedy::getYearReleased() {
	return this->getYearReleased;
}

void Comedy::setYearReleased(int year) {
	this->yearReleased = year;
}

bool Comedy::operator<(const Comedy& rightSide) const {
	int maxTitle = max(this->title.length(), rightSide.title.length());
	int maxDirector = max(this->director.length(), rightSide.director.length());
	for (int i = 0; i < maxDirector; ++i) {
		if (this->director[i] == rightSide.director[i] || this->director[i] <
			rightSide.director[i]) continue;
		else return false;
	}
	for (int i = 0; i < maxTitle; ++i) {
		if (this->title[i] == rightSide.title[i] || this->title[i] < rightSide.title[i])
			continue;
		else return false;
	}
	return true;
}

bool Comedy::operator>(const Comedy& rightSide) const {
	int maxTitle = max(this->title.length(), rightSide.title.length());
	int maxDirector = max(this->director.length(), rightSide.director.length());
	for (int i = 0; i < maxDirector; ++i) {
		if (this->director[i] == rightSide.director[i] || this->director[i] >
			rightSide.director[i]) continue;
		else return false;
	}
	for (int i = 0; i < maxTitle; ++i) {
		if (this->title[i] == rightSide.title[i] || this->title[i] > rightSide.title[i])
			continue;
		else return false;
	}
	return true;
}

bool Comedy::operator==(const Comedy& rightSide) const {
	return (this->director == rightSide.director && this->title == rightSide.title
		&& this->yearReleased == rightSide.yearReleased);
}

bool Comedy::operator!=(const Comedy& rightSide) const {
	return !(*this == rightSide);
}
