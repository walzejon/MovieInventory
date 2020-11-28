#include "classic.h"

ostream& operator<<(ostream& outputStream, Classic& classic) {
	outputStream << classic.getFormat() << ", " << classic.getCurrentStock() << ", "
		<< classic.getTitle() << ", " << classic.getDirector() << ", "
		<< classic.getMARD();
	return outputStream;
}

string Classic::getMARD() {
	return this->MARD;
}

void Classic::setMARD(string mard) {
	this->MARD = mard;
}