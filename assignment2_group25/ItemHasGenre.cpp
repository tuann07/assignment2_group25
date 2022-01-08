#include "ItemHasGenre.h"

ItemHasGenre::ItemHasGenre() {}
ItemHasGenre::ItemHasGenre(string id, string title, string rentalType, string loanType, int copies, double rentalFee, string genre) : Item(id, title, rentalType, loanType, copies, rentalFee)
{
    this->genre = genre;
}
// ItemHasGenre::ItemHasGenre(Record &i)
// {
//     this->id = i.getId();
//     this->title = i.getTitle();
//     this->rentalType = i.getRentalType();
//     this->loanType = i.getLoanType();
//     this->copies = i.getCopies();
//     this->rentalFee = i.getRentalFee();
//     this->available = i.getAvailable();
//     this->genre = i.getGenre();
// }
string ItemHasGenre::getGenre()
{
    return genre;
}
void ItemHasGenre::setGenre(string genre)
{
    this->genre = genre;
}