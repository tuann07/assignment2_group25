#include "Record.h"

Record::Record() {}
Record::Record(string id, string title, int rentalType, int loanType, int copies, float rentalFee, string genre)
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
Record::Record(Record& i) {
    this->id = i.getId();
    this->title = i.getTitle();
    this->rentalType = i.getRentalType();
    this->loanType = i.getLoanType();
    this->copies = i.getCopies();
    this->rentalFee = i.getRentalFee();
    this->available = i.getAvailable();
    this->genre = i.getGenre();
}
string Record::getGenre() {
    return genre;
}
void Record::setGenre(string genre) {
    this->genre = genre;
}