#pragma once
#include "Item.h"

using namespace std;

class Record : public Item
{
private:
    string genre;

public:
    // constructor
    Record();
    Record(string id, string title, int rentalType, int loanType, int copies, float rentalFee, string genre);
    Record(Record &i);
    // getters
    string getGenre();
    // setters
    void setGenre(string genre);

};
