//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_DRAMA_H
#define MOVIEINVENTORY_DRAMA_H
#include "movie.h"

class Drama : public Movie {
    friend ostream& operator<<(ostream& outputStream, Drama& drama);
public:
    //constructor
    Drama();
    //copy constructor
    Drama(string direc, string tit, int yearR);
    //getters and setters
    int getYearReleased() const;
    void setYearReleased(int year);
    string getTitle() const;
    //display
    void display();

    //returns true if it's drama or false if it's not
    virtual bool isClassic() const;
    virtual bool isDrama() const;
    virtual bool isComedy() const;

    //comparison operators
    virtual bool operator<(const Movie& rightSide) const;
    virtual bool operator>(const Movie& rightSide) const;
    virtual bool operator==(const Movie& rightSide) const;
    virtual bool operator!=(const Movie& rightSide) const;
};


#endif //MOVIEINVENTORY_DREAMA_H
