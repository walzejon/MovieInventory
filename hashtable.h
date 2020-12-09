//
// Created by stlp on 11/28/20.
//

#ifndef MOVIEINVENTORY_HASHTABLE_H
#define MOVIEINVENTORY_HASHTABLE_H

#endif //MOVIEINVENTORY_HASHTABLE_H
#include <iostream>
#include <cstring>
#include <list>
#include "customer.h"

using namespace std;

//Stores the customers inside of the hashtable with unique Customer IDs.
class HashTable{

public:

    HashTable();
    ~HashTable();
    //takes ID and gives unique id from it.
    int hashFunction(int ID);
    //inserts A customer inside the hashtable
    //only needs customer because Customer stores its own ID
    void insertItem(Customer);
    void removeItem(int ID);
    Customer* get(int ID);
    int getSize();

    //displays the table and it's contents
    void display();
    void clear();
    bool isEmpty() const;

private:
    int size;
    static const int hashGroup = 1001;
    //list of customers
    list<Customer> table[hashGroup];
};