#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "Customer.h"

using namespace std;

void team_detail() {
    cout << "" << endl;
    cout << "ASIGNMENT 2 - GROUP 25" << endl;
    cout << "s3825455, s3825455@rmit.edu.vn, Thien An, Nguyen Hoang" << endl;
    cout << "s3893635, s3893635@rmit.edu.vn, Minh Quan, Che" << endl;
    cout << "s3875336, s3875336@rmit.edu.vn, Nam Vinh, Nguyen" << endl;
    cout << "s3817907, s3817907@rmit.edu.vn, Anh Tuan, Nguyen" << endl;
}

void main_menu() {
    cout << "Welcome to Genie's video store" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add a new item, update or delete an existing item" << endl;
    cout << "2. Add new customer or update an existing customer" << endl;
    cout << "3. Promote an existing customer " << endl;
    cout << "4. Rent an item" << endl;
    cout << "5. Return an item" << endl;
    cout << "6. Display all items" << endl;
    cout << "7. Display out-of-stock items" << endl;
    cout << "8. Display all customers" << endl;
    cout << "9. Display group of customers " << endl;
    cout << "10. Search items or customers " << endl;
    cout << "Enter the number or type 'Exit' to quit: ";
}

string lower_input(string input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    return input;
}

bool validate_input(string input) {
    string num[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    int size = num->size();
    input = lower_input(input);
    if (input != "exit") {
        for (int i = 0; i < size; i++) {
            if (input == num[i]) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        return true;
    }
}


int main()
{
    string userInput;
    bool isValid;
    Customer* c1 = new Customer("C001", "Thien An", "RMIT Uni", "123456", 0, "none");

    main_menu();
    cin >> userInput;
    userInput = lower_input(userInput);
    isValid = validate_input(userInput);
    
    while (userInput != "exit" && isValid) {
        main_menu();
        cin >> userInput;
        userInput = lower_input(userInput);
        isValid = validate_input(userInput);
    }

    if (userInput == "exit") {
        team_detail();
        return 0;
    }

    return 0;

    
}

