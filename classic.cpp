#include "classic.h"

ostream& operator<<(ostream& outputStream, Classic& classic) {
	outputStream << classic.getFormat() << ", " << classic.getCurrentStock() << ", "
		<< classic.getTitle() << ", " << classic.getDirector() << ", "
		<< classic.getMARD();
	return outputStream;
}

void Classic::display() {
	cout << *this << endl;
}

string Classic::getMARD() {
	return this->MARD;
}

void Classic::setMARD(string mard) {
	this->MARD = mard;
}

bool Classic::operator<(const Classic& rightSide) const {
	if (this->director.compare(rightSide.director) != 0) {
		return this->director.compare(rightSide.director) < 0;
		if (this->title.compare(rightSide.title) != 0) {
			return this->title.compare(rightSide.title) < 0;
			if (this->MARD.compare(rightSide.MARD) != 0) {
				return this->MARD.compare(rightSide.MARD) < 0;
			}
		}
	}
	return false;
}

bool Classic::operator>(const Classic& rightSide) const {
	if (this->director.compare(rightSide.director) != 0) {
		return this->director.compare(rightSide.director) > 0;
		if (this->title.compare(rightSide.title) != 0) {
			return this->title.compare(rightSide.title) > 0;
			if (this->MARD.compare(rightSide.MARD) != 0) {
				return this->MARD.compare(rightSide.MARD) > 0;
			}
		}
	}
	return false;
}

bool Classic::operator==(const Classic& rightSide) const {
	return (this->director.compare(rightSide.director) == 0 && this->title.compare(rightSide.title)
		== 0 && this->MARD.compare(rightSide.MARD) == 0);
}

bool Classic::operator!=(const Classic& rightSide) const {
	return !(*this == rightSide);
}