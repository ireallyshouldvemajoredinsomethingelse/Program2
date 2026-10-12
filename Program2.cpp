#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
/////////////////////////////////////////
// Name: Tanner Glossner               //
// Assignment #2                       //
// Due: 10/12/26                       //
// Purpose: To create a shopping       //
// inventory, and to find the highest  //
// and average price                   //
/////////////////////////////////////////
//defines the struct, used in the vectors
struct Product
{
	string name;
	int qty = 0;
	double price = 0.0;
};
//Adds product name, its quantity, and its price
void addprod(vector<Product> &bginventory) {
	string name;
	int qty;
	double price;
	Product store;
	cin >> store.name;
	cin >> store.qty;
	cin >> store.price;
	bginventory.push_back(store);
}
// shows the average price by dividing the sum by the inventory size
void showavgprice(vector<Product> &bginventory) {
	string name;
	int qty;
	double price;
	Product store;
	double sum = 0.0;
	int i;
	for (i = 0; i < bginventory.size(); i++) {
		store = bginventory[i];
		sum += store.price;
	}
	cout << "The average price is: " << (sum / bginventory.size());
}
// shows the highest price by checking a certain variable
void showhiprice(vector<Product> &bginventory) {
	int i;
	string name;
	int qty;
	double price;
	double hiPrice = -1.0;
	string hiName;
	//hiPrice is negative so the first item will always be bigger
	Product store;
	for (i = 0; i < bginventory.size(); i++){
		store = bginventory[i];
		if (store.price > hiPrice) {
			hiName = store.name;
			hiPrice = store.price;
		}
	}
	cout << "The highest price is " << hiName << "|" << hiPrice << endl;
}
// shows items which are out of stock by checking if their qty is 0
void showoutofstock(vector<Product> &bginventory){
	int i;
	string name;
	int qty;
	double price;
	Product store;
	for (i = 0; i < bginventory.size(); i++) {
		store = bginventory[i];
		// checks if the quantity is equal to 0
		if (store.qty == 0) {
			cout << store.name << store.price;
		}
	}
}
// prints the current inventory
void showinventory(vector<Product> &bginventory) {
	Product store;
	string name;
	int qty;
	double price;
	int i;
	//Prints the text.
	cout << "##  " << "Name         " << "Qty            " << "Price" << endl;
	cout << "--  " << "----         " << "---            " << "-----" << endl;
	for (i = 0; i < bginventory.size(); i++) {
	// Prints the name, qty and price
		cout << i + 1 << "   " << store.name << "         " << store.qty << "               " << store.price << endl;

	}
}
//Displays the menu.
int menu(int choice) {
	int i;
	string name;
	int qty;
	double price;
	int YourChoice;
	vector<Product> bginventory;
	// Display a menu.
	cout << "1. Add new product\n";
	cout << "2. Average Price\n";
	cout << "3. Highest Price\n";
	cout << "4. Display out of stock\n";
	cout << "5. Display all products in inventory\n";
	cout << "6. Exit the program\n\n";
	// Get the user's choice.
	cout << "Enter your choice: ";
	cin >> YourChoice;
	if (YourChoice > 6 || YourChoice < 1) {
		cout << "Invalid. Please choose a number between 1 and 6." << endl;
	}
	return YourChoice;
}
int main() {
	//Allows user to input their choice in the menu
	int choice = 0;
	choice = menu(0);
	vector<Product> bginventory;
	while (choice != 6) {
		if (choice == 1) {
			addprod(bginventory);
		}
		else if (choice == 2) {
			showavgprice(bginventory);
		}
		else if (choice == 3) {
			showhiprice(bginventory);
		}
		else if (choice == 4) {
			showoutofstock(bginventory);
		}
		else if (choice == 5) {
			showinventory(bginventory);
		}
		//If the user chooses 6, the program terminates
		menu(0);
	}
	return 0;
	}
