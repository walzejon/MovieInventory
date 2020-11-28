//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_CLASSIC_H
#define MOVIEINVENTORY_CLASSIC_H
#include "movie.h"

friend ostream& operator<<(ostream& outputStream, Classic& classic);

class Classic : public Movie {
public:
    string getMARD();
    void setMARD(string);
private:
    string MARD;
};


#endif //MOVIEINVENTORY_CLASSIC_H
