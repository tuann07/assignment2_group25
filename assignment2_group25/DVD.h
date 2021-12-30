#pragma once
#include "Item.h"

using namespace std;

class DVD : public Item
{
private:
    string genre;

public:
    // constructor
    DVD();
    DVD(string id, string title, int rentalType, int loanType, int copies, float rentalFee, string genre);
    DVD(DVD &i);
    // getters
    string getGenre();
    // setters
    void setGenre(string genre);

};
