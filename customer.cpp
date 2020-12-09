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
// Preconditions: Customer&
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer::Customer(const Customer& rightSide) 
{
	id = rightSide.id;
	firstName = rightSide.firstName;
	lastName = rightSide.lastName;
}
 
//---------------------------- Constructor ----------------------------------
// Constructor taking in 3 arguments
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer::Customer(int ID, string firstN, string lastN) {
	this->id = ID;
	this->firstName = firstN;
	this->lastName = lastN;
}

//---------------------------- Destructor ----------------------------------
// Destructor
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer::~Customer() 
{
}

//---------------------------- setData --------------------------------------
// Sets data of customer read from file (id, first name, last name)
// Preconditions: data4customers.txt
// Postconditions: NONE
// --------------------------------------------------------------------------
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

//---------------------------- addTransaction -------------------------------
// Adds transaction into vector of transactions
// Preconditions: Transaction object
// Postconditions: NONE
// -------------------------------------------------------------------------- 
void Customer::addTransaction(Transaction trans)
 {
	transHistory.push_back(trans);
}

//---------------------------- addMovie -------------------------------------
// Adds movie into vector of movies
// Preconditions: Movie* objects
// Postconditions: NONE
// --------------------------------------------------------------------------
void Customer::addMovie(Movie* movie) {
	currentMovies.push_back(movie);
}

//---------------------------- removeMovie ----------------------------------
// Removes movie from vector of movies
// Preconditions: Movie must exist in vector
// Postconditions: NONE
// --------------------------------------------------------------------------
void Customer::removeMovie(Movie* movie) {
	if (checkMovie(movie) == true)
		currentMovies.erase(remove(currentMovies.begin(), currentMovies.end(), movie), currentMovies.end());
	else cout << "Couldn't remove non-existent movie";
}

//---------------------------- checkMovie -----------------------------------
// Checks to see if movie exists, helper function for removeMovie()
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
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

//---------------------------- Getters --------------------------------------
// Getter functions for ID, first name, last name
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
int Customer::getCustomerID() const { return id; }
string Customer::getFirstName() const { return firstName; }
string Customer::getLastName() const { return lastName; }

//---------------------------- operator== -----------------------------------
// Overloaded operator== to compare ID
// Preconditions: Customer&
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Customer::operator==(const Customer& rightSide) const 
{
	return (id == rightSide.id);
}

//---------------------------- operator!= -----------------------------------
// Overloaded operator!= to compare ID
// Preconditions: Customer&
// Postconditions: NONE
// --------------------------------------------------------------------------
bool Customer::operator!=(const Customer& rightSide) const
 {
	return (id != rightSide.id);
 }

//---------------------------- operator= ------------------------------------
// Overloaded operator= to assign rightSide values into left side
// Preconditions: Customer&
// Postconditions: NONE
// --------------------------------------------------------------------------
Customer& Customer::operator=(const Customer& rightSide) {
	this->id = rightSide.id;
	this->firstName = rightSide.firstName;
	this->lastName = rightSide.lastName;
	for (int i = 0; i < transHistory.size(); ++i) {
		transHistory[i] = rightSide.transHistory[i];
	}
	return *this;
}