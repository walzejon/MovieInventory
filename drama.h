//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_DRAMA_H
#define MOVIEINVENTORY_DRAMA_H
#include "movie.h"
#include <algorithm>

class Drama : public Movie {
    friend ostream& operator<<(ostream& outputStream, Drama& drama);
public:
    int getYearReleased();
    void setYearReleased(int year);
    bool operator<(const Drama& rightSide) const;
    bool operator>(const Drama& rightSide) const;
    bool operator==(const Drama& rightSide) const;
    bool operator!=(const Drama& rightSide) const;
private:
    int yearReleased;
};


#endif //MOVIEINVENTORY_DREAMA_H
