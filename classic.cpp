#include "classic.h"

ostream& operator<<(ostream& outputStream, Classic& classic) {
	outputStream << classic.getFormat() << ", " << classic.getCurrentStock() << ", "
		<< classic.getDirector() << ", " << classic.getTitle() << ", "
		<< classic.getMARD();
	return outputStream;
}

Classic::Classic() {
	this->director = "";
	this->title = "";
	this->MARD = "";
}

Classic::Classic(int mo, int ye, string ma)
{
	month = mo;
	year = ye;
	MA = ma;
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

string Classic::getMA() const {
	return this->MA;
}

void Classic::setMA(string MA) {
	this->MA = MA;
}

bool Classic::operator<(const Movie& rightSide) const {
    //MAKE SURE it really is a classic , if not return false
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
    if (this->year < otherClassic->year) {
        return true;
    }
    else if (this->year == otherClassic->year) {
        if (this->month < otherClassic->month) return true;
        else if (this->month == otherClassic->month)
            if (this->MA.compare(otherClassic->MA) < 0) return true;
    }
    return false;

}

bool Classic::operator>(const Movie& rightSide) const {
    //Make sure it really is classic, if not return false
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
    if (this->year > otherClassic->year) {
        return true;
    }
    else if (this->year == otherClassic->year) {
        if (this->month > otherClassic->month) return true;
        else if (this->month == otherClassic->month)
            if (this->MA.compare(otherClassic->MA) > 0) return true;
    }
    return false;
}

bool Classic::operator==(const Movie& rightSide) const {
    //Make sure right side is Classic!
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	return (this->month == otherClassic->month && this->year == otherClassic->year &&
		this->MA.compare(otherClassic->MA) == 0);
}

bool Classic::operator!=(const Movie& rightSide) const {
    //Make sure rightSide is classic!!
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	return !(*this == *otherClassic);
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

int Classic::getMonth() const {
    return this->month;
}
