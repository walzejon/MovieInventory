//
// Created by stlp on 11/25/20.
//

#ifndef MOVIEINVENTORY_STORE_H
#define MOVIEINVENTORY_STORE_H


class store {
public:
    Store();
    ~Store();
    addCustomers(&infile);
    addMovieInventory(&infile);
    doCommands(&infile);
    newMovie.stock();
    printCustomers();
    printHistory();
    printMovies();

private:
    HashTable<int ID, Customer cust>;
    BinTree movieTree;
    Vector<transaction> transHistory;
};


#endif //MOVIEINVENTORY_STORE_H
