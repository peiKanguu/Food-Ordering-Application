#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>   // For file operations
#include <sstream>
#include <limits>
#include <map>
#include "User.h"
#include "Restaurant.h"
#include "Order.h"
#include "Delivery.h"
#include "Rider.h"
#include "Colors.h"

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
	vector<User> users;
	vector<Order*> orders;
	vector<Order*> orderHistory;
	vector<Rider> riders;
public:

	vector<Order*> getOrderHistory() {
		return orderHistory;
	}

	// Load users' information from file
	void loadUsers(const string& filename) {
		ifstream inFile(filename);
		string line;
		getline(inFile, line); // Skip header line

		while (getline(inFile, line)) {
			istringstream iss(line);
			string firstName, lastName, fullName, username, password;

			getline(iss, firstName, ',');
			getline(iss, lastName, ',');
			getline(iss, fullName, ',');
			getline(iss, username, ',');
			getline(iss, password, ',');

			users.push_back(User(firstName, lastName, fullName, username, password));
		}
	}

	// Load food items' information from file
	void loadFoodItems(const string& filename, map<string, Food*>& foodMap) {
		ifstream file(filename);
		string line;
		getline(file, line); // Skip header line

		while (getline(file, line)) {
			stringstream ss(line);
			string name, priceStr, preference;
			getline(ss, name, ',');
			getline(ss, priceStr, ',');
			getline(ss, preference, ',');

			double price = stod(priceStr);
			Food* food;
			if (preference == "NULL") {
				food = new NoPreferenceFood(name, price, preference);
			}
			else {
				food = new PreferenceFood(name, price, preference);
			}
			foodMap[name] = food;
		}
	}

	// Load restaurants' information from file
	void loadRestaurants(const string& filename, const map<string, Food*>& foodMap, vector<Restaurant*>& restaurants) {
		ifstream file(filename);
		string line;
		getline(file, line); // Skip header line

		while (getline(file, line)) {
			stringstream ss(line);
			string name, distanceStr, category, foodItem;
			getline(ss, name, ',');
			getline(ss, distanceStr, ',');
			getline(ss, category, ',');

			int distance = stod(distanceStr);
			Restaurant* restaurant;
			if (category == "Chinese") {
				restaurant = new ChineseRestaurant(name, distance);
			}
			else if (category == "Thai") {
				restaurant = new ThaiRestaurant(name, distance);
			}
			else if (category == "Western") {
				restaurant = new WesternRestaurant(name, distance);
			}
			else if (category == "Arabic") {
				restaurant = new ArabicRestaurant(name, distance);
			}
			else if (category == "Japanese") {
				restaurant = new JapaneseRestaurant(name, distance);
			}
			else if (category == "Korean") {
				restaurant = new KoreanRestaurant(name, distance);
			}
			else {
				continue;
			}

			while (getline(ss, foodItem, ',')) {
				auto it = foodMap.find(foodItem);
				if (it != foodMap.end()) {
					restaurant->addFood(it->second);
				}
			}

			restaurants.push_back(restaurant);
		}
	}

	// Load restaurants' information from file
	void loadRiders(const string& filename) {
		ifstream inFile(filename);
		string line;
		getline(inFile, line); // Skip header line

		while (getline(inFile, line)) {
			istringstream iss(line);
			string name, contact, vehicle;

			getline(iss, name, ',');
			getline(iss, contact, ',');
			getline(iss, vehicle, ',');

			riders.push_back(Rider(name, contact, vehicle));
		}
	}

	void loadOrderHistory(const string& filename) {
		ifstream inFile(filename);
		string line;
		getline(inFile, line); // Skip header line

		while (getline(inFile, line)) {
			istringstream iss(line);
			string orderID, restaurantName, specialInstruction, distanceStr, riderName, riderContact, riderVehicle, paymentMethod, deliveryOption, totalPriceStr, foodItems;
			getline(iss, orderID, ',');
			getline(iss, restaurantName, ',');
			getline(iss, specialInstruction, ',');
			getline(iss, distanceStr, ',');
			getline(iss, riderName, ',');
			getline(iss, riderContact, ',');
			getline(iss, riderVehicle, ',');
			getline(iss, paymentMethod, ',');
			getline(iss, deliveryOption, ',');
			getline(iss, totalPriceStr, ',');
			getline(iss, foodItems, ',');

			double distance = stod(distanceStr);
			double totalPrice = stod(totalPriceStr);

			Delivery delivery(distance);
			Rider rider(riderName, riderContact, riderVehicle);
			delivery.assignRider(&rider);

			Order* order = new Order(orderID, restaurantName, delivery, paymentMethod);
			order->setTotalPrice_food(totalPrice);

			istringstream foodStream(foodItems);
			string foodItem;
			while (getline(foodStream, foodItem, ',')) {
				size_t xPos = foodItem.find(" x ");
				size_t pricePos = foodItem.find(" ($");
				size_t prefPos = foodItem.find("),");
				if (xPos != string::npos && pricePos != string::npos && prefPos != string::npos) {
					string foodName = foodItem.substr(0, xPos);
					int quantity = stoi(foodItem.substr(xPos + 3, pricePos - xPos - 3));
					double price = stod(foodItem.substr(pricePos + 3, foodItem.size() - pricePos - 4));
					string preference = foodItem.substr(pricePos + foodItem.substr(pricePos).find(",") + 2, prefPos - pricePos - 1);
					Food* food;
					if (preference == "NULL") {
						food = new NoPreferenceFood(foodName, price, "NULL");
					}
					else {
						food = new PreferenceFood(foodName, price, preference);
					}
					order->addFoodItems(food, quantity);
				}
			}

			orderHistory.push_back(order);
		}
	}

	// Login Function
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
					if (user.getID() == ID) {
						userFound = true;
						if (user.getPassWord() == Password) {
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
								if (user.getPassWord() == Password) {
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
				cin.clear(); // clear error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove invalid input
			}
		}
	}

	// Clear the screen
	void clearScreen() {
#ifdef _WIN32
		system("cls"); // Windows
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear"); // Linux, macOS, Unix
#else
		cerr << "Unsupported platform for clearScreen()" << std::endl;
#endif
	}

	void DetermineDeliveryOption(Delivery& delivery, Order* newOrder) {
		int deliveryOption;
		string option;
		while (true) {
			try {
				cout << YELLOW << "Please select the delivery option: [1] Express [2] Standard [3] Saver" << endl;
				cout << "(Enter numbers)" << endl;
				cout << "=====> ";
				if (!(cin >> deliveryOption)) {
					throw invalid_argument("Invalid input. Please enter a number.");
				}
				cout << RESET;
				if (deliveryOption == 1) {
					option = "Direct";
					break;
				}
				else if (deliveryOption == 2) {
					option = "Standard";
					break;
				}
				else if (deliveryOption == 3) {
					option = "Saver";
					break;
				}
				else {
					throw out_of_range("Invalid delivery option. Please try again.");
				}
				break;
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
			catch (const out_of_range& error) {
				cout << RED << error.what() << RESET << endl;
			}
		}
		delivery.setDeliveryOption(option);
		newOrder->setDelivery(delivery);
	}

	void DeterminePaymentMethod(Order* newOrder) {
		while (true) {
			try {
				cout << YELLOW << "Please select the payment method: [1] Cash [2] Credit Card [3] Debit Card" << endl;
				cout << "(Enter numbers)" << endl;
				cout << "=====> ";
				int paymentMethod;
				if (!(cin >> paymentMethod)) {
					throw invalid_argument("Invalid input. Please enter a number.");
				}

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
					throw out_of_range("Invalid payment method. Please try again.");
				}

				newOrder->setPaymentMethod(method);
				break;
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
			catch (const out_of_range& error) {
				cout << RED << error.what() << RESET << endl;
			}
		}
	}

	void confirmation(Order* newOrder) {
		char confirmationChoice;
		// Input validation loop
		while (true) {
			try {
				cout << "Do you want to confirm the order? (y/n): ";
				if (!(cin >> confirmationChoice)) {
					throw invalid_argument("Invalid input. Please enter 'y' for yes or 'n' for no.");
				}

				// Check for valid input
				if (confirmationChoice == 'y' || confirmationChoice == 'Y' || confirmationChoice == 'n' || confirmationChoice == 'N') {
					clearScreen();
					break;
				}
				else {
					throw invalid_argument("Invalid input. Please enter 'y' for yes or 'n' for no.");
				}
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
		}

		if (confirmationChoice == 'y' || confirmationChoice == 'Y') {
			cout << "Your order has been placed successfully!" << endl;
			cout << "------------------------------------------" << endl;
			cout << "            Order Confirmation            " << endl;
			cout << "------------------------------------------" << endl;
			cout << "\nOrder ID: " << newOrder->getOrderID();
			newOrder->orderSummary();
			cout << "\nDelivery option: " << newOrder->getDelivery().getDeliveryOption() << endl;
			cout << "Payment method: " << newOrder->getPaymentMethod() << endl;
			newOrder->getDelivery().getRider()->display();
			cout << "\nThank you for ordering!" << endl;
			cout << "-----------------------------------------" << endl;
			orders.push_back(newOrder);

			ofstream outFile("OrderHistory.csv", ios::app);
			if (outFile.is_open()) {
				outFile << newOrder->getOrderID() << "," << newOrder->getRestaurantName() << "," << newOrder->getSpecialInstructions() << ","
					<< newOrder->getDelivery().getDistance() << ","
					<< newOrder->getDelivery().getRider()->getName() << "," << newOrder->getDelivery().getRider()->getContact() << "," << newOrder->getDelivery().getRider()->getVehicle() << ","
					<< newOrder->getPaymentMethod() << "," << newOrder->getDelivery().getDeliveryOption() << ","
					<< newOrder->getTotalPrice_food() << ",";
				for (const auto& pair : newOrder->getFoodItemsAndQuantity()) {
					Food* food = pair.first;
					int quantity = pair.second;
					outFile << food->getName() << " x " << quantity << " ($" << fixed << setprecision(2) << food->getPrice() << "),"
						<< food->getPreference() << ",";
				}
				outFile << endl;
				outFile.close();
			}
			else {
				cout << RED << "Error opening file to save order history." << RESET << endl;
			}
		}
		else {
			// 如果用户不确认订单，则清除 newOrder 对象
			delete newOrder;
			newOrder = nullptr;
			cout << RED << "Your order has been canceled." << RESET << endl;
		}
	}

	void newOrder(vector<Restaurant*>& rest) {
		// 1. Select Category First.
		int categoryChoice;
		string category;
		while (true) {
			cout << YELLOW << "Please select Food categories: [1. Western] [2. Arabic] [3. Chinese] [4. Japanese] [5. Korean] [6. Thai]" << endl;
			cout << "(Enter numbers)" << endl;
			cout << "=====> ";
			try {
				// If the input is not an integer, throw an exception
				if (!(cin >> categoryChoice)) {
					throw invalid_argument("Invalid input, please enter a number.");
				}
				cout << RESET;
				if (categoryChoice >= 1 && categoryChoice <= 6) {
					break; // Valid category, exit the loop
				}
				else {
					// Invalid category, throw an exception
					throw out_of_range("Invalid number, please re-enter from 1-6.");
				}
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
			catch (const out_of_range& error) {
				cout << RED << error.what() << RESET << endl;
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

		// Prompt user to select restaurant by index
		int index;
		bool validIndex = false;
		while (!validIndex) {
			cout << "\nEnter the index of the restaurant you want to select: ";
			try {
				if (!(cin >> index)) {
					throw invalid_argument("Invalid input. Please enter a number.");
				}

				// Check if the index is valid
				if (find(matchedIndices.begin(), matchedIndices.end(), index) == matchedIndices.end()) {
					throw out_of_range("Invalid index. Please try again.");
				}
				else {
					validIndex = true;
				}
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
			catch (const out_of_range& error) {
				cout << RED << error.what() << RESET << endl;
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

			try {
				cout << "Choose your " << count << " food:" << endl;
				cout << "\tInput food index: ";
				if (!(cin >> foodIndex)) {
					throw invalid_argument("Invalid input. Please enter a number for the food index.");
				}

				cout << "\tInput food quantity: ";
				if (!(cin >> quantity)) {
					throw invalid_argument("Invalid input. Please enter a number for the food quantity.");
				}

				// Check if foodIndex is within valid range
				const vector<Food*>& items = selectedRestaurant->getItems();
				if (foodIndex < 0 || foodIndex >= items.size()) {
					throw out_of_range("Food index out of range. Please enter a valid index.");
				}

				// Check if the food item needs a preference, and choose one if needed
				if (items.at(foodIndex)->needsPreference()) {
					items.at(foodIndex)->choosePreference();
				}

				newOrder->addFoodItems(items.at(foodIndex), quantity);

				cout << "\tContinue ordering?(Y/N): ";
				cin >> judge;
				count++;

				if (judge != 'Y' && judge != 'y') {
					break;
				}
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
			catch (const out_of_range& error) {
				cout << RED << error.what() << RESET << endl;
			}
		}
		
		string specialInstructions;
		char temp;

		while (true) {
			try {
				cout << "\nAny special instructions for the order? (Y/N): ";
				if (!(cin >> temp)) {
					throw invalid_argument("Invalid input. Please enter 'Y' or 'N'.");
				}

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
					throw invalid_argument("Invalid input. Please enter 'Y' for yes or 'N' for no.");
				}
			}
			catch (const invalid_argument& e) {
				cout << RED << e.what() << RESET << endl;
				cin.clear(); // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			}
		}

		loadRiders("RiderInformation.csv");

		// Randomly select a rider
		int randomIndex = rand() % riders.size();
		Rider* selectedRider = &riders[randomIndex];

		// Assign the randomly selected rider to the delivery
		delivery.assignRider(selectedRider);

		cout << endl;
		DetermineDeliveryOption(delivery, newOrder);

		newOrder->orderSummary();

		cout << endl;
		DeterminePaymentMethod(newOrder);

		confirmation(newOrder);
	}

	void viewOrderHistory() {
		cout << "************ >Order History< ***********" << endl;
		int index = 1;
		for (auto& order : orderHistory) {
			cout << GREEN << "======= > Order " << index++ << RESET << endl;
			cout << "****************************************\n";
			cout << "Order ID: " << order->getOrderID();
			order->orderSummary();
			cout << "\nDelivery option: " << order->getDelivery().getDeliveryOption() << endl;
			cout << "Payment method: " << order->getPaymentMethod() << endl;
			order->getDelivery().getRider()->display();
			cout << "****************************************\n";
			cout << endl << endl;
		}
	}

	void reorder() {
		cout << GREEN << "Reorder" << RESET << endl;
		int index;

		while (true) {
			try {
				cout << "Enter the order index you want to reorder: ";
				if (!(cin >> index)) {
					cin.clear(); // Clear the error flag on cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
					throw invalid_argument("Invalid input. Please enter a number.");
				}

				if (index < 1 || index > orders.size()) {
					throw out_of_range("Invalid order index. Please try again.");
				}

				Order* reOrder = orderHistory[index - 1];
				cout << "Reordering the following order:" << endl;
				reOrder->orderSummary();
				cout << "============================================\n";
				cout << "Order has been successfully reordered!" << endl;
				cout << "============================================\n";
				orders.push_back(reOrder);
				break;
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;
			}
			catch (const out_of_range& error) {
				cout << RED << error.what() << RESET << endl;
			}
		}
	}
};

void printMenu() {
	cout << CYAN;
	cout << "***************************" << endl;
	cout << "*****   >Main Menu<   *****" << endl;
	cout << "***************************" << endl;
	cout << "** 1. Start New Order    **" << endl;
	cout << "** 2. View Order History **" << endl;
	cout << "** 3. Exit Application   **" << endl;
	cout << "***************************" << endl;
	cout << RESET;
}
#endif //SYSTEM_H