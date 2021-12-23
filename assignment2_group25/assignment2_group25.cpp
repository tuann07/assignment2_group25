#include <iostream>
using namespace std;

void team_detail() {
    cout << "" << endl;
    cout << "ASIGNMENT 2 - GROUP 25" << endl;
    cout << "s3825455, s3825455@rmit.edu.vn, Thien An, Nguyen Hoang" << endl;
    cout << "s3893635, s3893635@rmit.edu.vn, Minh Quan, Che" << endl;
    cout << "s3875336, s3875336@rmit.edu.vn, Nam Vinh, Nguyen" << endl;
    cout << "s3817907, s3817907@rmit.edu.vn, Anh Tuan, Nguyen" << endl;
}
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
    team_detail();
}

