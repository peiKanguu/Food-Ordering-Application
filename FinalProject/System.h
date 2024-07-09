#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <ctime>    // For time()
#include <cstdlib>  // For rand() and srand()
#include "User.h"
#include "Restaurant.h"
#include "Order.h"
#include "Delivery.h"
#include "Rider.h"

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";

class LoginException : public exception {
public:
	explicit LoginException(const string& message) : msg_(message) {}
	virtual const char* what() const noexcept {
		return msg_.c_str();
	}
private:
	string msg_;
};




class System
{
private:
	vector<User*> users;
	vector<Order*> orders;
public:
	void addUsers(User* user) {
		users.push_back(user);
	}

	User* getDefaultUser() {
		return users[0];
	}

	vector<Order*> getOrders() {
		return orders;
	}

	// Login Window
	//void login() {
	//	string ID, Password;
	//	bool loginSuccess = false;

	//	while (!loginSuccess) {
	//		cout << "==============================" << endl;
	//		cout << "=========  >Login<   =========" << endl;
	//		cout << "======  Enter ID: ";
	//		cin >> ID;
	//		cout << "======  Password: ";
	//		cin >> Password;

	//		bool userFound = false;

	//		for (auto& user : users) {
	//			if (user->getID() == ID) {
	//				userFound = true;
	//				if (user->getPassWord() == Password) {
	//					cout << GREEN << "Successful login!" << RESET << endl;
	//					loginSuccess = true;
	//				}
	//				else {
	//					cout << RED << "Wrong password, please re-enter." << RESET << endl;
	//					while (!loginSuccess) {
	//						cout << "==============================" << endl;
	//						cout << "=========  >Login<   =========" << endl;
	//						cout << "======  Enter ID: ";
	//						cin >> ID;
	//						cout << "======  Password: ";
	//						cin >> Password;
	//						if (user->getPassWord() == Password) {
	//							cout << GREEN << "Successful login!" << RESET << endl;
	//							loginSuccess = true;
	//						}
	//						else {
	//							cout << RED << "Wrong password, please re-enter." << RESET << endl << endl;
	//						}
	//					}
	//				}
	//				break;
	//			}
	//		}

	//		if (!userFound) {
	//			cout << RED << "Incorrect ID, please check its accuracy and try again." << RESET << endl << endl;
	//		}
	//	}
	//}

