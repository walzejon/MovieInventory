//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_CLASSIC_H
#define MOVIEINVENTORY_CLASSIC_H
#include "movie.h"

class Classic : public Movie {
    friend ostream& operator<<(ostream& outputStream, Classic& classic);
public:
    Classic();
    Classic(string di, string tit, string mard);
    string getMARD() const;
    void setMARD(string);
    void display();
    virtual bool isClassic() const;
    virtual bool isDrama() const;
    virtual bool isComedy() const;
    virtual bool operator<(const Movie& rightSide) const;
    virtual bool operator>(const Movie& rightSide) const;
    virtual bool operator==(const Movie& rightSide) const;
    virtual bool operator!=(const Movie& rightSide) const;
private:
    string MARD;
};


#endif //MOVIEINVENTORY_CLASSIC_H
