//
// Created by stlp on 11/28/20.
//
#include "hashtable.h"

bool HashTable::isEmpty() const
{
    int sum;
    for (int i; i < hashGroup; i++)
    {
        sum+=table[i].size();
    }
    if(sum ==0) return true;
    else return false;
}

int HashTable::hashFunction(int ID)
{
    return ID % hashGroup;
}

void HashTable::insertItem(int ID, Customer cust)
{
    int hashValue = hashFunction(ID);
    auto& cell = table[hashValue];
    auto iter = begin(cell);
    bool keyExists = false;
    for(; iter != end(cell); iter++)
    {
        if(iter->first == ID) {
            keyExists = true;
            iter->second = cust;
            cout << "[WARNING] Cutomer ID already exists. Customer replaced";
            break;
        }
    }
    if(!keyExists)
    {
        cell.emplace_back(ID, cust);
    }
    return;
}

void HashTable::removeItem(int ID)
{
    int hashValue = hashFunction(ID);
    auto& cell = table[hashValue];
    auto iter = begin(cell);
    bool keyExists = false;
    for(; iter != end(cell); iter++)
    {
        if(iter->first == ID) {
            keyExists = true;
            iter = cell.erase(iter);
            cout << "[INFO] Customer ID " << ID << " removed";
            break;
        }
    }
    if(!keyExists)
    {
        cout << "[WARNING] Cutomer ID not found. Nothing was removed.";
    }
    return;
}

void HashTable::print()
{
    for(int i = 0; i < hashGroup; i++)
    {
        if(table[i].size() == 0 ) continue;

        auto iter = table[i].begin();
        for(; iter != table[i].end(); iter++)
        {
            cout << "[INFO] Key: " <<
        }
    }
}
