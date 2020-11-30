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

class HashTable{

public:
    HashTable();
    ~HashTable();
    int hashFunction(int ID);
    void insertItem(int, Customer);
    void removeItem(int ID);
    //bool hasItem(int ID); I added this but idk if we need it. I dont think so bc i think getCust can jus
    Customer getCust(int ID); //idk how to do this
    void print();
    void clear();
    bool isEmpty() const;

private:
    int size;
    static const int hashGroup = 10;
    list<pair<int,Customer>>table[hashGroup];
};