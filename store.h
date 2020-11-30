//
// Created by stlp on 11/25/20.
//

#ifndef MOVIEINVENTORY_STORE_H
#define MOVIEINVENTORY_STORE_H
#include "hashtable.h"
#include "transaction.h"
#include "bintree.h"
#include "customer.h"
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
    void newMoviestock();
    void printCustomers();
    void printHistory();
    void printMovies(BinTree* A);

private:
    HashTable customerTable<int ID, Customer cust>;

    BinTree F, D, C; //Comedy, Drama, Classic
    vector<Transaction> transHistory;
    void printHelp(Node* root);
};


#endif //MOVIEINVENTORY_STORE_H
