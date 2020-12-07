#pragma once
#ifndef MOVIEINVENTORY_TRANSACTION_H
#define MOVIEINVENTORY_TRANSACTION_H
#include <iostream>
using namespace std;

class Transaction {
public:
	Transaction();
	~Transaction();
	void setTransactionType(char);
	void display();
protected:
	int transactionID;
	char transactionType;
	string movieType;
	string mediaType;
	bool hasBeenBorrowed;
};

#endif