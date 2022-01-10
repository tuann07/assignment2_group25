#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "Customer.h"
#include "Item.h"
#include "ItemHasGenre.h"

using namespace std;

vector<string> split_string(string s, string delimeter)
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
        result.push_back(temp);
    }

    return result;
}

void team_detail()
{
    cout << "" << endl;
    cout << "ASIGNMENT 2 - GROUP 25" << endl;
    cout << "s3825455, s3825455@rmit.edu.vn, Thien An, Nguyen Hoang" << endl;
    cout << "s3893635, s3893635@rmit.edu.vn, Minh Quan, Che" << endl;
    cout << "s3875336, s3875336@rmit.edu.vn, Nam Vinh, Nguyen" << endl;
    cout << "s3817907, s3817907@rmit.edu.vn, Anh Tuan, Nguyen" << endl;
}

void main_menu()
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

void crud_item()
{
    cout << "========================================" << endl;
    cout << "ADD - UPDATE - DELETE ITEM" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add new item" << endl;
    cout << "2. Update an item" << endl;
    cout << "3. Update an item" << endl;
    cout << "Enter the number or type 'Exit' to quit: ";
}

void crud_customer()
{
    cout << "========================================" << endl;
    cout << "ADD - UPDATE CUSTOMER" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add new customer" << endl;
    cout << "2. Update a customer" << endl;
    cout << "Enter the number or type 'Exit' to quit: ";
}

void promote_customer()
{
    cout << "========================================" << endl;
    cout << "PROMOTE CUSTOMER" << endl;
    cout << "Enter the customer ID or type 'Exit' to quit: ";
}

void rent_item()
{
    cout << "========================================" << endl;
    cout << "RENT AN ITEM" << endl;
    cout << "Enter the item ID or type 'Exit' to quit: ";
}

void return_item()
{
    cout << "========================================" << endl;
    cout << "RETURN AN ITEM" << endl;
    cout << "Enter the item ID or type 'Exit' to quit: ";
}

string lower_input(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        input[i] = tolower(input[i]);
    }
    return input;
}

bool validate_input(string input)
{
    string num[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
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

int main()
{

    string userInput;
    string secondUserInput;
    bool isValid;

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
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "7")
        {
            do
            {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "8")
        {
            do
            {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "9")
        {
            do
            {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

            } while (secondUserInput != "exit");
        }

        if (userInput == "10")
        {
            do
            {
                return_item();
                cin >> secondUserInput;
                secondUserInput = lower_input(secondUserInput);

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
