//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_COMEDY_H
#define MOVIEINVENTORY_COMEDY_H
#include "movie.h"

friend ostream& operator<<(ostream& outputStream, Comedy& com);

class Comedy : public Movie {
public:
    int getYearReleased();
    void setYearReleased(int year);
private:
    int yearReleased;
};


#endif //MOVIEINVENTORY_COMEDY_H
