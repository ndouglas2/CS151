/*Programming Chellenge 15- Struct to binary file
* Author: Nate Douglas
* Module: 9
* Project: 2
* Problem Statement: Create a struct that is written to a file, with user functionality 
* Algorithm:
* 1. Declare a struct named Inventory, in it are 4 instance variables for item name, date added, quantity, wholesale cost and retail cost
* 2. The struct also contains one constructor for all of the variables.
* 3. In Main, create a vector of Inventory objects to pre-populate the file with.
* 4. remove any previous versions of Inventory.dat, and open it for output
* 5. Use a for loop to push the vector to the file and close it. 
* 6. In a do while loop, create a menu for the user to choose between displaying all items, just one, adding an item, changing an item, or quitting.
* 7. At the top of the loop, push the vector to the file in order to save the changes every time.
* 8. Showing all loops through the file and uses showItem to display them.
* 9. Show one asks the user for a record number and uses showItem to display it.
* 10. Add new prompts the user for each bit of information and then creates a new Inventory object with it.
* 11. Change finds the right object in the vector, prompts the user for input, deletes the old version and pushes the new changes.
* 12. Quit uses the same outfile loop that is used in other spots to ensure that the file is updated before quitting.
* 13.. Finally, at the bottom of the program declare a function called showItem that simply formats the output for showing an entry or entries in the file.
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

const int DATE_SIZE = 10; //  dd/mm/yyyy
const int ITEM_SIZE = 20; //size of item name

struct Inventory {
    char item_description[ITEM_SIZE], date_added[DATE_SIZE];
    int quantity;
    double wholesale_cost, retail_cost;

    //Constructor 
    Inventory(string item = "N/A", string date = "00/00/0000", int q = 1, double wholeCost = 0.00, double retailCost = 0.00) {
        strcpy(item_description, item.c_str());
        strcpy(date_added, date.c_str());
        quantity = q;
        wholesale_cost = wholeCost;
        retail_cost = retailCost;
    }

};

void showItem(fstream&, int);

int main()
{
    //Vector of Inventory items
    string itemName;
    string date;
    int quantity;
    double wholePrice;
    double retailPrice;
    vector<Inventory> items;
    items.push_back(Inventory("Blueberries", "04/13/2021", 12, 2.75, 4.00));
    items.push_back(Inventory("Strawberries", "04/13/2021", 5, 1.50, 3.75));

    //Logic for creating a new binary file, and writing the vector of items to it
    fstream binaryio;
    remove("Inventory.dat");
    binaryio.open("Inventory.dat", ios::binary | ios::out);
    for (int i = 0; i < items.size(); i++) {
        binaryio.write(reinterpret_cast<char*>(&items[i]), sizeof(Inventory));
    }
    binaryio.close();

    int choice = 0;
    //Menu Logic
    do {
        //Pushes changes to file each time the loop is run
        binaryio.close();
        binaryio.open("Inventory.dat", ios::binary | ios::out);
        for (int i = 0; i < items.size(); i++) {
            binaryio.write(reinterpret_cast<char*>(&items[i]), sizeof(Inventory));
        }
        binaryio.close();
        binaryio.open("Inventory.dat", ios::binary | ios::in);
        cout << "Welcome to inventory manager 2.0" << endl;
        cout << "How can I help you today?" << endl << endl;
        cout << "1. Display all records." << endl
            << "2. Display a specific record." << endl
            << "3. Add a new record." << endl
            << "4. Change a record." << endl
            << "5. Quit" << endl;
        cin >> choice;

        switch (choice) {
        case 1://Display All
            cout << "Current Inventory: " << endl;
            for (int j = 0; j < items.size(); j++) {
                showItem(binaryio, j);
            }
            cout << "Enter 0 to return to main menu.";
            cin>>choice;
            break;
        case 2://Display Specific record
            int record;
            cout << "Please enter the record number you wish to view: ";
            cin >> record;
            showItem(binaryio, record);
            cout << "Enter 0 to return to main menu.";
            cin >> choice;
            break;
        case 3://Add new
            cout << "Please enter your record information now: " << endl;
            cout << "Item name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, itemName);
            cout << "Date added: ";
            cin >> date;
            cout << "Quantity: ";
            cin >> quantity;
            cout << "Wholesale price: ";
            cin >> wholePrice;
            cout << "Retail price: ";
            cin >> retailPrice;

            items.push_back(Inventory(itemName, date, quantity, wholePrice, retailPrice));
            cout << "Item added. Enter 0 to return to main menu";
            cin >> choice;
            break;
        case 4://Change record
            cout << "What record # would you like to change? ";
            cin >> record;

            showItem(binaryio, record);

            cout << "Please enter the new record information now: " << endl;
            cout << "Item name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, itemName);
            cout << "Date added: ";
            cin >> date;
            cout << "Quantity: ";
            cin >> quantity;
            cout << "Wholesale price: ";
            cin >> wholePrice;
            cout << "Retail price: ";
            cin >> retailPrice;

            items.erase(items.begin() + record);
            items.insert(items.begin() + record, Inventory(itemName, date, quantity, wholePrice, retailPrice));

            cout << "Item changed. Enter 0 to return to main menu.";
            cin >> choice;
            break;
        case 5://Exit 
            //Closes the file for input, and pushes changes to the file.
            binaryio.close();
            remove("Inventory.dat");
            binaryio.open("Inventory.dat", ios::binary | ios::out);
            for (int i = 0; i < items.size(); i++) {
                binaryio.write(reinterpret_cast<char*>(&items[i]), sizeof(Inventory));
            }
        default:
            cout << "That is not a valid entry."<<endl;
            break;
        }

    } while (choice != 5);

    binaryio.close();


}

//Function for printing the items
void showItem(fstream& io_stream, int index) {
    Inventory item;
    long position = index * sizeof(Inventory);
    io_stream.clear();
    io_stream.seekg(position, ios::beg);
    io_stream.read(reinterpret_cast<char*>(&item), sizeof(Inventory));
    cout << "Item #" << index + 1 << setprecision(2) << fixed
        << " Item Name: " << left << setw(ITEM_SIZE) << item.item_description
        << " Date Added: " << setw(15) << item.date_added
        << " Quantity: " << setw(7) << item.quantity
        << " Wholesale Cost: $" << setw(7) <<item.wholesale_cost
        << " Retail Cost: $" << setw(7) << item.retail_cost << endl << endl;
}