//
// Created by stlp on 11/25/20.
//

#ifndef MOVIEINVENTORY_STORE_H
#define MOVIEINVENTORY_STORE_H
#include "hashtable.h"
#include "transaction.h"
#include "bintree.h"
#include "customer.h"
#include "movie.h"
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Store {
public:
    Store();
    ~Store();
    void addCustomers(ifstream&);
    void addMovieInventory(ifstream&);
    void doCommands(ifstream&);
    //void newMoviestock(); idk if we need this
    void printCustomers();
    void printHistory();
    void borrowMovie(char movieGenre, string movieData);
    void showStock() const;
    void printMoviesSideways(BinTree* A) const;

private:
    HashTable customerTable;
    BinTree F, D, C; //Comedy, Drama, Classic
    vector<Transaction> transHistory;
};


#endif //MOVIEINVENTORY_STORE_H
