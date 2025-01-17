#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>  
#include <sstream>
#include <limits>
#include <chrono>
#include <map>
#include "User.h"
#include "Restaurant.h"
#include "Order.h"
#include "Delivery.h"
#include "Rider.h"
#include "Colors.h"

// Custom exception class for login-related errors
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

	vector<Order*> getHistoryOrder() {
		return orderHistory;
	}

	// generate a random order ID
	string generateOrderID() {
		// Seed the random number generator with current time including milliseconds
		srand(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));

		// Create a new orderID
		return "ORD" + to_string(rand() % 10000000 + 10000000);
	}

	// Get a random rider
	Rider* getRider() {
		// Seed the random number generator with current time including milliseconds
		srand(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));

		// Randomly select a rider
		int randomIndex = rand() % riders.size();
		return &riders[randomIndex];
	}

	// Load users' information from file
	void loadUsers(const string& filename) {
		ifstream inFile(filename);
		if (!inFile.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return;
		}
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
		if (!file.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return;
		}
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
		if (!file.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return;
		}
		string line;
		getline(file, line); // Skip header line

		while (getline(file, line)) {
			if (line.empty()) break; // Stop if the line is empty

			stringstream ss(line);
			string name, distanceStr, category, foodItem;
			getline(ss, name, ',');
			getline(ss, distanceStr, ',');
			getline(ss, category, ',');

			// Convert distance to integer
			int distance=0;
			try {
				distance = stoi(distanceStr);
			}
			catch (const invalid_argument&) {
				cerr << "Invalid distance: " << distanceStr << " for restaurant: " << name << endl;
				continue;
			}
			catch (const out_of_range&) {
				cerr << "Distance out of range: " << distanceStr << " for restaurant: " << name << endl;
				continue;
			}

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
		if (!inFile.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return;
		}
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

	// Load order history from file
	void loadOrderHistory(const string& filename, map<string, Food*>& foodMap) {
		ifstream inFile(filename);
		if (!inFile.is_open()) {
			cerr << "Error opening file: orderHistory.txt" << endl;
			return;
		}

		// Clear the order history vector
		orderHistory.clear();

		string line;
		while (getline(inFile, line)) {
			if (line.empty()) {
				continue; // Skip empty lines (used to separate orders)
			}

			istringstream iss(line);
			string orderID, restaurantName, distanceStr, deliveryOption, paymentMethod, specialInstructions;
			int distance;

			// Read the header line
			getline(iss, orderID, ',');
			getline(iss, restaurantName, ',');
			getline(iss, distanceStr, ',');
			distance= stoi(distanceStr);
			getline(iss, deliveryOption, ',');
			getline(iss, paymentMethod, ',');
			getline(iss, specialInstructions);

			Delivery delivery(distance);
			delivery.setDeliveryOption(deliveryOption);

			Order* newOrder = new Order(orderID, restaurantName, delivery, paymentMethod);
			newOrder->setSpecialInstructions(specialInstructions);

			// Read food items
			while (getline(inFile, line) && !line.empty()) {
				istringstream foodIss(line);
				string foodName, quantityStr, preference, priceStr;
				int quantity;
				double price;

				getline(foodIss, foodName, ',');
				getline(foodIss, quantityStr, ',');
				quantity = stoi(quantityStr);
				getline(foodIss, preference, ',');
				getline(foodIss, priceStr);
				price = stod(priceStr);

				// Create a Food object or look it up from a map if already created
				Food* foodItem = nullptr;
				auto it = foodMap.find(foodName);
				if (it != foodMap.end()) {
					foodItem = it->second;
				}
				else {
					if(preference == "NULL"){
						foodItem = new NoPreferenceFood(foodName, price, preference);
					}
					else {
						foodItem = new PreferenceFood(foodName, price, preference);
					}
					foodMap[foodName] = foodItem;
				}

				if (foodItem->needsPreference()) {
					foodItem->setPreference(preference);
				}

				newOrder->addFoodItems(foodItem, quantity);

			}

			// Add the order to the history
			orderHistory.push_back(newOrder);
		}

		inFile.close();
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
			catch (const LoginException& error) {
				cerr << RED << error.what() << RESET << endl;
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
			newOrder->saveToOrderHistory();
		}
		else {
			// If user don't confirm the order, delete it 
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

		// Create a new orderID
		string newOrderID = generateOrderID();

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
		string temp;

		while (true) {
			try {
				cout << "\nAny special instructions for the order? (Y/N): ";
				cin >> temp;

				if (temp.length() != 1 || (toupper(temp[0]) != 'Y' && toupper(temp[0]) != 'N')) {
					throw invalid_argument("Invalid input. Please enter 'Y' or 'N'.");
				}

				// Convert temp to uppercase to handle both 'Y' and 'y' or 'N' and 'n'
				char response = toupper(temp[0]);

				if (response == 'Y') {
					cout << "Enter special instructions: ";
					cin.ignore();
					getline(cin, specialInstructions);
					newOrder->setSpecialInstructions(specialInstructions);
					break;
				}
				else if (response == 'N') {
					newOrder->setSpecialInstructions("NULL");
					break;
				}
			}
			catch (const invalid_argument& error) {
				cout << RED << error.what() << RESET << endl;  
				cin.clear();  // Clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
			}
		}

		loadRiders("RiderInformation.txt");

		// Randomly select a rider
		Rider* selectedRider = getRider();

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
			cout << "****************************************\n";
			cout << endl << endl;
		}
	}

	void reorder() {
		cout << GREEN << "Reorder" << RESET << endl;
		int index;

		// Create a new orderID
		string newOrderID = generateOrderID();

		while (true) {
			try {
				cout << "Enter the order index you want to reorder: ";
				if (!(cin >> index)) {
					cin.clear(); // Clear the error flag on cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
					throw invalid_argument("Invalid input. Please enter a number.");
				}

				if (index < 1 || index > orderHistory.size()) {
					throw out_of_range("Invalid order index. Please try again.");
				}

				// crate a new order object with the same food items but a new orderID
				Order* reOrder = orderHistory[index - 1];
				reOrder->setOrderID(newOrderID);
				reOrder->orderSummary();
				cout << GREEN;
				cout << "======================================\n";
				cout << "Order has been successfully reordered!" << endl;
				cout << "======================================\n";
				cout << RESET << endl;
				cout << endl;
				// Determine payment method
				loadRiders("RiderInformation.txt");
				Rider* selectedRider = getRider();
				reOrder->getDelivery().assignRider(selectedRider);
				cout << endl;
				// Determine new delivery option
				DetermineDeliveryOption(reOrder->getDelivery(), reOrder);
				confirmation(reOrder);
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