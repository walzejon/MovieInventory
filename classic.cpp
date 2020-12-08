#include "classic.h"

ostream& operator<<(ostream& outputStream, Classic& classic) {
	outputStream << classic.getFormat() << ", " << classic.getCurrentStock() << ", "
		<< classic.getDirector() << ", " << classic.getTitle() << ", "
		<< classic.getMARD();
	return outputStream;
}

void Classic::display() {
	cout << *this << endl;
}

string Classic::getMARD() const {
	return this->MARD;
}

void Classic::setMARD(string mard) {
	this->MARD = mard;
}

bool Classic::operator<(const Movie& rightSide) const {
    //MAKE SURE it really is a classic , if not return false
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	if (this->director.compare(otherClassic->getDirector()) != 0) {
		return this->director.compare(otherClassic->getDirector()) < 0;
		if (this->title.compare(otherClassic->getTitle()) != 0) {
			return this->title.compare(otherClassic->getTitle()) < 0;
			if (this->MARD.compare(otherClassic->getMARD()) != 0) {
				return this->MARD.compare(otherClassic->getMARD()) < 0;
			}
		}
	}
	return false;
}

bool Classic::operator>(const Movie& rightSide) const {
    //Make sure it really is classic, if not return false
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	if (this->director.compare(otherClassic->getDirector()) != 0) {
		return this->director.compare(otherClassic->getDirector()) > 0;
		if (this->title.compare(otherClassic->getTitle()) != 0) {
			return this->title.compare(otherClassic->getTitle()) > 0;
			if (this->MARD.compare(otherClassic->getMARD()) != 0) {
				return this->MARD.compare(otherClassic->getMARD()) > 0;
			}
		}
	}
	return false;
}

bool Classic::operator==(const Movie& rightSide) const {
    //Make sure right side is Classic!
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	return (this->director.compare(otherClassic->getDirector()) == 0 && this->title.compare(otherClassic->getTitle())
		== 0 && this->MARD.compare(otherClassic->getMARD()) == 0);
}

bool Classic::operator!=(const Movie& rightSide) const {
    //Make sure rightSide is classic!!
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	return !(*this == *otherClassic);
}

Classic::Classic(string di, string tit, string mard)
{
    MARD = mard;
    director = di;
    title = tit;
}

bool Classic::isClassic() const {
    return true;
}

bool Classic::isDrama() const {
    return false;
}

bool Classic::isComedy() const {
    return false;
}
