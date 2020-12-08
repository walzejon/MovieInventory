//
// Created by stlp on 11/24/20.
//

#ifndef MOVIEINVENTORY_MOVIE_H
#define MOVIEINVENTORY_MOVIE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Movie {
    friend ostream& operator<<(ostream& outputStream, Movie& movie);

public:
    // Constructor & Destructor
    Movie();
    ~Movie();

    // Getter and Setter for movieFormat
    string getFormat();
    void setFormat(string movieFormat);

    // Getter and Setter for currentStock
    int getCurrentStock();
    void setCurrentStock(int currentStock);

    // Getter and Setter for stockOwned
    int getStockOwned();
    void setStockOwned(int stockOwned);

    int getStockDifference();

    // Getter and Setter for title
    string getTitle() const;
    void setTitle(string title);

    // Getter and Setter for director
    string getDirector() const;
    void setDirector(string director);

    // Getter and Setter for maxStock
    int getMaxStock();
    void setMaxStock(int stock);

    virtual bool isClassic() const = 0;
    virtual bool isDrama() const = 0;
    virtual bool isComedy() const = 0;

    virtual void display();

    virtual bool operator==(const Movie&) const = 0;
    virtual bool operator!=(const Movie&) const = 0;
    virtual bool operator<(const Movie&) const = 0;
    virtual bool operator>(const Movie&) const = 0;

protected:
    string movieFormat;
    int currentStock;
    int stockOwned;
    string title;
    string director;
    int maxStock;
};


#endif //MOVIEINVENTORY_MOVIE_H
