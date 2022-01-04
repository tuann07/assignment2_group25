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
    cout << "========================================" << endl;
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

void crud_item() {
    cout << "========================================" << endl;
    cout << "ADD - UPDATE - DELETE ITEM" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add new item" << endl;
    cout << "2. Update an item" << endl;
    cout << "3. Update an item" << endl;
    cout << "Enter the number or type 'Exit' to quit: ";
}

void crud_customer() {
    cout << "========================================" << endl;
    cout << "ADD - UPDATE CUSTOMER" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add new customer" << endl;
    cout << "2. Update a customer" << endl;
    cout << "Enter the number or type 'Exit' to quit: ";
}

void promote_customer() {
    cout << "========================================" << endl;
    cout << "PROMOTE CUSTOMER" << endl;
    cout << "Enter the customer ID or type 'Exit' to quit: ";
}

void rent_item() {
    cout << "========================================" << endl;
    cout << "RENT AN ITEM" << endl;
    cout << "Enter the item ID or type 'Exit' to quit: ";
}

void return_item() {
    cout << "========================================" << endl;
    cout << "RETURN AN ITEM" << endl;
    cout << "Enter the item ID or type 'Exit' to quit: ";
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
        }
        return false;
    }
    else {
        return true;
    }
}


int main()
{
    string userInput;
    string secondUserInput;
    bool isValid;
    Customer* c1 = new Customer("C001", "Thien An", "RMIT Uni", "123456", 0, "none");

    do {
        main_menu();
        cin >> userInput;
        userInput = lower_input(userInput);
        isValid = validate_input(userInput);

       /* if (!isValid) {
            cout << "INVALID OPTION" << endl;
        }*/

        if (userInput == "1") {
            do {
                crud_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);
                cout << secondUserInput << endl;
                
                if (secondUserInput == "1") {}
                if (secondUserInput == "2") {}
                if (secondUserInput == "3") {}



            } while (secondUserInput != "exit");
        }

        if (userInput == "2") {
            do {
                crud_customer();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);
                cout << secondUserInput << endl;

                if (secondUserInput == "1") {}
                if (secondUserInput == "2") {}
            }
            while (secondUserInput != "exit");
        }

        if (userInput == "3") {
            do {
                promote_customer();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "4") {
            do {
                rent_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "5") {
            do {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "6") {
            do {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "7") {
            do {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "8") {
            do {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "9") {
            do {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "10") {
            do {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }











    } while (userInput != "exit");

    if (userInput == "exit") {
        team_detail();
        return 0;
    }

    return 0;

    
}

