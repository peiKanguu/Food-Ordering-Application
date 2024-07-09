#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <unordered_map>
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
public:
    Order(string ID, string Name, Delivery delivery, string paymentMethod = "") :
        newOrderID(ID), restaurantName(Name), delivery(delivery), paymentMethod(paymentMethod), totalPrice_food(0) {}

	string getOrderID() {
		return newOrderID;
	}

	string getRestaurantName() {
		return restaurantName;
	}

	void addFoodItems(Food* foodItem, int quantities) {
		food_and_quantity[foodItem] = quantities;
	}

    double getTotalPrice_food() {
        return totalPrice_food;
    }

    void setDelivery(Delivery delivery) {
		this->delivery = delivery;
    }

    Delivery getDelivery() {
		return delivery;
    }

    void setPaymentMethod(string method) {
		paymentMethod = method;
    }

    string getPaymentMethod() {
        return paymentMethod;
    }

    void orderSummary() {
        cout << "Order Summary:" << endl;
        cout << "===== >" << getRestaurantName() << "< =====" << endl;
        cout << "Order List:" << endl;
        cout << "Food Name:\t\tUnit price:\tQuantity:\tTotal price:" << endl;
        for (auto& pair : food_and_quantity) {
            Food* food = pair.first;
            int quantity = pair.second;
            cout << food->getName() << "\t\t$" << food->getPrice() << "\t\tX" << quantity << "\t$" << food->getPrice() * quantity << endl;
            totalPrice_food += food->getPrice() * quantity;
        }
        cout << "===== > Subtotal: $" << totalPrice_food << endl;
        cout << "The delivery fee is $" << delivery.getDeliveryFee() << endl;
        cout << "\n====> Total amount: $" << delivery.getDeliveryFee() + totalPrice_food << endl << endl;
    }
};

#endif // ORDER_H


