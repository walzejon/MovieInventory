//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_DRAMA_H
#define MOVIEINVENTORY_DRAMA_H
#include "movie.h"

class Drama : public Movie {
    friend ostream& operator<<(ostream& outputStream, Drama& drama);
public:
    int getYearReleased() const;
    void setYearReleased(int year);
    void display();
    virtual bool isClassic() const;
    virtual bool isDrama() const;
    virtual bool isComedy() const;
    virtual bool operator<(const Drama& rightSide) const;
    virtual bool operator>(const Drama& rightSide) const;
    virtual bool operator==(const Drama& rightSide) const;
    virtual bool operator!=(const Drama& rightSide) const;
private:
    int yearReleased;
};


#endif //MOVIEINVENTORY_DREAMA_H
