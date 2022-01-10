#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;

class Customer
{
public:
	Customer();
	Customer(const vector<string>& info);
	Customer(string id, string name, string address, int phone, string typeOfAccount);
	~Customer(){};
	string getId();
	string getName();
	string getAddress();
	int getPhone();
	int getNumOfRentals();
	string getTypeOfAccount();
	int getRewardPoints();
	vector<string> getListOfRentals();
	vector<string> getAll();

	void setId(string id);
	void setName(string name);
	void setAddress(string address);
	void setPhone(int phone);
	void setNumOfRentals(int numOfRentals);
	void setTypeOfAccount(string typeOfAccount);
	void setRewardPoints(int rewardPoints);

	void addItem(string itemId);

private:
	string id;
	string name;
	string address;
	int phone;
	int numOfRentals;
	string typeOfAccount;
	vector<string> listOfRentals;
	int rewardPoints;
};
