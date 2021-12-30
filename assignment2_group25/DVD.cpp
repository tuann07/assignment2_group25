#include "DVD.h"

DVD::DVD() {}
DVD::DVD(string id, string title, int rentalType, int loanType, int copies, float rentalFee, string genre)
{
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->loanType = loanType;
    this->copies = copies;
    this->rentalFee = rentalFee;
    this->available = true;
    this->genre = genre;
}
DVD::DVD(DVD& i) {
    this->id = i.getId();
    this->title = i.getTitle();
    this->rentalType = i.getRentalType();
    this->loanType = i.getLoanType();
    this->copies = i.getCopies();
    this->rentalFee = i.getRentalFee();
    this->available = i.getAvailable();
    this->genre = i.getGenre();
}
string DVD::getGenre() {
    return genre;
}
void DVD::setGenre(string genre) {
    this->genre = genre;
}