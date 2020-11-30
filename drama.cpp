#include "drama.h"

ostream& operator<<(ostream& outputStream, Drama& drama) {
	outputStream << drama.getFormat() << ", " << drama.getCurrentStock() << ", "
		<< drama.getTitle() << ", " << drama.getDirector() << ", "
		<< drama.getYearReleased();
	return outputStream;
}

int Drama::getYearReleased() {
	return this->yearReleased;
}

void Drama::setYearReleased(int year) {
	this->yearReleased = year;
}

bool Drama::operator<(const Drama& rightSide) const {
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

bool Drama::operator>(const Drama& rightSide) const {
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

bool Drama::operator==(const Drama& rightSide) const {
	return (this->director == rightSide.director && this->title == rightSide.title
		&& this->yearReleased == rightSide.yearReleased);
}

bool Drama::operator!=(const Drama& rightSide) const {
	return !(*this == rightSide);
}
