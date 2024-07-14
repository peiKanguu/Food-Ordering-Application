#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <unordered_map>
#include <iomanip>
#include "Restaurant.h"
#include "Food.h"
#include "Delivery.h"

using namespace std;

// Custom hash function for Food*
struct FoodPtrHash {
    size_t operator()(Food* food) const {
        return std::hash<std::string>()(food->getName());
    }
};

// Custom equality function for Food*
struct FoodPtrEqual {
    bool operator()(Food* lhs, Food* rhs) const {
        return lhs->getName() == rhs->getName();
    }
};

class Order {
private:
	string newOrderID;
	string restaurantName;
    unordered_map<Food*, int, FoodPtrHash, FoodPtrEqual> food_and_quantity; // Hash table to store the food items and corresponding quantities
    double totalPrice_food;
	Delivery delivery;
	string paymentMethod;
    string specialInstructions = "NULL";
public:
    Order(string ID, string Name, Delivery delivery, string paymentMethod = "") :
        newOrderID(ID), restaurantName(Name), delivery(delivery), paymentMethod(paymentMethod), totalPrice_food(0) {}

    void setOrderID(string orderID) {
		newOrderID = orderID;
    }

	string getOrderID() {
		return newOrderID;
	}

	string getRestaurantName() {
		return restaurantName;
	}

	void addFoodItems(Food* foodItem, int quantities) {
		food_and_quantity[foodItem] = quantities;
	}

	unordered_map<Food*, int, FoodPtrHash, FoodPtrEqual> getFoodItemsAndQuantity() {
		return food_and_quantity;
	}

    void setDelivery(Delivery delivery) {
		this->delivery = delivery;
    }

    Delivery& getDelivery() {
		return delivery;
    }

    void setPaymentMethod(string method) {
		paymentMethod = method;
    }

    string getPaymentMethod() {
        return paymentMethod;
    }

    void setSpecialInstructions(string instructions) {
		specialInstructions = instructions;
    }

    void orderSummary() {
        cout << "\nRestaurant: " << getRestaurantName() << endl;
        cout << "\nOrder Summary:" << endl;
        totalPrice_food = 0;
        for (auto& pair : food_and_quantity) {
            Food* food = pair.first;
            int quantity = pair.second;
            cout << "- " << quantity << " x " << setw(20) << left << food->getName()
                << "\t$" << setw(7) << right << fixed << setprecision(2) << food->getPrice() * quantity << endl;
			if (food->needsPreference()) {
				cout << " (" << food->getPreference() << ")" << endl;
			}
            totalPrice_food += food->getPrice() * quantity;
        }

        cout << "\n===== > Subtotal: " << setw(15) << right << "$" << setw(7) << fixed << setprecision(2) << totalPrice_food << endl;
        cout << "===== > Delivery fee: " << setw(11) << right << "$" << setw(7) << fixed << setprecision(2) << delivery.getDeliveryFee() << endl;
        cout << "\nTotal: " << setw(26) << right << "$" << setw(7) << fixed << setprecision(2) << delivery.getDeliveryFee() + totalPrice_food << endl;
        cout << "\n----------------------------------------\n";
        cout << "Special Instructions:\n" << specialInstructions << endl;
        cout << "\n----------------------------------------\n";
    }

    void saveToOrderHistory() const {
        ofstream outFile("orderHistory.txt", ios::app);
        if (!outFile.is_open()) {
            cerr << "Error opening file: orderHistory.txt" << endl;
            return;
        }

        // Write the order header line
        outFile << newOrderID << ","
            << restaurantName << ","
            << delivery.getDistance() << ","
			<< delivery.getDeliveryOption() << ","
            << paymentMethod << ","
            << specialInstructions << endl;

        // Write each food item in the order
        for (const auto& pair : food_and_quantity) {
            Food* food = pair.first;
            int quantity = pair.second;
            outFile << food->getName() << ","
                << quantity << ","
                << (food->needsPreference() ? food->getPreference() : "N/A") << ","
                << food->getPrice() << endl;
        }

        // Add a blank line to separate orders
        outFile << endl;

        outFile.close();
    }
};

#endif // ORDER_H