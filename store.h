//
// Created by stlp on 11/25/20.
//

#ifndef MOVIEINVENTORY_STORE_H
#define MOVIEINVENTORY_STORE_H
#include "transaction.h"
#include <iostream>
#include <fstream>

using namespace std;


class Store {
public:
    Store();
    ~Store();
    void addCustomers(ifstream&);
    void addMovieInventory(ifstream&);
    void doCommands(ifstream&);
    void newMoviestock();
    void printCustomers();
    void printHistory();
    void printMovies();

private:
    HashTable<int ID, Customer cust>;
    BinTree F, D, C; //Comedy, Drama, Classic       - Is this how we want to do this?
    Vector<Transaction> transHistory;
};


#endif //MOVIEINVENTORY_STORE_H
