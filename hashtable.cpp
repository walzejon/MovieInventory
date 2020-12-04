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

void HashTable::insertItem(int ID, Customer cust) // should i require the user to input an ID or just call cust.id??
{                                  // idk if cust should be a reference or not
    int hashValue = hashFunction(ID);
    auto& cell = table[hashValue];
    bool keyExists = false;
    auto iter = begin(cell);
    for(; iter != end(cell); iter++)
    {
        if(iter->getCustomerID() == ID) {
            keyExists = true;
            //iter->second = cust; what video showed
            cell.emplace_back(cust); // what i did instead?
            cout << "[WARNING] Customer ID already exists. Customer replaced";
            break;
        }
    }
    if(!keyExists)
    {
        cell.emplace_back(cust);
    }
}

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

void HashTable::display()
{
    for(int i = 0; i < hashGroup; i++)
    {
        if(table[i].size() == 0 ) continue;

        auto iter = table[i].begin();
        for(; iter != table[i].end(); iter++)
        {
            cout << "At table position: " << i << " [INFO] Key: " << iter->getCustomerID() << " Value: " << "iter->second.. but for now 'cust data'" << endl;
        }
    }
}

Customer HashTable::get(int ID) {
    int index = hashFunction(ID);
    bool foundCustomer = false;
    Customer findMe;
    auto& cell = table[index]; //error here
    auto iter = begin(cell);

    for(; iter != end(cell); iter++)
    {
        if(iter->getCustomerID() == ID) {
            foundCustomer = true;
            findMe = *iter;
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
    return Customer(-1,"notFound","notFound"); //Customer not found
}

//int main()
//{
//    HashTable HT;
//
//    if(HT.isEmpty())
//    {
//        cout<<"isEmpty works right" <<endl;
//    } else
//    {
//        cout << "ERROR isEmpty is not working" << endl;
//    }
//
//    Customer James =  Customer(1102,"James","Jackson");
//    HT.insertItem(1102,James);
//    HT.insertItem(1101,Customer(1101,"Hi","Bye"));
//    HT.insertItem(6969, Customer(6969,"sixtey","nine"));
//    HT.insertItem(1101,Customer(1101,"James","Bond"));
//
//    HT.display();
//
//    HT.removeItem(1101);
//    HT.display();
//
//    if(HT.isEmpty()) cout << "ERROR isEmpty is not working" << endl;
//    else cout<<"isEmpty works right" <<endl;
//}