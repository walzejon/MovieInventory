#include "transaction.h"
#include <random>

//---------------------------- Constructor ----------------------------------
// Default Constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Transaction::Transaction() { }

//---------------------------- Destructor -----------------------------------
// Displays hash table
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Transaction::~Transaction() { }

//---------------------------- setTransactionType ---------------------------
// Sets the transaction type Borrow or Return 'B' 'R'
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Transaction::setTransactionType(char transType) {
	this->transactionType = transType;
}

//---------------------------- display --------------------------------------
// Displays media type and transaction type
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Transaction::display() const {
	cout << this->mediaType << " " << transactionType;
}