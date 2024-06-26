#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "Order.h"
#include "Delivery.h"

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";

class System
{
private:
	vector<User*> users;
	vector<Order*> orders;
public:
	void addUsers(User* user) {
		users.push_back(user);
	}

	// Login Window
	void login() {
		string ID, Password;
		bool loginSuccess = false;

		while (!loginSuccess) {
			cout << "== Login==" << endl;
			cout << "Enter ID: ";
			cin >> ID;
			cout << "Enter password: ";
			cin >> Password;

			bool userFound = false;

			for (auto& user : users) {
				if (user->getID() == ID) {
					userFound = true;
					if (user->getPassWord() == Password) {
						cout << GREEN << "Successful login!" << RESET << endl;
						loginSuccess = true;
					}
					else {
						cout << RED << "Wrong password, please re-enter." << RESET << endl;
						while (!loginSuccess) {
							cout << "== Login==" << endl;
							cout << "Enter ID: " << ID << endl;
							cout << "Enter password: ";
							cin >> Password;
							if (user->getPassWord() == Password) {
								cout << GREEN << "Successful login!" << RESET << endl;
								loginSuccess = true;
							}
							else {
								cout << RED << "Wrong password, please re-enter." << RESET << endl;
							}
						}
					}
					break;
				}
			}

			if (!userFound) {
				cout << RED << "Incorrect ID, please check its accuracy and try again." << RESET << endl;
			}
		}
	}

	// Clear the screen
	void clearScreen()
	{
#ifdef _WIN32
		char* buffer = nullptr;
		size_t requiredSize;

		// Get the value of the WSL_DISTRO_NAME environment variable
		getenv_s(&requiredSize, nullptr, 0, "WSL_DISTRO_NAME");
		if (requiredSize != 0) {
			// Allocate buffer and get the actual value
			buffer = new char[requiredSize];
			getenv_s(&requiredSize, buffer, requiredSize, "WSL_DISTRO_NAME");

			if (buffer && buffer[0] != '\0') {
				system("clear"); // Running in WSL
			}
			else {
				system("cls"); // Running in Windows
			}

			// Clean up
			delete[] buffer;
		}
		else {
			system("cls"); // Running in Windows
		}
#else
		system("clear"); // Running in Linux/MacOS/Unix
#endif
	}

	void newOrder(vector<Restaurant*>& rest) {
		// 1. Select Category First.
		int categoryChoice;
		string category;
		while (true) {
			cout << "Food categories: [1. Western] [2. Arabic] [3. Chinese] [4. Japanese] [5. Korean] [6. Thai]" << endl;
			cout << "Select food category: ";

			if (cin >> categoryChoice) { // Check if input is a number
				if (categoryChoice >= 1 && categoryChoice <= 6) {
					break; // Valid category, exit the loop
				}
				else {
					cout << "Invalid number, please re-enter." << endl;
				}
			}
			else {
				cout << "Invalid input, please enter a number." << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
		}
		switch (categoryChoice) {
		case 1:
			category = "Western";
			break;
		case 2:
			category = "Arabic";
			break;
		case 3:
			category = "Chinese";
			break;
		case 4:
			category = "Japanese";
			break;
		case 5:
			category = "Korean";
			break;
		case 6:
			category = "Thai";
			break;
		}
		
		// 2. Get matched restaurants by catrgory.
		vector<Restaurant*> matchedRestaurants;
		for (auto& restaurant : rest) {
			if (restaurant->getCategory() == category) {
				matchedRestaurants.push_back(restaurant);
			}
		}

		// Print the matched restaurant name.
		if (!matchedRestaurants.empty()) {
			cout << "All available restaurants: [ " << category << " ]" << endl;
			for (size_t i = 0; i < matchedRestaurants.size(); ++i) {
				cout << i << "\t:";
				cout << matchedRestaurants[i]->getName() << endl;
			}
		}

		// Clear the input buffer to ensure proper handling of getline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Prompt user to select vehicles by index
		cout << "Enter the indices of the vehicles you want to select : ";
		int index;
		cin >> index;

		Restaurant* selectedRestaurant = matchedRestaurants[index];
		
		selectedRestaurant->displayMenu();

		// ********
		// a simple
		// ********
		//orders.push_back(new Order("~~~~~~~new~order~~~~~~", selectedRestaurant->getName()));
		Order* newOrder = new Order("~~~~~~~new~order~~~~~~", selectedRestaurant->getName());
		int count = 1;
		while (true) {
			int foodIndex = 0;
			int quantity = 0;
			char judge;
			cout << "Choose your " << count << " food:" << endl;
			cout << "\tInput food index: "; cin >> foodIndex;
			cout << "\tInput food quantity: "; cin >> quantity;
			newOrder->addFoodItems((selectedRestaurant->getItems()).at(foodIndex), quantity);
			cout << "\tContinue ordering?(Y/N): "; cin >> judge;
			count++;
			if (judge != 'Y' && judge != 'y') {
				break;
			}
		}
		cout << "Please select the delivery options: [ Direct ] [ Standard ] [ Saver ]" << endl;
		string options; 
		cin >> options;
		Delivery delivery(selectedRestaurant->getDistance(), options);
		cout << "\n";
		newOrder->orderSummary();
		cout << "The delivery fee is $" << delivery.getDeliveryFee() << endl;
		cout << "\n====> Total amount: $" << delivery.getDeliveryFee() + newOrder->getTotalPrice_food() << endl;

	}
};


void printMenu();

#endif //SYSTEM_H
