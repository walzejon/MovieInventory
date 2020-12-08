//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_COMEDY_H
#define MOVIEINVENTORY_COMEDY_H
#include "movie.h"

class Comedy : public Movie {
    friend ostream& operator<<(ostream& outputStream, Comedy& com);
public:
    int getYearReleased() const;
    void setYearReleased(int year);
    void display();
    virtual bool isClassic() const;
    virtual bool isDrama() const;
    virtual bool isComedy() const;
    virtual bool operator<(const Comedy& rightSide) const;
    virtual bool operator>(const Comedy& rightSide) const;
    virtual bool operator==(const Comedy& rightSide) const;
    virtual bool operator!=(const Comedy& rightSide) const;
private:
    int yearReleased;
};


#endif //MOVIEINVENTORY_COMEDY_H
