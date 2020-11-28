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
