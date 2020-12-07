#include "transaction.h"
#include <random>

Transaction::Transaction() {
	
}

void Transaction::setTransactionType(char transType) {
	this->transactionType = transType;
}

void Transaction::display() {
	cout << this->mediaType << " " << transactionType;
}