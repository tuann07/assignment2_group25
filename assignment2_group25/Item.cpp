#include "Item.h"

Item::Item() {}
Item::Item(string id, string title, int rentalType, int loanType, int copies, float rentalFee)
{
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->loanType = loanType;
    this->copies = copies;
    this->rentalFee = rentalFee;
    this->available = true;
}
Item::Item(Item& i) {
    this->id = i.getId();
    this->title = i.getTitle();
    this->rentalType = i.getRentalType();
    this->loanType = i.getLoanType();
    this->copies = i.getCopies();
    this->rentalFee = i.getRentalFee();
    this->available = i.getAvailable();
}

// getters
string Item::getId()
{
    return id;
}
string Item::getTitle()
{
    return title;
}
int Item::getRentalType()
{
    return rentalType;
}
int Item::getLoanType()
{
    return loanType;
}
int Item::getCopies()
{
    return copies;
}
float Item::getRentalFee()
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
void Item::setRentalType(int rentalType)
{
    this->rentalType = rentalType;
}
void Item::setLoanType(int loanType)
{
    this->loanType = loanType;
}
void Item::setCopies(int copies)
{
    this->copies = copies;
}
void Item::setRentalFee(float rentalFee)
{
    this->rentalFee = rentalFee;
}
void Item::setAvailable(bool available)
{
    this->available = available;
}