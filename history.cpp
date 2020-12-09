#include "history.h"
//constructor
History::History() { }
//destructor
History::~History() { }
//display
void History::display(Customer* cust) {
	cust->display();
}