#include "ItemHasGenre.h"

ItemHasGenre::ItemHasGenre() {}
ItemHasGenre::ItemHasGenre(string id, string title, string rentalType, string loanType, int copies, double rentalFee, string genre) : Item(id, title, rentalType, loanType, copies, rentalFee)
{
    this->genre = genre;
}
ItemHasGenre::ItemHasGenre(vector<string> info)
{
    // if (info.size() != 6)
    // {
    //     return;
    // }
    this->id = info[0];
    this->title = info[1];
    this->rentalType = info[2];
    this->loanType = info[3];
    this->copies = stoi(info[4]);
    this->rentalFee = stod(info[5]);
    this->available = true;
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
vector<string> ItemHasGenre::getAll()
{
    vector<string> result;
    result.push_back(this->id);
    result.push_back(this->title);
    result.push_back(this->rentalType);
    result.push_back(this->loanType);
    result.push_back(to_string(this->copies));
    result.push_back(to_string(this->rentalFee));
    result.push_back(this->genre);
    return result;
}