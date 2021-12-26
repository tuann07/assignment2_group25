#pragma once
#include <string>
#include <iostream>
using namespace std;

enum TypeOfAccount { GuestAccount, RegularAccount, VipAccount };

class Customer {

public:
	Customer(string id, string name, string address, string phone, int point, string rental_list, TypeOfAccount type = GuestAccount) {
		this->id = id;
		this->name = name;
		this->address = address;
		this->phone = phone;
		this->rewardPoint = point;
		this->listOfRentals = rental_list;
		this->typeOfAccount = type;
	}

	~Customer() {};
	
	string getId() {
		return id;
	}
	
	string getName() {
		return name;
	}

	string getAddress() {
		return address;
	}

	string getPhone() {
		return phone;
	}

	int getRewardPoint() {
		return rewardPoint;
	}
 
	TypeOfAccount getType() {
		return typeOfAccount;
	}

private:
	string id;
	string name;
	string address;
	string phone;
	int rewardPoint;
	TypeOfAccount typeOfAccount;
	string listOfRentals;
};

