// assignment2_group25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
enum TypeOfAccount { GuestAccount, RegularAccount, VipAccount };

class Customer {

private:
	string ID;
	string name;
	string address;
	string phone;
	int rewardPoint;
	TypeOfAccount typeOfAccount;
	string listOfRentals;

public:
	Customer(string a="", string b ="", string c="", string d="", int e = 0, TypeOfAccount f = GuestAccount, string g ="") {
		ID = a;
		name = b;
		address = c;
		phone = d;
		rewardPoint = e;
		typeOfAccount = f;
		listOfRentals = g;

	}





};

int main()
{
	std::cout << "Hello World!\n";
	cout << VipAccount << endl;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
