#pragma once
#include <string>

using namespace std;

class Item
{
protected:
	string id;
	string title;
	int rentalType; // 1 = Record, 2 = DVD, 3 = Game
	int loanType;	// 1 = 2-day, 2 = 1-week
	int copies;
	float rentalFee;
	bool available;

public:
	// constructor
	Item();
	Item(string id, string title, int rentalType, int loanType, int copies, float rentalFee);
	Item(Item &i);
	// getters
	string getId();
	string getTitle();
	int getRentalType();
	int getLoanType();
	int getCopies();
	float getRentalFee();
	bool getAvailable();
	// setters
	void setId(string id);
	void setTitle(string title);
	void setRentalType(int rentalType);
	void setLoanType(int loanType);
	void setCopies(int copies);
	void setRentalFee(float rentalFee);
	void setAvailable(bool available);
};