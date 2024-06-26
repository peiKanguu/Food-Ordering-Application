#ifndef DELIVERY_H
#define DELIVERY_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Delivery {
private:
    int distance;
    string deliveryOption;
    int deliveryTime;
    double deliveryFee;

    double calculateDeliveryFee() {
        double baseFee;

        // Determine base time based on delivery option
        if (deliveryOption == "Direct") {
            deliveryTime = 30;
            baseFee = 10.0;
        }
        else if (deliveryOption == "Standard") {
            deliveryTime = 45;
            baseFee = 5.0;
        }
        else if (deliveryOption == "Saver") {
            deliveryTime = 60;
            baseFee = 2.5;
        }
        else {
            throw invalid_argument("Invalid delivery option");
        }

        // Adjust base time based on distance
        if (distance = 1) {
            return baseFee;
        }
        else if (distance == 5) {
            return baseFee + 2.5;  // Add $2.5 for 5 km
        }
        else if (distance == 10) {
            return baseFee + 5;  // Add $2.5 for 10 km
        }
        else {
            throw invalid_argument("Invalid distance");
        }
    }
public:
    Delivery(int distance, string deliveryOption)
        : distance(distance), deliveryOption(deliveryOption) {
        deliveryFee = calculateDeliveryFee();
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

