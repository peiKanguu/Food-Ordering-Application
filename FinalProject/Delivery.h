#ifndef DELIVERY_H
#define DELIVERY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Rider.h"

using namespace std;

class Delivery {
private:
    int distance;
    string deliveryOption;
    int deliveryTime;
    double deliveryFee;
    Rider* rider;

    double calculateDeliveryFee() {
        double baseFee;

        // Determine base time based on delivery option
        if (deliveryOption == "Direct") {
            deliveryTime = 30;
            baseFee = 5.0;
        }
        else if (deliveryOption == "Standard") {
            deliveryTime = 45;
            baseFee = 3.0;
        }
        else if (deliveryOption == "Saver") {
            deliveryTime = 60;
            baseFee = 1.5;
        }
        else {
            throw invalid_argument("Invalid delivery option");
        }

        // Adjust base time based on distance
        if (distance == 1) {
            return baseFee;
        }
        else if (distance == 5) {
            return baseFee + 2.5;  // Add $2.5 for 5 km
        }
        else if (distance == 10) {
            return baseFee + 5;  // Add $5 for 10 km
        }
        else {
            throw invalid_argument("Invalid distance");
        }
    }

public:
    Delivery(int distance)
        : distance(distance), deliveryTime(0), deliveryFee(0.0), rider(nullptr) {}

	int getDistance() const {
		return distance;
	}

    void setDeliveryOption(const string& option) {
        deliveryOption = option;
        deliveryFee = calculateDeliveryFee(); // Calculate delivery fee when option is set
    }

    void assignRider(Rider* rider) {
        this->rider = rider;
    }

    Rider* getRider() const {
        return rider;
    }

    string getDeliveryOption() const {
        return deliveryOption;
    }

    int getDeliveryTime() const {
        return deliveryTime;
    }

    double getDeliveryFee() const {
        return deliveryFee;
    }
};

#endif // DELIVERY_H

