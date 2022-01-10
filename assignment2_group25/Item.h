#pragma once
#include <string>
#include <vector>

using namespace std;

class Item
{
protected:
	string id;
	string title;
	string rentalType;
	string loanType;
	int copies;
	double rentalFee;
	bool available;

public:
	// constructor
	Item();
	Item(string id, string title, string rentalType, string loanType, int copies, double rentalFee);
	Item(vector<string> info);
	// Item(Item &i);
	// Item(Item*&i);
	~Item(){};
	// getters
	string getId();
	string getTitle();
	string getRentalType();
	string getLoanType();
	int getCopies();
	double getRentalFee();
	bool getAvailable();
	virtual vector<string> getAll();
	// setters
	void setId(string id);
	void setTitle(string title);
	void setRentalType(string rentalType);
	void setLoanType(string loanType);
	void setCopies(int copies);
	void setRentalFee(double rentalFee);
	void setAvailable(bool available);
};