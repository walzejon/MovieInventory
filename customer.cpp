/*
Cindy Acevedo
CSS 343 
Assignment 4
*/

#include "customer.h"


//---------------------------- Constructor ----------------------------------
// Default constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer::Customer() : id(0), firstName(""), lastName("")
{
	transHistory.reserve(5);
}

//---------------------------- Constructor ----------------------------------
// Constructor taking in 1 argument (reading from file)
// Preconditions: data4customers.txt
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer::Customer(istream& readFile)
 {
	setData(readFile);
}

// Copy constructor 
// It copies right side to into this "new customer" side
//----------------------------- Copy Constructor ----------------------------
// Copy Constructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer::Customer(const Customer& rightSide) 
{
	id = rightSide.id;
	firstName = rightSide.firstName;
	lastName = rightSide.lastName;
}
 

Customer::Customer(int ID, string firstN, string lastN) {
	this->id = ID;
	this->firstName = firstN;
	this->lastName = lastN;
}

// Destructor
 
Customer::~Customer() 
{
}


// setData
// Sets the data to customer from reading the file
 
void Customer::setData(istream& readFile)
 {
	//get the id
	readFile >> id;

	if (readFile.eof())
	{
		return;
	}

	//get the lastname
	readFile.get();
	readFile >> lastName;

	//get the firstname
	readFile.get();
	readFile >> firstName;
}

//---------------------------- displayCustomerHistory -----------------------
// Helper function for display()
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Customer::displayCustomerHistory() const
{
	//customer id name lastname
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName
		<< endl;

	int size = transHistory.size();

	if (size > 0)
	{
		//display the transaction history
		for (int i = 0; i < size; i++)
		{
			transHistory[i].display();
		}
		cout << endl;
	}
	else
	{
		//otherwise print out error message
		cout << "No Transaction for this Customer" << endl;
	}
		
	cout << endl;
}


// add transaction 
// Adds a transaction to the customer's history
 
void Customer::addTransaction(Transaction trans)
 {
	transHistory.push_back(trans);
}

void Customer::addMovie(Movie* movie) {
	currentMovies.push_back(movie);
}

void Customer::removeMovie(Movie* movie) {
	currentMovies.erase(remove(currentMovies.begin(), currentMovies.end(), movie), currentMovies.end());
}

bool Customer::checkMovie(Movie* movie) {
	for (int i = 0; i < currentMovies.size(); ++i) {
		if (currentMovies[i] == movie) return true;
	}
	return false;
}
 
//---------------------------- display --------------------------------------
// Displays customer history
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void Customer::display() 
{
	displayCustomerHistory();
}


//all getters 

int Customer::getCustomerID() const { return id; }
string Customer::getFirstName() const { return firstName; }
string Customer::getLastName() const { return lastName; }


// Comparison operator == 
 
bool Customer::operator==(const Customer& rightSide) const 
{
	return (id == rightSide.id);
}


// Comparison operator != 

bool Customer::operator!=(const Customer& rightSide) const
 {
	return (id != rightSide.id);
 }

Customer& Customer::operator=(const Customer& rightSide) {
	this->id = rightSide.id;
	this->firstName = rightSide.firstName;
	this->lastName = rightSide.lastName;
	for (int i = 0; i < transHistory.size(); ++i) {
		transHistory[i] = rightSide.transHistory[i];
	}
	return *this;
}