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
        customerTable.insertItem(Customer(ID, firstName, lastName));
    }
}

void Store::addMovieInventory(ifstream &infile)
{
    //-	For comedy movies: F, Stock, Director, Title, Year it released
    //-	For drama movies: D, Stock, Director, Title, Year it released
    //-	For classics movies: C, Stock, Director, Title, Major actor Release date
    string const comedy = "F,";
    string const classic = "C,";
    string const drama = "D,";
    for(;;)
    {
        if(infile.eof()) break;
        string genre;
        infile >> genre;
        if (genre == classic)
        {
            string stock;
            infile >> stock;
            stock = stock.substr(0,stock.length() - 2); //////// make sure this works.
            string director;
            infile >> director;
            string title;
            infile >> title;
            string MARD;
            infile >> MARD;
            Classic* m = new Classic(director, title, MARD);
            //insert movie into respective binTree;
            C.insert(new Classic(director, title, MARD),stoi(stock));

        } // insert classic
        else if (genre == comedy)
        {

        } // insert comedy
        else if (genre == drama)
        {

        } // insert drama
        else{
            cout<<"[ERROR] Genre type: " << genre << " is not available" << endl;
            string nonsense;
            getline(infile, nonsense);
        } // output error for invalid movie type

        //store genre trees in an array? so for(binTree A in arrray) {
        // if(genre == 'F') {add this movie to that binTree}
    }
}


//preorder print
void Store::printMovies(BinTree* A)
{
    A->preorderDisplay(A->getRoot());
}

void Store::doCommands(ifstream &infile)
{
    for(;;)
    {
        if(infile.eof()) break;
        char command;
        infile >> command;
        if (command == 'I') {}//do I maybe commandI(infile) do rest of parsing there
        if (command == 'B') {} //do B
        if (command == 'H') {} //do H
        if (command == 'R') {} // do R
    }
}

