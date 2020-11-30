//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_COMEDY_H
#define MOVIEINVENTORY_COMEDY_H
#include "movie.h"

class Comedy : public Movie {
    friend ostream& operator<<(ostream& outputStream, Comedy& com);
public:
    int getYearReleased();
    void setYearReleased(int year);
    bool operator<(const Comedy& rightSide) const;
    bool operator>(const Comedy& rightSide) const;
    bool operator==(const Comedy& rightSide) const;
    bool operator!=(const Comedy& rightSide) const;
private:
    int yearReleased;
};


#endif //MOVIEINVENTORY_COMEDY_H
