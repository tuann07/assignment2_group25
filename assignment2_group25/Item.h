#include <string>
#include <iostream>
using namespace std;

class Item {
private:
	string id;
	string name;
	int rentalType;  // 1 = Record, 2 = DVD, 3 = Game
	int loanType;  // 1 = 2-day, 2 = 1-week
	int copies;
	float rentalFee;
	bool available;

public:
	Item(string id, string title, int rentalType, int loanType, int copies, float rentalFee) {
		this->id = id;
		this->title = title;
		this->rentalType = rentalType;
		this->loanType = loanType;
		this->copies = copies;
		this->rentalFee = rentalFee;
		this->available = true;
	}

	~Item() {};
	
	string getId() {
		return id;
	}
	
	string getTitle() {
		return title;
	}

	int getRentalType() {
		return rentalType;
	}

	int getLoanType() {
		return loanType;
	}

	int getCopies() {
		return copies;
	}
 
	float getRentalFee() {
		return rentalFee;
	}

	bool getAvailable() {
		return available;
	}
};

