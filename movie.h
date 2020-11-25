//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_MOVIE_H
#define MOVIEINVENTORY_MOVIE_H


class Movie {

public:
    Movie();
    ~Movie();
    String getFormat();
    setFormat();
    int getCurrentStock();
    setCurrentStock();
    setStockOwned(int n);
    String getTitle();
    setTitle(string t);
    String getDirector();
    setDirector(string s);
    string toString();
private:
    String movieFormat;
    String title;
    int currentStock;
    int stockOwned;
    String director;
};


#endif //MOVIEINVENTORY_MOVIE_H
