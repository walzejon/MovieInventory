#include "transaction.h"
#include <random>

Transaction::Transaction() { }

Transaction::~Transaction() { }

void Transaction::setTransactionType(char transType) {
	this->transactionType = transType;
}

void Transaction::display() const {
	cout << this->mediaType << " " << transactionType;
}