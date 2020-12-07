#ifndef MOVIEINVENTORY_HISTORY_H
#define MOVIEINVENTORY_HISTORY_H
#include <algorithm>
#include <string>
#include "transaction.h"
#include "customer.h"
using namespace std;

class History : public Transaction {
public:
	History();
	~History();
	void display(Customer*);
};
#endif