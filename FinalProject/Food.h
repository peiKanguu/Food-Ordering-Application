#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Colors.h"
using namespace std;

class Food {
protected:
    string name;
    double price;
    string preference;

public:
    Food(string n, double p, string pref) : name(n), price(p), preference(pref) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    string getPreference() const {
        return preference;
    }

    virtual bool needsPreference() const = 0;
    virtual void choosePreference() = 0;

	void setPreference(const string& pref) {
		preference = pref;
	}
};

// Specific food classes inheriting from Food
// No need to choose preference
class NoPreferenceFood : public Food {
public:
    NoPreferenceFood(const string& name, double price, const string& pref) : Food(name, price, pref) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
		preference = "NULL";
    }
};

// Need to choose preference
class PreferenceFood : public Food {
private:
    string chooseFromOptions(const string& foodName, const vector<string>& options) {
        cout << "Please choose a preference for " << foodName << ":\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        while (true) {
            try {
                cout << "Enter the number of your choice: ";
                if (!(cin >> choice)) {
                    cin.clear(); // Clear the error flag on cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    throw invalid_argument("Invalid input. Please enter a number.");
                }

                if (choice < 1 || choice > static_cast<int>(options.size())) {
                    throw out_of_range("Invalid choice. Please enter a number within the range.");
                }

                break;
            }
            catch (const invalid_argument& error) {
                cout << RED << error.what() << RESET << endl;
            }
            catch (const out_of_range& error) {
                cout << RED << error.what() << RESET << endl;
            }
        }

        return options[choice - 1];
    }

public:
    PreferenceFood(const string& name, double price, const string& pref) : Food(name, price, pref) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        if (preference == "Roast Chicken Wing") {
            preference = chooseFromOptions("Roast Chicken Wing", { "Balsamic Vinegar Sauce", "Black Pepper Sauce", "Sweet Chili Sauce" });
        }
        else if (preference == "French Fries") {
            preference = chooseFromOptions("French Fries", { "Regular", "Large" });
            price = (preference == "Regular") ? 2.99 : 3.99;
        }
        else if (preference == "Popcorn Chicken") {
            preference = chooseFromOptions("Popcorn Chicken", { "Spicy Sauce", "Sweet Chili Sauce" });
        }
        else if (preference == "Grilled Ribeye Steak") {
            preference = chooseFromOptions("Grilled Ribeye Steak", { "Medium Rare", "Medium", "Medium Well", "Well Done" });
        }
        else if (preference == "Shish Kebab") {
            preference = chooseFromOptions("Shish Kebab", { "Beef", "Chicken", "Lamb" });
            if (preference == "Beef") price = 12.99;
            else if (preference == "Chicken") price = 11.99;
            else price = 10.99;
        }
        else if (preference == "Labneh") {
            preference = chooseFromOptions("Labneh", { "Olive Oil", "Za'atar" });
        }
        else if (preference == "Baklava") {
            preference = chooseFromOptions("Baklava", { "Regular", "Large" });
            price = (preference == "Regular") ? 2.69 : 3.69;
        }
        else if (preference == "Boiled Fish") {
            preference = chooseFromOptions("Boiled Fish", { "Bass", "Carp", "Catfish" });
            if (preference == "Bass") price = 13.66;
            else if (preference == "Carp") price = 12.66;
            else price = 11.66;
        }
        else if (preference == "Mapo Tofu") {
            preference = chooseFromOptions("Mapo Tofu", { "Mild", "Spicy" });
        }
        else if (preference == "Instant Boiled Mutton") {
            preference = chooseFromOptions("Instant Boiled Mutton", { "Lamb Leg", "Lamb Rib", "Lamb Shoulder" });
        }
        else if (preference == "Grilled Meat") {
            preference = chooseFromOptions("Grilled Meat", { "Beef", "Lamb", "Pork" });
            if (preference == "Beef") price = 8.60;
            else if (preference == "Lamb") price = 6.60;
            else price = 4.60;
        }
        else if (preference == "Sushi") {
            preference = chooseFromOptions("Sushi", { "Salmon", "Carp", "Eel" });
            if (preference == "Salmon") price = 4.99;
            else if (preference == "Carp") price = 2.99;
            else price = 3.99;
        }
        else if (preference == "Tempura") {
            preference = chooseFromOptions("Tempura", { "Shrimp", "Vegetable", "Fish" });
        }
        else if (preference == "Ramen") {
            preference = chooseFromOptions("Ramen", { "Shoyu", "Miso", "Tonkotsu" });
        }
        else if (preference == "Sashimi") {
            preference = chooseFromOptions("Sashimi", { "Salmon", "Tuna", "Octopus" });
        }
        else if (preference == "Yakitori") {
            preference = chooseFromOptions("Yakitori", { "Salt", "Tare (Sweet soy sauce)" });
        }
        else if (preference == "Bibimbap") {
            preference = chooseFromOptions("Bibimbap", { "Beef", "Chicken", "Tofu" });
            if (preference == "Beef") price = 10.22;
            else if (preference == "Chicken") price = 9.22;
            else price = 8.22;
        }
        else if (preference == "Bulgogi") {
            preference = chooseFromOptions("Bulgogi", { "Soy Sauce", "Spicy" });
        }
        else if (preference == "Budae Jjigae") {
            preference = chooseFromOptions("Budae Jjigae", { "Cheese", "Ramen Noodles", "Extra Meat" });
        }
        else if (preference == "Pad Thai") {
            preference = chooseFromOptions("Pad Thai", { "Chicken", "Shrimp", "Tofu" });
        }
        else if (preference == "Thai Fried Rice") {
            preference = chooseFromOptions("Thai Fried Rice", { "Chicken", "Shrimp", "Vegetable" });
        }
        else if (preference == "Thai Dessert") {
            preference = chooseFromOptions("Thai Dessert", { "Mango Sticky Rice", "Coconut Pudding", "Banana in Coconut Milk" });
            if (preference == "Mango Sticky Rice") price = 13.99;
            else if (preference == "Coconut Pudding") price = 12.99;
            else price = 11.99;
        }
    }
};

#endif // FOOD_H