	void login() {
		string ID, Password;
		bool loginSuccess = false;

		while (!loginSuccess) {
			try {
				cout << "==============================" << endl;
				cout << "=========  >Login<   =========" << endl;
				cout << "======  Enter ID: ";
				if (!(cin >> ID)) {
					throw LoginException("Invalid input for ID");
				}
				cout << "======  Password: ";
				if (!(cin >> Password)) {
					throw LoginException("Invalid input for Password");
				}

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
								cout << "==============================" << endl;
								cout << "=========  >Login<   =========" << endl;
								cout << "======  Enter ID: ";
								if (!(cin >> ID)) {
									throw LoginException("Invalid input for ID");
								}
								cout << "======  Password: ";
								if (!(cin >> Password)) {
									throw LoginException("Invalid input for Password");
								}
								if (user->getPassWord() == Password) {
									cout << GREEN << "Successful login!" << RESET << endl;
									loginSuccess = true;
								}
								else {
									cout << RED << "Wrong password, please re-enter." << RESET << endl << endl;
								}
							}
						}
						break;
					}
				}

				if (!userFound) {
					cout << RED << "Incorrect ID, please check its accuracy and try again." << RESET << endl << endl;
				}
			}
			catch (const LoginException& e) {
				cerr << RED << e.what() << RESET << endl;
				cin.clear(); // Çå³ý´íÎó×´Ì¬
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ¶ªÆú´íÎóÊäÈë
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

	void DetermineDeliveryOption(Delivery& delivery, Order* newOrder) {
		cout << YELLOW << "Please select the delivery option: [1] Direct [2] Standard [3] Saver" << endl;
		cout << "(Enter numbers)" << endl;
		cout << "=====> ";
		int deliveryOption;
		cin >> deliveryOption;
		cout << RESET;
		string option;
		if (deliveryOption == 1) {
			option = "Direct";
		}
		else if (deliveryOption == 2) {
			option = "Standard";
		}
		else if (deliveryOption == 3) {
			option = "Saver";
		}
		else {
			cout << RED << "Invalid delivery option. Please try again." << RESET << endl;
			return;
		}
		delivery.setDeliveryOption(option);
		newOrder->setDelivery(delivery);
	}

	void DeterminePaymentMethod(Order* newOrder) {
		cout << YELLOW << "Please select the payment method: [1] Cash [2] Credit Card [3] Debit Card" << endl;
		cout << "(Enter numbers)" << endl;
		cout << "=====> ";
		int paymentMethod;
		cin >> paymentMethod;
		cout << RESET;
		string method;
		if (paymentMethod == 1) {
			method = "Cash";
		}
		else if (paymentMethod == 2) {
			method = "Credit Card";
		}
		else if (paymentMethod == 3) {
			method = "Debit Card";
		}
		else {
			cout << RED << "Invalid payment method. Please try again." << RESET << endl;
			return;
		}
		newOrder->setPaymentMethod(method);
	}

	void confirmation(Order* newOrder) {
		char confirmationChoice;

		// Input validation loop
		while (true) {
			cout << "Do you want to confirm the order? (y/n): ";
			cin >> confirmationChoice;

			// Check for valid input
			if (confirmationChoice == 'y' || confirmationChoice == 'Y' || confirmationChoice == 'n' || confirmationChoice == 'N') {
				clearScreen();
				break;
			}
			else {
				cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
			}
		}

		if (confirmationChoice == 'y' || confirmationChoice == 'Y') {
			cout << "Your order has been placed successfully! Please check." << endl;
			cout << "Order ID: " << newOrder->getOrderID() << endl;
			newOrder->orderSummary();
			cout << "Delivery option: " << newOrder->getDelivery().getDeliveryOption() << endl;
			cout << "Payment method: " << newOrder->getPaymentMethod() << endl;
			newOrder->getDelivery().getRider()->display();
			cout << "\nThank you for ordering!" << endl;
			cout << "--------------------------------------------" << endl;
			orders.push_back(newOrder);
		}
		else {
			// Clear the newOrder object if the user does not confirm the order
			delete newOrder;
			newOrder = nullptr;
			cout << "Your order has been canceled." << endl;
		}
	}

	void newOrder(vector<Restaurant*>& rest) {

		// 1. Select Category First.
		int categoryChoice;
		string category;
		while (true) {
			cout << "Food categories: [1. Western] [2. Arabic] [3. Chinese] [4. Japanese] [5. Korean] [6. Thai]" << endl;
			cout << "Select food category by index: ";

			if (cin >> categoryChoice) { // Check if input is a number
				if (categoryChoice >= 1 && categoryChoice <= 6) {
					break; // Valid category, exit the loop
				}
				else {
					cout << RED << "Invalid number, please re-enter." << RESET << endl;
				}
			}
			else {
				cout << RED << "Invalid input, please enter a number." << RESET << endl;
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

		vector<int> matchedIndices;

		// Print the matched restaurant name.
		if (!matchedRestaurants.empty()) {
			cout << "\n\nAll available restaurants: [ " << category << " ]" << endl;
			for (size_t i = 0; i < matchedRestaurants.size(); ++i) {
				cout << RED << "* " << RESET << i << " : ";
				matchedIndices.push_back(i);
				cout << matchedRestaurants[i]->getName() << endl;
			}
		}

		// Clear the input buffer to ensure proper handling of getline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Prompt user to select vehicles by index
		int index;
		bool validIndex = false;
		while (!validIndex) {
			cout << "\nEnter the indices of the vehicles you want to select : ";
			cin >> index;

			// Check if the index is valid
			if (find(matchedIndices.begin(), matchedIndices.end(), index) == matchedIndices.end()) {
				cout << RED << "Invalid index. Please try again." << RESET << endl;
			}
			else {
				validIndex = true;
			}
		}
		Restaurant* selectedRestaurant = matchedRestaurants[index];

		selectedRestaurant->displayMenu();

		// Seed the random number generator
		srand(static_cast<unsigned int>(time(0)));

		// Create a new orderID
		string newOrderID = "ORD" + to_string(rand() % 100000 + 100000);

		Delivery delivery(selectedRestaurant->getDistance());
		Order* newOrder = new Order(newOrderID, selectedRestaurant->getName(), delivery);
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

		string specialInstructions;
		char temp;

		while (true) {
			cout << "\nAny special instructions for the order? (Y/N): ";
			cin >> temp;

			// Convert temp to uppercase to handle both 'Y' and 'y' or 'N' and 'n'
			temp = toupper(temp);

			if (temp == 'Y') {
				cout << "Enter special instructions: ";
				cin.ignore();
				getline(cin, specialInstructions);
				newOrder->setSpecialInstructions(specialInstructions);
				break;
			}
			else if (temp == 'N') {
				newOrder->setSpecialInstructions("NULL");
				break;
			}
			else {
				cout << RED << "Invalid input. Please enter 'Y' for yes or 'N' for no." << RESET << endl;
			}
		}

		// Creating multiple riders
		vector<Rider> riders = {
			Rider("John Doe", "+1234567890", "Honda Activa"),
			Rider("Jane Smith", "+0987654321", "Yamaha R15"),
			Rider("Alice Johnson", "+1122334455", "Suzuki Access")
		};

		// Randomly select a rider
		int randomIndex = rand() % riders.size();
		Rider* selectedRider = &riders[randomIndex];

		// Assign the randomly selected rider to the delivery
		delivery.assignRider(selectedRider);

		DetermineDeliveryOption(delivery, newOrder);

		newOrder->orderSummary();

		DeterminePaymentMethod(newOrder);

		confirmation(newOrder);
	}

	void viewOrderHistory() {
		cout << "Order History" << endl;
		int index = 1;
		for (auto& order : orders) {
			cout << "=====>Order " << index++ << endl;
			cout << "============================================\n";
			order->orderSummary();
			cout << "============================================\n";
		}
	}

	void reorder() {
		cout << "Reorder" << endl;
		cout << "Enter the order index you want to reorder: ";
		int index;
		cin >> index;
		if (index < 1 || index > orders.size()) {
			cout << RED << "Invalid order index. Please try again." << RESET << endl;
			return;
		}
		Order* reOrder = orders[index - 1];
		cout << "Reordering the following order:" << endl;
		reOrder->orderSummary();
		cout << "============================================\n";
		cout << "Order has been successfully reordered!" << endl;
		cout << "============================================\n";
		orders.push_back(reOrder);
	}
};


void printMenu();

#endif //SYSTEM_H
