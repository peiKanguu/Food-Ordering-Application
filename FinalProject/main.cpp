#include "System.h"
#include "Restaurant.h"

int main() {
	System system;
	map<string, Food*> foodMap;
	vector<Restaurant*> restaurants;

	// Load users' information from file
	system.loadUsers("UsersInformation.csv");

	// Load food items' information from file
	system.loadFoodItems("FoodInformation.txt", foodMap);

	// Load restaurant information from file
	system.loadRestaurants("RestaurantInformation.csv", foodMap, restaurants);

	// Display a default user for teacher to test
	cout << GREEN << "Welcome to the Food Delivery System!"  << endl;
	cout << "Default user for teacher to test:" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~        ID: pk123456" << endl;
	cout << "~~~~~~~  Password: 123456" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << RESET << endl;

	// Login
	//system.login();
	system.clearScreen();

    int choice;

    do {
        printMenu();
        cout << CYAN << "===> Enter your choice: ";
        if (!(cin >> choice)) {
            cout << RESET;
            cout << RED << "Invalid input. Please enter a number." << RESET << endl;
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }
        cout << RESET;

        switch (choice) {
        case 1: {
            system.clearScreen();
            cout << GREEN << "You are taking a new order." << RESET << endl << endl;
            system.newOrder(restaurants);
            break;
        }
        case 2: {
            system.clearScreen();
            if (system.getOrders().empty()) {
                cout << RED << "No previous orders found." << RESET << endl;
                break;
            }
            cout << GREEN << "You are viewing your order history." << RESET << endl << endl;
            system.viewOrderHistory();
            system.reorder();
            break;
        }
        case 3:
            cout << GREEN << "Exiting...\n" << RESET;
            break;
        default:
            cout << RED << "Invalid choice. Try again.\n" << RESET;
        }
    } while (choice != 3);

	return 0;
}