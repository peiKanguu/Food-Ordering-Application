#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Food.h"
#include "Colors.h"
#include <iomanip>
#include <vector>

using namespace std;

class Restaurant {
protected:
    string name;
    int distance;
    vector<Food*> items;

public:
    Restaurant(string name, int distance) : name(name), distance(distance) {}

    virtual string getName() const {
        return name;
    }

    virtual int getDistance() const {
        return distance;
    }

    virtual string getCategory() const = 0;

    virtual void addFood(Food* food) {
        items.push_back(food);
    }

    virtual vector<Food*> getItems() const {
        return items;
    }

    virtual void displayMenu() const {
        cout << "\nMenu for restaurant: [ " << name << " ]" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << MAGENTA << "* " << RESET << i << " : ";
            cout << setw(26) << left << items[i]->getName() << "$" << setw(7) << right << fixed << setprecision(2) << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

// Specific restaurant classes inheriting from Restaurant
class WesternRestaurant : public Restaurant {
public:
    WesternRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getCategory() const override {
        return "Western";
    }
};

class ArabicRestaurant : public Restaurant {
public:
    ArabicRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getCategory() const override {
        return "Arabic";
    }
};

class ChineseRestaurant : public Restaurant {
public:
    ChineseRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getCategory() const override {
        return "Chinese";
    }
};

class JapaneseRestaurant : public Restaurant {
public:
    JapaneseRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getCategory() const override {
        return "Japanese";
    }
};

class KoreanRestaurant : public Restaurant {
public:
    KoreanRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getCategory() const override {
        return "Korean";
    }
};

class ThaiRestaurant : public Restaurant {
public:
    ThaiRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getCategory() const override {
        return "Thai";
    }
};

#endif // RESTAURANT_H

