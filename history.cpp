#include "history.h"

History::History() { }

History::~History() { }

void History::display(Customer* cust) {
	cust->displayCustomerHistory();
}