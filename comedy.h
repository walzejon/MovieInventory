//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_COMEDY_H
#define MOVIEINVENTORY_COMEDY_H
#include "movie.h"

class Comedy : public Movie {
    friend ostream& operator<<(ostream& outputStream, Comedy& com);
public:
    //constructor
    Comedy();
    //copy constructor
    Comedy(string direc, string tit, int yearR);
    //getter
    int getYearReleased() const;
    //setter
    void setYearReleased(int year);
    //display
    void display();
    //returns true if movie is comedy or false if it's another genre
    virtual bool isClassic() const;
    virtual bool isDrama() const;
    virtual bool isComedy() const;
    //comparison operators
    virtual bool operator<(const Movie& rightSide) const;
    virtual bool operator>(const Movie& rightSide) const;
    virtual bool operator==(const Movie& rightSide) const;
    virtual bool operator!=(const Movie& rightSide) const;
};


#endif //MOVIEINVENTORY_COMEDY_H
