#include "Item.h"

Item::Item() {}
Item::Item(string id, string title, string rentalType, string loanType, int copies, double rentalFee)
{
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->loanType = loanType;
    this->copies = copies;
    this->rentalFee = rentalFee;
    this->available = true;
}
Item::Item(vector<string> info)
{
    // if (!(rental_type == "Record" || rental_type == "DVD" || rental_type == "Game"))
    // {
    //     continue;
    // }
    // // check for loan type
    // if (!(loan_type == "2-day" || loan_type == "1-week"))
    // {
    //     continue;
    // }
    this->id = info[0];
    this->title = info[1];
    this->rentalType = info[2];
    this->loanType = info[3];
    this->copies = stoi(info[4]);
    this->rentalFee = stod(info[5]);
    this->available = true;
}
// Item::Item(Item& i) {
//     this->id = i.getId();
//     this->title = i.getTitle();
//     this->rentalType = i.getRentalType();
//     this->loanType = i.getLoanType();
//     this->copies = i.getCopies();
//     this->rentalFee = i.getRentalFee();
//     this->available = i.getAvailable();
// }

// getters
string Item::getId()
{
    return id;
}
string Item::getTitle()
{
    return title;
}
string Item::getRentalType()
{
    return rentalType;
}
string Item::getLoanType()
{
    return loanType;
}
int Item::getCopies()
{
    return copies;
}
double Item::getRentalFee()
{
    return rentalFee;
}
bool Item::getAvailable()
{
    return available;
}
// setters
void Item::setId(string id)
{
    this->id = id;
}
void Item::setTitle(string title)
{
    this->title = title;
}
void Item::setRentalType(string rentalType)
{
    this->rentalType = rentalType;
}
void Item::setLoanType(string loanType)
{
    this->loanType = loanType;
}
void Item::setCopies(int copies)
{
    this->copies = copies;
}
void Item::setRentalFee(double rentalFee)
{
    this->rentalFee = rentalFee;
}
void Item::setAvailable(bool available)
{
    this->available = available;
}
vector<string> Item::getAll()
{
    vector<string> result;
    result.push_back(this->id);
    result.push_back(this->title);
    result.push_back(this->rentalType);
    result.push_back(this->loanType);
    result.push_back(to_string(this->copies));
    result.push_back(to_string(this->rentalFee));
    return result;
}