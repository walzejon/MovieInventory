//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_CLASSIC_H
#define MOVIEINVENTORY_CLASSIC_H
#include "movie.h"

class Classic : public Movie {
    friend ostream& operator<<(ostream& outputStream, Classic& classic);
public:
    //default constructor
    Classic();
    //copy constructor
    Classic(int mo, int ye, string ma);

    Classic(string di, string tit, string MARD);
    string getMARD() const;
    void setMARD(string);
    string getMA() const;
    //getter
    int getMonth() const;
    //setter
    void setMA(string);
    //display
    void display();
    virtual bool isClassic() const;
    virtual bool isDrama() const;
    virtual bool isComedy() const;
    //less than operator
    virtual bool operator<(const Movie& rightSide) const;
    //more than operator
    virtual bool operator>(const Movie& rightSide) const;
    //equals operator
    virtual bool operator==(const Movie& rightSide) const;
    //comparison operator
    virtual bool operator!=(const Movie& rightSide) const;
private:
    string MARD;
};


#endif //MOVIEINVENTORY_CLASSIC_H
