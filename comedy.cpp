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

