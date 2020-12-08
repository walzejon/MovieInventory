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
            C.insert(m,stoi(stock));

        } // insert classic
        else if (genre == comedy)
        {
            string stock;
            infile >> stock;
            stock = stock.substr(0,stock.length() - 2); //////// make sure this works.
            string director;
            infile >> director;
            string title;
            infile >> title;
            int releaseDate;
            infile >> releaseDate;
            Comedy* m = new Comedy(director, title, releaseDate);
            //insert movie into respective binTree;
            F.insert(m,stoi(stock));
        } // insert comedy
        else if (genre == drama)
        {
            string stock;
            infile >> stock;
            stock = stock.substr(0,stock.length() - 2); //////// make sure this works.
            string director;
            infile >> director;
            string title;
            infile >> title;
            int releaseDate;
            infile >> releaseDate;
            Drama* m = new Drama(director, title, releaseDate);
            //insert movie into respective binTree;
            D.insert(m,stoi(stock));
        } // insert drama
        else{
            cout<<"[ERROR] Genre type: " << genre << " is not available" << endl;
            string nonsense;
            getline(infile, nonsense);
        } // output error for invalid movie type
    }
}


//preorder print
void Store::showStock() const
{
    F.preorderDisplay();
    D.preorderDisplay();
    C.preorderDisplay();
}
/////ADD correct errors
void Store::doCommands(ifstream &infile)
{
    for(;;)
    {
        if(infile.eof()) break;
        char command;
        infile >> command;
        if (command == 'I') {showStock();}
        else if (command == 'B')
        {
            int ID;
            infile >> ID;
            //Get customer from customer Table
            Customer thisCust = customerTable.get(ID);
            if(thisCust.getCustomerID() == -1) {} ////INVALID CUSTOMER ERROR
            char mediaFormat;
            infile >> mediaFormat;
            //Check to see if media format is correct
            if(mediaFormat != 'D') {} ////INVALID MEDIA FORMAT ERROR
            char movieGenre;
            infile >> movieGenre;
            if (movieGenre != 'D' && movieGenre != 'C' && movieGenre != 'F') {} ////INVALID GENRE ERROR
            string movieData;
            getline(infile, movieData);
            borrowMovie(movieGenre, movieData);

        }
        else if (command == 'H') {} //do H
        else if (command == 'R') {} // do R
        else{
            //invalid action code
        }
    }
}

//maybe just for testing.
void Store::printMoviesSideways(BinTree *A) const
{
    A->displaySideways();
}

void Store::borrowMovie(char movieGenre, string movieData)
{
    if(movieGenre == 'D' || movieGenre == 'F')
    {
        //parse data and borrow movie
    } else if (movieGenre == 'C')
    {
        //parse data and borrow movie
    }
}