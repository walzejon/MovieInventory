//
// Created by stlp on 11/28/20.
//
#include "hashtable.h"

bool HashTable::isEmpty() const
{
    int sum=0;
    for (int i=0; i < hashGroup; i++)
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
// PRE: Customer must contain it's own unique ID. Use cutomer.getID() to get ID
// Post: IF the hashTable contains a customer with given ID it replaces that customer
void HashTable::insertItem(Customer cust)
{
    int hashValue = hashFunction(cust.getCustomerID());
    auto& cell = table[hashValue];
    bool keyExists = false;
    auto iter = begin(cell);
    for(; iter != end(cell); iter++)
    {
        if(iter->getCustomerID() == cust.getCustomerID()) {
            cout << "[WARNING] Customer ID already exists. Customer: " <<
                 iter->getFirstName() << " " << iter->getLastName() << " " << "Replaced by " << cust.getFirstName()
                 << " " << cust.getLastName() << endl;
            keyExists = true;
            *iter = cust;
            break;
        }
    }
    if(!keyExists)
    {
        cell.emplace_back(cust);
    }
}

//Removes a customer with given ID
void HashTable::removeItem(int ID)
{
    int hashValue = hashFunction(ID);
    auto& cell = table[hashValue];
    auto iter = begin(cell);
    bool keyExists = false;
    for(; iter != end(cell); iter++)
    {
        if(iter->getCustomerID() == ID) {
            keyExists = true;
            iter = cell.erase(iter);
            cout << "[INFO] Customer ID " << ID << " removed" <<endl;
            break;
        }
    }
    if(!keyExists)
    {
        cout << "[WARNING] Cutomer ID not found. Nothing was removed." << endl;
    }
}

void HashTable::display()
{
    for(int i = 0; i < hashGroup; i++)
    {
        if(table[i].size() == 0 ) continue;

        auto iter = table[i].begin();
        for(; iter != table[i].end(); iter++)
        {
            cout << "At table position: " << i << " [INFO] Key: " << iter->getCustomerID() << " Value: " << iter->getFirstName() << " " << iter->getLastName() << endl;
        }
    }
}

//PRE: ID must be valid, else throws error message.
// returns a customer with given ID.
Customer* HashTable::get(int ID) {
    int index = hashFunction(ID);
    bool foundCustomer = false;
    Customer* findMe = new Customer();
    auto& cell = table[index]; //error here
    auto iter = begin(cell);

    for(; iter != end(cell); iter++)
    {
        if(iter->getCustomerID() == ID) {
            foundCustomer = true;
            *findMe = *iter;
            break;
        }
    }
    if(foundCustomer)
    {
        cout << "Found Customer ID: " << ID << endl;
        return findMe;
    } else
    {
        cout << "[ERROR] ID: " << ID << " not found." << endl;
    }
    return new Customer(-1,"notFound","notFound"); //Customer not found
}

HashTable::HashTable() {
    size = 100;
}

HashTable::~HashTable() {
    this->clear();
}

int HashTable::getSize() {
    return size;
}

void HashTable::clear() {
    for(int i = 0; i <hashGroup; i++)
    {
        table[i].clear();
    }
}