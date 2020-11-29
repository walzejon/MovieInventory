//
// Created by stlp on 11/28/20.
//

#ifndef MOVIEINVENTORY_HASHTABLE_H
#define MOVIEINVENTORY_HASHTABLE_H

#endif //MOVIEINVENTORY_HASHTABLE_H
#include <iostream>
#include "customer.h"

using namespace std;

class HashTable{
public:
    HashTable();
    ~HashTable();
    int hashFunction(int);
    bool insertItem(int, Customer);
    void removeItem(int, Customer);
    bool findItem();
    void print();
    void clear();
    bool isEmpty();

private:
    int size;
    //table:list<pair<int,Customer>>[size]
};