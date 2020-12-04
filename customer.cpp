
/*
Cindy Acevedo
CSS 343 
Assignment 4
*/

#include "customer.h"


// Default contructor

Customer::Customer() : id(-1), firstName(""), lastName("")
{
	tranHistory.reserve(5);
}



// Istream setting data constructor

Customer::Customer(istream& readFile)
 {
	setData(readFile);
}



// Copy constructor 
// It copies right side to into this "new customer" side
 
Customer::Customer(const Customer& rightSide) 
{
	id = rightSide.id;
	firstName = rightSide.firstName;
	lastName = rightSide.lastName;
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


// Customer History display

void Customer::displayCustomerHistory() const 
{
	//customer id name lastname
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName
		<< endl;

	int size = tranHistory.size();

	if (size > 0)
	{
		//display the transaction history
		for (int i = 0; i < size; i++)
		{
			tranHistory[i].display();
			tranHistory[i].getTitle()->display();
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
	tranHistory.push_back(trans);
}


// display (customer history)
 
void Customer::display() const
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

Customer Customer::operator=(const Customer& rightSide) {
	this->id = rightSide.id;
	this->firstName = rightSide.firstName;
	this->lastName = rightSide.lastName;
	for (int i = 0; i < transHistory.size(); ++i) {
		transHistory[i] = rightSide.tranHistory[i];
	}
	return *this;
}