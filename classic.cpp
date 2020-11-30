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

bool Classic::operator<(const Classic& rightSide) const {
	int maxTitle = max(this->title.length(), rightSide.title.length());
	int maxDirector = max(this->director.length(), rightSide.director.length());
	int maxMARD = max(this->MARD.length(), rightSide.MARD.length());
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
	for (int i = 0; i < maxMARD; ++i) {
		if (this->MARD[i] == rightSide.MARD[i] || this->MARD[i] < rightSide.MARD[i])
			continue;
		else return false;
	}
	return true;
}

bool Classic::operator>(const Classic& rightSide) const {
	int maxTitle = max(this->title.length(), rightSide.title.length());
	int maxDirector = max(this->director.length(), rightSide.director.length());
	int maxMARD = max(this->MARD.length(), rightSide.MARD.length());
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
	for (int i = 0; i < maxMARD; ++i) {
		if (this->MARD[i] == rightSide.MARD[i] || this->MARD[i] > rightSide.MARD[i])
			continue;
		else return false;
	}
	return true;
}

bool Classic::operator==(const Classic& rightSide) const {
	return (this->director == rightSide.director && this->title == rightSide.title &&
		this->MARD == rightSide.MARD);
}

bool Classic::operator!=(const Classic& rightSide) const {
	return !(*this == rightSide);
}