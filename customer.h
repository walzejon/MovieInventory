/*
Cindy Acevedo
CSS 343 
Assignment 4
 
*/


#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "movie.h"    //make sure to name it movie
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"  //make sure to name it transaction
using namespace std;

//from text file
class Customer
{
public:
	//constructor
	Customer();
    //constructor with istream(reading)
	Customer(istream&);
    //copy constructor 
	Customer(const Customer&);
	//First and last Name constructor
	Customer(int ID, string firstN, string lastN);
    // desctructor
	virtual ~Customer();

	void setData(istream& readFile); //set the data
	void displayCustomerHistory(); //display customer history
	void addTransaction(Transaction); //add transaction to specific customer
	virtual void display() const;

	//getters
	int getCustomerID() const;
	string getFirstName() const;
	string getLastName() const;

	//operator overloads for comparison
	virtual bool operator==(const Customer& rightSide) const; 
	virtual bool operator!=(const Customer& rightSide) const; 
	Customer& operator=(const Customer& rightSide);

<<<<<<< HEAD
protected:

=======
private:
>>>>>>> da956d9dad7d842a969b9e48526a86b9f0f2d731
	//id number, first name and last name for customers
	int id;
	string firstName;
	string lastName;
	vector<Transaction> transHistory; //for customer trasaction history
};

#endif