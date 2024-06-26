#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Food.h"
#include <vector>

using namespace std;

// Base Restaurant class
class Restaurant {
protected:
    string name;
    int distance;
    vector<Food*> items;
public:
    Restaurant(string name, int distance) : name(name), distance(distance) {}
    virtual string getName() = 0;
    virtual int getDistance() = 0;
    virtual string getCategory() = 0;
    virtual void addFood(Food* food) = 0;
    virtual vector<Food*> getItems() = 0;
    virtual void displayMenu() = 0;
};

// Specific restaurant classes inheriting from Restaurant
class WesternRestaurant : public Restaurant {
public:
    WesternRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getName() override {
        return name;
    }

    int getDistance() override {
        return distance;
    }

    string getCategory() override {
        return "Western";
    }

    void addFood(Food* food) override {
        items.push_back(food);
    }

    vector<Food*> getItems() override {
        return items;
    }

    void displayMenu() override {
        cout << "\nMenu for " << name << ":" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << "\t: ";
            cout << items[i]->getName() << ", Price: $" << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

class ArabicRestaurant : public Restaurant {
public:
    ArabicRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getName() override {
        return name;
    }

    int getDistance() override {
        return distance;
    }

    string getCategory() override {
        return "Arabic";
    }

    void addFood(Food* food) override {
        items.push_back(food);
    }

    vector<Food*> getItems() override {
        return items;
    }

    void displayMenu() override {
        cout << "\nMenu for " << name << ":" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << "\t: ";
            cout << items[i]->getName() << ", Price: $" << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

class ChineseRestaurant : public Restaurant {
public:
    ChineseRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getName() override {
        return name;
    }

    int getDistance() override {
        return distance;
    }

    string getCategory() override {
        return "Chinese";
    }

    void addFood(Food* food) override {
        items.push_back(food);
    }

    vector<Food*> getItems() override {
        return items;
    }

    void displayMenu() override {
        cout << "\nMenu for " << name << ":" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << "\t: ";
            cout << items[i]->getName() << ", Price: $" << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

class JapaneseRestaurant : public Restaurant {
public:
    JapaneseRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getName() override {
        return name;
    }

    int getDistance() override {
        return distance;
    }

    string getCategory() override {
        return "Japanese";
    }

    void addFood(Food* food) override {
        items.push_back(food);
    }

    vector<Food*> getItems() override {
        return items;
    }

    void displayMenu() override {
        cout << "\nMenu for " << name << ":" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << "\t: ";
            cout << items[i]->getName() << ", Price: $" << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

class KoreanRestaurant : public Restaurant {
public:
    KoreanRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getName() override {
        return name;
    }

    int getDistance() override {
        return distance;
    }

    string getCategory() override {
        return "Korean";
    }

    void addFood(Food* food) override {
        items.push_back(food);
    }

    vector<Food*> getItems() override {
        return items;
    }

    void displayMenu() override {
        cout << "\nMenu for " << name << ":" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << "\t: ";
            cout << items[i]->getName() << ", Price: $" << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

class ThaiRestaurant : public Restaurant {
public:
    ThaiRestaurant(string name, int distance) : Restaurant(name, distance) {}

    string getName() override {
        return name;
    }

    int getDistance() override {
        return distance;
    }

    string getCategory() override {
        return "Thai";
    }

    void addFood(Food* food) override {
        items.push_back(food);
    }

    vector<Food*> getItems() override {
        return items;
    }

    void displayMenu() override {
        cout << "\nMenu for " << name << ":" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << "\t: ";
            cout << items[i]->getName() << ", Price: $" << items[i]->getPrice() << endl;
        }
        cout << endl;
    }
};

#endif // RESTAURANT_H
