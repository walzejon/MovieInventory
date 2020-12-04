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
	Customer(int ID, string& firstN, string& lastN);
    // desctructor
	virtual ~Customer();

	void setData(istream& readFile); //set the data
	void displayCustomerHistory() const; //display customer history
	void addTransaction(Transaction); //add transaction to specific customer
	virtual void display() const;

	//getters
	int getCustomerID() const;
	string getFirstName() const;
	string getLastName() const;

	//operator overloads for comparison
	virtual bool operator==(const Customer& rightSide) const; 
	virtual bool operator!=(const Customer& rightSide) const; 
	virtual Customer& operator=(const Customer& rightSide);

private:

	//id number, first name and last name for customers
	int id;
	string firstName;
	string lastName;
	vector<Transaction> tranHistory; //for customer trasaction history
};

#endif
