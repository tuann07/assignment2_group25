#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "Customer.h"
#include "Item.h"
#include "ItemHasGenre.h"

using namespace std;

// DISPLAY FUNCTIONS
void main_menu() // Application main menu
{
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

void crud_item() //interface for CRUD items
{
	cout << "========================================" << endl;
	cout << "ADD - UPDATE - DELETE ITEM" << endl;
	cout << "Enter an option below." << endl;
	cout << "1. Add new item" << endl;
	cout << "2. Update an item" << endl;
	cout << "3. Update an item" << endl;
	cout << "Enter the number or type 'Exit' to quit: ";
}

void crud_customer() //interface for CRUD customers
{
	cout << "========================================" << endl;
	cout << "ADD - UPDATE CUSTOMER" << endl;
	cout << "Enter an option below." << endl;
	cout << "1. Add new customer" << endl;
	cout << "2. Update a customer" << endl;
	cout << "Enter the number or type 'Exit' to quit: ";
}

void promote_customer() // Interface for promote customer
{
	cout << "========================================" << endl;
	cout << "PROMOTE CUSTOMER" << endl;
	cout << "Enter the customer ID or type 'Exit' to quit: ";
}

void rent_item() // Interface to rent item
{
	cout << "========================================" << endl;
	cout << "RENT AN ITEM" << endl;
	cout << "Enter the item ID or type 'Exit' to quit: ";
}

void return_item() // Interface to return item
{
	cout << "========================================" << endl;
	cout << "RETURN AN ITEM" << endl;
	cout << "Enter the item ID or type 'Exit' to quit: ";
}

void display_all_item() // Interface for display all items
{
	cout << "========================================" << endl;
	cout << "DISPLAY ALL ITEMS" << endl;
	cout << "1. Sort by ID" << endl;
	cout << "2. Sort by name" << endl;
	cout << "Enter the option or type 'Exit' to quit: ";
}

void search_items() // Interface for search items
{
	cout << "========================================" << endl;
	cout << "SEARCH ITEMS" << endl;
	cout << "1. Search by ID" << endl;
	cout << "2. Search by name" << endl;
	cout << "Enter the option or type 'Exit' to quit: ";
}

// ULTILITY FUNCTIONS
string lower_input(string input) // Lowercase user's input
{
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	return input;
}

void team_detail() // Display team details
{
	cout << "" << endl;
	cout << "ASIGNMENT 2 - GROUP 25" << endl;
	cout << "s3825455, s3825455@rmit.edu.vn, Thien An, Nguyen Hoang" << endl;
	cout << "s3893635, s3893635@rmit.edu.vn, Minh Quan, Che" << endl;
	cout << "s3875336, s3875336@rmit.edu.vn, Nam Vinh, Nguyen" << endl;
	cout << "s3817907, s3817907@rmit.edu.vn, Anh Tuan, Nguyen" << endl;
}

bool validate_input(string input) // Validate user's input
{
	string num[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	int size = num->size();
	input = lower_input(input);
	if (input != "exit")
	{
		for (int i = 0; i < size; i++)
		{
			if (input == num[i])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}

vector<string> split_string(string s, string delimeter) // Split string
{
	vector<string> result;
	string temp;
	int start = 0;
	int end = s.find(delimeter);
	result.push_back(s.substr(start, end - start));

	while (end != -1)
	{
		start = end + delimeter.size();
		end = s.find(delimeter, start);
		temp = s.substr(start, end - start);
		if (temp.length() == 0)
		{
			continue;
		}
		result.push_back(temp);
	}

	return result;
}

void display_item_info(Item* item) // Display item info
{ 
	cout << item->getId() << " | " << item->getTitle() << " | " << item->getRentalType() << " | "
		<< item->getLoanType() << " | " << item->getCopies() << " | " << item->getRentalFee() << endl;
}

void read_item_file(string filename, vector<Item *> &items)
{
    const int normal_length = 6;
    const int genre_length = 7;

    ifstream myfile;
    myfile.open(filename);

    if (!myfile)
    {
        cerr << "Cannot open file " << filename << endl;
        return;
    }

    string line;
    string delimeter = ",";

    vector<string> splitted;

    while (getline(myfile, line))
    {
        splitted = split_string(line, ",");
        if (splitted.empty())
        {
            continue;
        }
        if (splitted.size() == normal_length || splitted.size() == genre_length)
        {
            items.push_back(new Item(splitted));
        }
    }

    myfile.close();
}

void write_item_file(string filename, const vector<Item *> &items)
{
    ofstream myfile;
    myfile.open(filename);

    if (!myfile)
    {
        cerr << "Cannot open file " << filename << endl;
        return;
    }

    for (int i = 0; i < items.size(); i++)
    {
        vector<string> info = items[i]->getAll();
        int size = info.size();

        for (int j = 0; j < size; j++)
        {
            myfile << info[j] << (j != size - 1 ? "," : "\n");
        }
    }

    myfile.close();
}

void read_customer_file(string filename, vector<Customer *> &customers)
{
    ifstream myfile;
    myfile.open(filename);

    if (!myfile)
    {
        cerr << "Cannot open file " << filename << endl;
        return;
    }

    string line;
    string delimeter = ",";
    int phone, last;

    vector<string> splitted;

    while (getline(myfile, line))
    {
        splitted = split_string(line, ",");
        last = customers.size() - 1;
        if (splitted.empty())
        {
            continue;
        }
        if (splitted[0][0] == 'C')
        {
            customers.push_back(new Customer(splitted));
        }
        else if (splitted[0][0] == 'I')
        {
            customers[last]->addItem(line);
        }
    }

    myfile.close();
}

void write_customer_file(string filename, const vector<Customer *> &customers)
{
    ofstream myfile;
    myfile.open(filename);

    if (!myfile)
    {
        cerr << "Cannot open file " << filename << endl;
        return;
    }

    for (int i = 0; i < customers.size(); i++)
    {
        vector<string> info = customers[i]->getAll();
        int info_size = info.size();
        for (int j = 0; j < info_size; j++)
        {
            myfile << info[j] << (j != info_size - 1 ? "," : "\n");
        }

        vector<string> rentals = customers[i]->getListOfRentals();
        int rentals_size = rentals.size();

        for (int j = 0; j < rentals_size; j++)
        {
            myfile << rentals[j] << endl;
        }
    }

    myfile.close();
}

// FUNCTION 1: CRUD ITEMS

// FUNCTION 2: CRUD CUSTOMERS

// FUNCTION 3: PROMOTE CUSTOMERS

// FUNCTION 4: RENT AN ITEM

// FUNCTION 5: RETURN AN ITEM

// FUNCTION 6: DISPLAY ALL ITEMS
void sort_item_by_name(vector<Item*>& items) // Display items sorted by name
{
	vector<string> itemsName;
	for (int i = 0; i < items.size(); i++) {
		itemsName.push_back((items[i]->getTitle()));
	}
	for (int i = 0; i < itemsName.size(); ++i) {
		// Locate next lowest element (it should be in that position).

		int minPos = i;
		for (int k = i + 1; k < itemsName.size(); ++k) {
			if (itemsName.at(minPos) < itemsName.at(k)) {
				minPos = k;
			}
		}

		// If not already there, swap it with what is there.

		if (i != minPos) {
			string temp = itemsName.at(minPos);
			itemsName.at(minPos) = itemsName.at(i);
			itemsName.at(i) = temp;
		}
	}
	cout << endl;
	cout << "LIST OF ITEMS" << endl;
	cout << "   ID     | TITLE | Rental type | Loan type | Copies | Rental fee" << endl;
	for (int i = itemsName.size() - 1; i >= 0; i--) {
		for (int j = 0; j < items.size(); j++) {
			if (itemsName[i] == items[j]->getTitle()) {
				string available;
				if (items[j]->getAvailable() == 1) {
					available = "Yes";
				}
				else {
					available = "No";

				}
				display_item_info(items[j]);
			}
		}
	}
	cout << endl;
}

// FUNCTION 7: DISPLAY OUT-OF-STOCK ITEMS
void display_out_of_stock_items(vector<Item*>& items) // Display out-of-stock items
{
	cout << endl;
	cout << "LIST OF OUT-OF-STOCK ITEMS" << endl;
	int count = 0;
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getAvailable() == 0) {
			display_item_info(items[i]);
			count += 1;
		}
	}
	if (count == 0) {
		cout << "All of the items are available!" << endl;
	}
	cout << endl;
}

// FUNCTION 8: DISPLAY ALL CUSTOMERS

// FUNCTION 9: DISPLAY GROUP OF CUSTOMERS

// FUNCTION 10: SEARCH ITEM OR CUSTOMER
void search_item(vector<Item*>& items, string param, int type) // Search item by name or ID
{
	param = lower_input(param);
	if (type == 1) {
		cout << endl;
		for (int i = 0; i < items.size(); i++) {
			if (lower_input(items[i]->getId()) == param) {
				display_item_info(items[i]);
			}
		}
		cout << endl;
	}
	else if (type == 2) {
		cout << endl;
		for (int i = 0; i < items.size(); i++) {
			if (lower_input(items[i]->getTitle()) == param) {
				display_item_info(items[i]);
			}
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	//if (argc != 3) {
	//    cerr << "Please provide a file name." << endl;
	//    return 0;
	//}

	string userInput;
	string secondUserInput;
	bool isValid;

	vector<Item*> items;
	read_item_file("item.txt", items);


	do
	{
		main_menu();
		cin >> userInput;
		userInput = lower_input(userInput);
		isValid = validate_input(userInput);

		/* if (!isValid) {
			cout << "INVALID OPTION" << endl;
		}*/

		if (userInput == "1")
		{
			do
			{
				crud_item();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);
				cout << secondUserInput << endl;

				if (secondUserInput == "1")
				{
				}
				if (secondUserInput == "2")
				{
				}
				if (secondUserInput == "3")
				{
				}

			} while (secondUserInput != "exit");
		}

		if (userInput == "2")
		{
			do
			{
				crud_customer();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);
				cout << secondUserInput << endl;

				if (secondUserInput == "1")
				{
				}
				if (secondUserInput == "2")
				{
				}
			} while (secondUserInput != "exit");
		}

		if (userInput == "3")
		{
			do
			{
				promote_customer();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);

			} while (secondUserInput != "exit");
		}

		if (userInput == "4")
		{
			do
			{
				rent_item();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);

			} while (secondUserInput != "exit");
		}

		if (userInput == "5")
		{
			do
			{
				return_item();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);

			} while (secondUserInput != "exit");
		}

		if (userInput == "6")
		{
			do
			{
				display_all_item();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);

				if (secondUserInput == "1") {

				}

				if (secondUserInput == "2") {
					sort_item_by_name(items);
					cout << "Type 'Exit' to return to main menu: ";
					cin >> secondUserInput;
					cout << endl;
					secondUserInput = lower_input(secondUserInput);
					if (secondUserInput != "exit") {
						cout << "Unknown command!" << endl;
					}
					cout << endl;
				}

				if (secondUserInput != "1" && secondUserInput != "1" && secondUserInput != "exit") {
					cout << "Unknown command!" << endl;
				}
				cout << endl;

			} while (secondUserInput != "exit");
		}

		if (userInput == "7")
		{
			display_out_of_stock_items(items);
			do {
				cout << "Type 'Exit' to return to main menu: ";
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);
				if (secondUserInput != "exit") {
					cout << "Unknown command!" << endl;
				}
				cout << endl;
			} while (secondUserInput != "exit");
		}

		if (userInput == "8")
		{
			do
			{

			} while (secondUserInput != "exit");
		}

		if (userInput == "9")
		{
			do
			{

			} while (secondUserInput != "exit");
		}

		if (userInput == "10")
		{
			do
			{
				search_items();
				cin >> secondUserInput;
				secondUserInput = lower_input(secondUserInput);

				if (secondUserInput == "1") {
					cout << "Please enter the item ID: ";
					cin >> secondUserInput;
					search_item(items, secondUserInput, 1);
					do {
						cout << "Type 'Exit' to return to main menu: ";
						cin >> secondUserInput;
						secondUserInput = lower_input(secondUserInput);
						if (secondUserInput != "exit") {
							cout << "Unknown command!" << endl;
						}
						cout << endl;
					} while (secondUserInput != "exit");
				}
				else if (secondUserInput == "2") {
					cout << "Please enter the item name: ";
					cin >> secondUserInput;
					search_item(items, secondUserInput, 2);
					do {
						cout << "Type 'Exit' to return to main menu: ";
						cin >> secondUserInput;
						secondUserInput = lower_input(secondUserInput);
						if (secondUserInput != "exit") {
							cout << "Unknown command!" << endl;
						}
						cout << endl;
					} while (secondUserInput != "exit");
				}
			} while (secondUserInput != "exit");
		}

	} while (userInput != "exit");

	if (userInput == "exit")
	{
		team_detail();
		return 0;
	}

	return 0;
}
