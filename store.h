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
#include "borrow.h"
#include "return.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Store {
public:
    Store();                                       // Constructor
    ~Store();                                      // Destructor
    void addCustomers(ifstream&);                  // Add customers
    void addMovieInventory(ifstream&);             // Add movie into inventory
    void doCommands(ifstream&);                    // Perform commands
    void printCustomers();                         // Print out customer list
    void printHistory();                           // Print out transaction history
    void showStock() const;                        // Show the current stock
    void printMoviesSideways(BinTree* A) const;    // Sideways BinTree display

private:
    void borrowMovie(Customer* borrower, char movieGenre, ifstream& infile);  //borrow movie
    void returnMovie(Customer* cust, char movieGenre, ifstream& infile);      //return movie

    HashTable customerTable;                    
    BinTree F, D, C; //Comedy, Drama, Classic
    vector<Transaction> transHistory;
};


#endif //MOVIEINVENTORY_STORE_H
