#pragma once
#ifndef MOVIEINVENTORY_TRANSACTION_H
#define MOVIEINVENTORY_TRANSACTION_H

class Transaction {
public:
	Transaction();
	~Transaction();
protected:
	int transactionID;
	char transactionType;
	string movieType;
	string mediaType;
	bool hasBeenBorrowed;
};

#endif