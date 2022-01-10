#pragma once
#include "Item.h"

using namespace std;

class ItemHasGenre : public Item
{
private:
    string genre;

public:
    // constructor
    ItemHasGenre();
    ItemHasGenre(string id, string title, string rentalType, string loanType, int copies, double rentalFee, string genre);
    ItemHasGenre(vector<string> info);
    // Record(Record &i);
    ~ItemHasGenre(){};
    // getters
    string getGenre();
    vector<string> getAll();
    // setters
    void setGenre(string genre);
};
