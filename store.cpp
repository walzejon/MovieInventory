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
        //HashTable.insertItem(ID,Customer(ID,fistName,lastName));
    }
}

void Store::addMovieInventory(ifstream &infile)
{
    //-	For comedy movies: F, Stock, Director, Title, Year it released
    //-	For drama movies: D, Stock, Director, Title, Year it released
    //-	For classics movies: C, Stock, Director, Title, Major actor Release date
    char const comedy = 'F';
    char const classic = 'C';
    char const drama = 'D';
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

//Store
void Store::printHelp(Node* root)
{
    if(root != nullptr)
    {
        cout<<root<<endl;
        printHelp(root->left);
        printHelp(root->right);
    }
}

//preorder print
void Store::printMovies(BinTree* A)
{
    printHelp(A->root);
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

