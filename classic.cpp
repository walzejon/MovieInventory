#include "classic.h"
//ostream operator to display output
ostream& operator<<(ostream& outputStream, Classic& classic) {
	outputStream << classic.getFormat() << ", " << classic.getCurrentStock() << ", "
		<< classic.getDirector() << ", " << classic.getTitle() << ", "
		<< classic.getMARD();
	return outputStream;
}
//constructor
Classic::Classic() {
	this->director = "";
	this->title = "";
	this->MARD = "";
}
// constructor
Classic::Classic(string di, string tit, string mard)
{
	MARD = mard;
	director = di;
	title = tit;
}
//displays  classic movies
void Classic::display() {
	cout << *this << endl;
}

string Classic::getMARD() const {
	return this->MARD;
}

void Classic::setMARD(string mard) {
	this->MARD = mard;
}
//getter
string Classic::getMA() const {
	return this->MA;
}
//setter
void Classic::setMA(string MA) {
	this->MA = MA;
}
//
bool Classic::operator<(const Movie& rightSide) const {
    //Make sure it really is classic, if not return false
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
    // test
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
    // test
    return false;
}
//comparison operator
bool Classic::operator==(const Movie& rightSide) const {
    //Make sure right side is Classic!
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	return (this->month == otherClassic->month && this->year == otherClassic->year &&
		this->MA.compare(otherClassic->MA) == 0);
}
//comparison operator
bool Classic::operator!=(const Movie& rightSide) const {
    //Make sure rightSide is classic!!
    if(!rightSide.isClassic()) return false;
    const auto otherClassic = dynamic_cast<const Classic*>(&rightSide);
	return !(*this == *otherClassic);
}
//returns true if it's a classic movie
bool Classic::isClassic() const {
    return true;
}
//returns false if it's a drama movie
bool Classic::isDrama() const {
    return false;
}
//returns false if it's a drama movie
bool Classic::isComedy() const {
    return false;
}

Classic::Classic(int mo, int ye, string ma) {
    this->month = mo;
    this->year = ye;
    this-> MA = ma;
}
