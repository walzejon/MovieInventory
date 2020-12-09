//
// Created by stlp on 11/28/20.
//
#include "store.h"

#include <iostream>
#include <fstream>

using namespace std;

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
    for(;;) {
        if (infile.eof()) break;
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
            getline(infile, stock, ',');
            //stock = stock.substr(0,stock.length() - 2); //////// make sure this works.
            string director;
            getline(infile, director, ',');
            string title;
            getline(infile, title, ',');
            string MARD;
            getline(infile, MARD);
            Classic* m = new Classic(director, title, MARD);
            m->setFormat("C");
            m->setCurrentStock(stoi(stock));
            //insert movie into respective binTree;
            C.insert(m,stoi(stock));

        } // insert classic
        else if (genre == comedy)
        {
            string stock;
            getline(infile, stock, ',');
            //stock = stock.substr(0,stock.length() - 2); //////// make sure this works.
            string director;
            getline(infile, director, ',');
            string title;
            getline(infile, title, ',');
            int releaseDate;
            infile >> releaseDate;
            Comedy* m = new Comedy(director, title, releaseDate);
            m->setFormat("F");
            m->setCurrentStock(stoi(stock));
            //insert movie into respective binTree;
            F.insert(m,stoi(stock));
        } // insert comedy
        else if (genre == drama)
        {
            string stock;
            getline(infile, stock, ',');
            //stock = stock.substr(0,stock.length() - 2); //////// make sure this works.
            string director;
            getline(infile, director, ',');
            string title;
            getline(infile, director, ',');
            int releaseDate;
            infile >> releaseDate;
            Drama* m = new Drama(director, title, releaseDate);
            m->setFormat("D");
            m->setCurrentStock(stoi(stock));
            //insert movie into respective binTree;
            D.insert(m,stoi(stock));
        } // insert drama
        else {
            if (genre[0]) cout << "[ERROR] Genre type: " << genre <<
                " is not available" << endl;
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
        if (command == 'I') {showStock();} //Show inventory
        else if (command == 'B'|| command == 'R') //Going to borrow or return movie
        {
            int ID;
            infile >> ID;
            //Get customer from customer Table
            Customer* thisCust = customerTable.get(ID);

            if(thisCust->getCustomerID() == -1)
            { ////INVALID CUSTOMER ERROR
                cout << "[ERROR] Invalid Customer: " << ID << endl;
                continue;
            }
            char mediaFormat;
            infile >> mediaFormat;

            //Check to see if media format is correct
            if(mediaFormat != 'D')
            {////INVALID MEDIA FORMAT ERROR
                cout << "[ERROR] INVALID MEDIA FORM4AT: " << mediaFormat << endl;
                continue;
            }

            char movieGenre;
            infile >> movieGenre;

            if (movieGenre != 'D' && movieGenre != 'C' && movieGenre != 'F')
            {////INVALID GENRE ERROR
                cout << "[ERROR] INVALID GENRE: " << movieGenre << endl;
                continue;
            }
            if(command == 'B') borrowMovie(thisCust, movieGenre, infile);
            else if (command == 'R') returnMovie(thisCust, movieGenre, infile);
        }
        else if (command == 'H') // Show history of customer
        {
            int id;
            infile >> id;
            Customer* custy = customerTable.get(id);
            custy->display();

        }
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

void Store::borrowMovie(Customer* borrower, char movieGenre, ifstream& infile)
{
    cout << "Borrowing " << movieGenre << endl;
    switch (movieGenre) 
    {
        case 'D': {
            Borrow* bor = new Borrow();
            
            string director, title;    
            infile >> director;        
            infile >> title;           
            Drama* dummy = new Drama(director, title, NULL);
            Movie* result;
            if (D.retrieve(dummy, result) == true) {
                bor->borrowMovie("D", result, borrower);
            }
            delete dummy;
            break;
        }
        case 'F': {
            Borrow* bor = new Borrow();

            string director, year;
            getline(infile, director, ',');
            getline(infile, year, ',');
            cout<<"Director"<<director << "..Year"<<year<<endl;
            Comedy* dummy = new Comedy();
            dummy->setDirector(director);
            dummy->setYearReleased(stoi(year));
            Movie* result;
            if (F.retrieve(dummy, result)) {
                cout << result->getStockOwned() << " " << result->getStockDifference() << endl;
                bor->borrowMovie("D", result, borrower);
            }
            //delete dummy;
            break;
        }
        case 'C': {
            Borrow* bor = new Borrow();

            string director, title;
            infile >> director;
            infile >> title;
            Classic* dummy = new Classic(director, title, NULL);
            Movie* result;
            if (C.retrieve(dummy, result) == true) {
                bor->borrowMovie("D", result, borrower);
            }
            delete dummy;
            break;
        }
        default: {
            cout << "Invalid genre";
            break;
        }
    }
}

void Store::returnMovie(Customer* cust, char movieGenre, ifstream &infile)
{
    switch (movieGenre)
    {
        case 'D': {
            Return* re = new Return();

            string director, title;
            infile >> director;
            infile >> title;
            Drama* dummy = new Drama(director, title, NULL);
            Movie* result;
            if (D.retrieve(dummy, result) == true) {
                re->returnMovie("D", result, cust);
            }
            else cout << "Couldn't retrieve Drama movie" << endl;
            delete dummy;
            break;
        }
        case 'F': {
            Return* re = new Return();

            string director, title;
            infile >> director;
            infile >> title;
            Comedy* dummy = new Comedy(director, title, NULL);
            Movie* result;
            if (F.retrieve(dummy, result) == true) {
                re->returnMovie("D", result, cust);
            }
            else cout << "Couldn't retrieve Comedy movie" << endl;
            delete dummy;
            break;
        }
        case 'C': {
            Return* re = new Return();

            string director, title;
            infile >> director;
            infile >> title;
            Classic* dummy = new Classic(director, title, NULL);
            Movie* result;
            if (C.retrieve(dummy, result) == true) {
                re->returnMovie("D", result, cust);
            }
            else cout << "Couldn't retrieve Classic movie" << endl;
            delete dummy;
            break;
        }
        default: {
            cout << "Invalid genre";
            break;
        }
    }
}
//runs the program 

int main() {
    Store* myStore = new Store();

    ifstream commands, customers, movies;
    movies = ifstream("C:/Users/shado/Documents/MovieInventory/data4movies.txt");
    if (!movies) {
        cout << "Movies data file not found!" << endl;
        return 1;
    }
    customers = ifstream("C:/Users/shado/Documents/MovieInventory/data4customers.txt");
    if (!customers) {
        cout << "Customer data file not found!" << endl;
        return 1;
    }
    commands = ifstream("C:/Users/shado/Documents/MovieInventory/data4commands.txt");
    if (!commands) {
        cout << "Commands data file not found!" << endl;
        return 1;
    }
    myStore->addMovieInventory(movies);
    //myStore->showStock();
    myStore->addCustomers(customers);
    myStore->doCommands(commands);
    return 0;
}