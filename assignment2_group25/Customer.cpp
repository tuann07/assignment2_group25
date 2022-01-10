#include "string"
#include "Customer.h"
#include "Item.h"

using namespace std;

Customer::Customer() {}
Customer::Customer(const vector<string>& info)
{
    this->id = info[0];
    this->name = info[1];
    this->address = info[2];
    this->phone = stoi(info[3]);
    this->typeOfAccount = info[5];
    this->numOfRentals = 0;
    this->rewardPoints = 0;
}
Customer::Customer(string id, string name, string address, int phone, string typeOfAccount)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->typeOfAccount = typeOfAccount;
    this->numOfRentals = 0;
    this->rewardPoints = 0;
}

string Customer::getId()
{
    return id;
}
string Customer::getName()
{
    return name;
}
string Customer::getAddress()
{
    return address;
}
int Customer::getPhone()
{
    return phone;
}
int Customer::getNumOfRentals()
{
    return numOfRentals;
}
string Customer::getTypeOfAccount()
{
    return typeOfAccount;
}
int Customer::getRewardPoints()
{
    return rewardPoints;
}
vector<string> Customer::getListOfRentals()
{
    return listOfRentals;
}
vector<string> Customer::getAll()
{
    vector<string> result;
    result.push_back(this->id);
    result.push_back(this->name);
    result.push_back(this->address);
    result.push_back(to_string(this->phone));
    result.push_back(to_string(this->numOfRentals));
    result.push_back(this->typeOfAccount);
    return result;
}
void Customer::setId(string id)
{
    this->id = id;
}
void Customer::setName(string name)
{
    this->name = name;
}
void Customer::setAddress(string address)
{
    this->address = address;
}
void Customer::setPhone(int phone)
{
    this->phone = phone;
}
void Customer::setNumOfRentals(int numOfRentals)
{
    this->numOfRentals = numOfRentals;
}
void Customer::setTypeOfAccount(string typeOfAccount)
{
    this->typeOfAccount = typeOfAccount;
}
void Customer::setRewardPoints(int rewardPoints)
{
    this->rewardPoints = rewardPoints;
}
void Customer::addItem(string itemId) {
    listOfRentals.push_back(itemId);
    numOfRentals++;
}