//
// Created by stlp on 11/28/20.
//
#include "store.h"

Store::Store()
{
    //initialize HashTable
    //initialize bintree
    //initialize transactionHisory
}

void Store::addCustomers(ifstream &infile)
{
    //Assume data is set in format below
    // int CustomerID String firstName String lastName
    // EX 3333 Witch Wicked
    int ID;
    string firstName;
    string lastName;
    for(;;)
    {
        if(infile.eof()) break;
        infile >> ID;
        infile >> firstName;
        infile >> lastName;
        //HashTable.add(ID,Customer(fistName,lastName);    - should i parse files here or let customer constructor do that?
    }
}

void Store::addMovieInventory(ifstream &infile)
{
    //-	For comedy movies: F, Stock, Director, Title, Year it released
    //-	For drama movies: D, Stock, Director, Title, Year it released
    //-	For classics movies: C, Stock, Director, Title, Major actor Release date
    for(;;)
    {
        if(infile.eof()) break;
        char genre;
        infile >> genre;
        //if(we have no tree for genre) skip whole line and keep going OR add a new binTree with this genre?
        //store genre trees in an array? so for(binTree A in arrray) {
        // if(genre == A) {add this movie to that binTree}
    }
}

