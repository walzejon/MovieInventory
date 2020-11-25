#pragma once
#ifndef MOVIEINVENTORY_TRANSACTION_H
#define MOVIEINVENTORY_TRANSACTION_H

class Transaction {
public:
	Transaction();
	~Transaction();
private:
	int transactionID;
	char type;
	bool hasBeenBorrowed;
};

#endif