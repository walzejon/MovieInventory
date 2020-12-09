#include "history.h"
//---------------------------- Constructor ----------------------------------
// Default Constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
History::History() { }

//---------------------------- Destructor -----------------------------------
// Destructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
History::~History() { }

//---------------------------- display --------------------------------------
// Displays Customer history
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void History::display(Customer* cust) {
	cust->display();
}