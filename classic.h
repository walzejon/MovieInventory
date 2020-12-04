//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_CLASSIC_H
#define MOVIEINVENTORY_CLASSIC_H
#include "movie.h"

class Classic : public Movie {
    friend ostream& operator<<(ostream& outputStream, Classic& classic);
public:
    string getMARD();
    void setMARD(string);
    virtual bool operator<(const Classic& rightSide) const;
    virtual bool operator>(const Classic& rightSide) const;
    virtual bool operator==(const Classic& rightSide) const;
    virtual bool operator!=(const Classic& rightSide) const;
private:
    string MARD;
};


#endif //MOVIEINVENTORY_CLASSIC_H
