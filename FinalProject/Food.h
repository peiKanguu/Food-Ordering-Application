#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
using namespace std;

class Food {
protected:
	string name;
	double price;
public:
	Food(string n, double p) : name(n), price(p) {}

	virtual string getName() = 0;
	virtual double getPrice() = 0;
    virtual bool needsPreference() const = 0;
    virtual void choosePreference() = 0;
    virtual string getPreference() = 0;
};

class WesternFood : public Food {
protected:
    string preference;
public:
    WesternFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }

    string getPreference() override {
        return preference;
    }

    void setPreference(const string& pref) {
        preference = pref;
    }
};

class ArabicFood : public Food {
protected:
    string preference;
public:
    ArabicFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }

    string getPreference() override {
        return preference;
    }

    void setPreference(const string& pref) {
        preference = pref;
    }
};

class ChineseFood : public Food {
protected:
    string preference;
public:
    ChineseFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }

    string getPreference() override {
        return preference;
    }

    void setPreference(const string& pref) {
        preference = pref;
    }
};

class JapaneseFood : public Food {
protected:
    string preference;
public:
    JapaneseFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }

    string getPreference() override {
        return preference;
    }

    void setPreference(const string& pref) {
        preference = pref;
    }
};

class KoreanFood : public Food {
protected:
    string preference;
public:
    KoreanFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }

    string getPreference() override {
        return preference;
    }

    void setPreference(const string& pref) {
        preference = pref;
    }
};

class ThaiFood : public Food {
protected:
    string preference;
public:
    ThaiFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }

    string getPreference() override {
        return preference;
    }

    void setPreference(const string& pref) {
        preference = pref;
    }
};

// Specific food classes inheriting from their respective cuisine classes
// ������ - 3�ֽ���ѡ��
class RoastChickenWing : public WesternFood {
public:
	RoastChickenWing() : WesternFood("Roast Chicken Wing", 36.00) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Balsamic Vinegar Sauce","Black Pepper Sauce", "Sweet chili sauce" };
        cout << "Please select sauce" <<":\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// ������� - ����ѡ��
class TomatoBread : public WesternFood {
public:
	TomatoBread() : WesternFood("Tomato Bread", 20.00) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// �������� - ����ѡ��
class PanFriedFoieGras : public WesternFood {
public:
	PanFriedFoieGras() : WesternFood("Pan-Fried Foie Gras", 48.00) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ��ʽ���� - 2�ַ���ѡ��
class FrenchFries : public WesternFood {
public:
    FrenchFries() : WesternFood("French Fries", 15.00) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Regular", "Large" };
        cout << "Please select the serving size" << ":\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Regular") {
            price = 8.00;
        }
        else {
            price = 15.00;
        }
    }
};

// ���׻� - 2��պ��ѡ��
class PopcornChicken : public WesternFood {
public:
    PopcornChicken() : WesternFood("Procorn Chicken", 22.00) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Spicy Sauce", "Sweet chili sauce" };
        cout << "Please choose sauce" << ":\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// �ɿ���������� - ����ѡ��
class ChocolateThinCrisp : public WesternFood {
public:
	ChocolateThinCrisp() : WesternFood("Chocolate Thin Crisp", 26.00) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}

};

// ������ţ�� - 4�����ѡ��
class GrilledRibeyeSteak : public WesternFood {
public:
    GrilledRibeyeSteak() : WesternFood("Grilled Ribeye Steak", 45.99) {}

	bool needsPreference() const override {
		return true;
	}

	void choosePreference() override {
		vector<string> options = { "Medium Rare", "Medium","Medium well", "Well Done" };
		cout << "Please choose a preference for " << ":\n";
		for (size_t i = 0; i < options.size(); ++i) {
			cout << i + 1 << ". " << options[i] << "\n";
		}

		int choice;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		while (choice < 1 || choice > options.size()) {
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
		}

		preference = options[choice - 1];
	}
};

// ����ɳ�� - ����ѡ��
class CaesarSalad : public WesternFood {
public:
    CaesarSalad() : WesternFood("Caesar Salad", 10.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ̼�������� - ����ѡ��
class SpaghettiCarbonara : public WesternFood {
public:
    SpaghettiCarbonara() : WesternFood("Spaghetti Carbonara", 15.99) {}

    bool needsPreference() const override {
        return false;
    }

	void choosePreference() override {
		preference = "NULL";
	}
};

// ��Ӣ��������Ũ�� - ����ѡ��
class NewEnglandClamChowder : public WesternFood {
public:
    NewEnglandClamChowder() : WesternFood("New England Clam Chowder", 8.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ƻ���� - ����ѡ��
class ApplePie : public WesternFood {
public:
    ApplePie() : WesternFood("Apple Pie", 6.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
		preference = "NULL";
    }
};

// ӥ�춹�� - ����ѡ��
class Hummus : public ArabicFood {
public:
	Hummus() : ArabicFood("Hummus", 6.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ����ɳ���� - ����ѡ��
class LambShawarma : public ArabicFood {
public:
    LambShawarma() : ArabicFood("Lamb Shawarma", 15.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ���⴮ - 3��ʳ��ѡ��
class ShishKebab : public ArabicFood {
public:
	ShishKebab() : ArabicFood("Shish Kebab", 21.69) {}

	bool needsPreference() const override {
		return true;
	}

	void choosePreference() override {
		vector<string> options = { "Beef", "Chicken", "Lamb" };
		cout << "Please select ingredients" << ":\n";
		for (size_t i = 0; i < options.size(); ++i) {
			cout << i + 1 << ". " << options[i] << "\n";
		}

		int choice;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		while (choice < 1 || choice > options.size()) {
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
		}

		preference = options[choice - 1];
	}
};

// Ũ������ - 2�ֽ���ѡ��
class Labneh : public ArabicFood {
public:
	Labneh() : ArabicFood("Labneh", 5.99) {}

	bool needsPreference() const override {
		return true;
	}

	void choosePreference() override {
		vector<string> options = { "Olive Oil", "Za'atar" };
		cout << "Please choose a dipping sauce" << ":\n";
		for (size_t i = 0; i < options.size(); ++i) {
			cout << i + 1 << ". " << options[i] << "\n";
		}

		int choice;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		while (choice < 1 || choice > options.size()) {
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
		}

		preference = options[choice - 1];
	}
};

// ɳ��������ƴ�� - ����ѡ��
class FalafelPlate : public ArabicFood {
public:
    FalafelPlate() : ArabicFood("Falafel Plate", 9.99) {}

    bool needsPreference() const override {
		return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ���⿨���� - ����ѡ��
class ChickenKabsa : public ArabicFood {
public:
    ChickenKabsa() : ArabicFood("Chicken Kabsa", 13.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ��ͼɳ�� - ����ѡ��
class FattoushSalad : public ArabicFood {
public:
    FattoushSalad() : ArabicFood("Fattoush Salad", 7.99) {}

    bool needsPreference() const override {
		return false;
    }

	void choosePreference() override {
		preference = "NULL";
	}
};

// ������ - 2�ַ���ѡ��
class Baklava : public ArabicFood {
public:
    Baklava() : ArabicFood("Baklava", 5.99) {}

	bool needsPreference() const override {
		return true;
	}

	void choosePreference() override {
		vector<string> options = { "Regular", "Large" };
		cout << "Please select the serving size" << ":\n";
		for (size_t i = 0; i < options.size(); ++i) {
			cout << i + 1 << ". " << options[i] << "\n";
		}

		int choice;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		while (choice < 1 || choice > options.size()) {
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
		}

		preference = options[choice - 1];
	}
};

// ˮ���� - 3��ʳ��ѡ��
class BoiledFish : public ChineseFood {
public:
	BoiledFish() : ChineseFood("Boiled Fish", 15.99) {}

	bool needsPreference() const override {
		return true;
	}

	void choosePreference() override {
		vector<string> options = { "Bass", "Carp", "Catfish" };
		cout << "Please select ingredients" <<":\n";
		for (size_t i = 0; i < options.size(); ++i) {
			cout << i + 1 << ". " << options[i] << "\n";
		}

		int choice;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		while (choice < 1 || choice > options.size()) {
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
		}

		preference = options[choice - 1];
	}
};

// ���Ŷ��� - 2������ѡ��
class MapoTofu : public ChineseFood {
public:
	MapoTofu() : ChineseFood("Mapo Tofu", 11.99) {}

	bool needsPreference() const override {
		return true;
	}

	void choosePreference() override {
		vector<string> options = { "Mild", "Spicy" };
		cout << "Please select the spiciness" << ":\n";
		for (size_t i = 0; i < options.size(); ++i) {
			cout << i + 1 << ". " << options[i] << "\n";
		}

		int choice;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		while (choice < 1 || choice > options.size()) {
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
		}

		preference = options[choice - 1];
	}
};

// �������� - ����ѡ��
class KungPaoChicken : public ChineseFood {
public:
    KungPaoChicken() : ChineseFood("Kung Pao Chicken", 12.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ���Ӽ� - ����ѡ��
class ChongqingChicken : public ChineseFood {
public:
	ChongqingChicken() : ChineseFood("Chongqing Chicken", 13.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// �ع��� - ����ѡ��
class TwiceCookedPork : public ChineseFood {
public:
	TwiceCookedPork() : ChineseFood("Twice Cooked Pork", 14.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ��÷�� - ����ѡ��
class SourPlumDrink : public ChineseFood {
public:
	SourPlumDrink() : ChineseFood("Sour Plum Drink", 3.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ������ - ����ѡ��
class SweetAndSourPork : public ChineseFood {
public:
	SweetAndSourPork() : ChineseFood("Sweet and Sour Pork", 13.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ��ת�� - ����ѡ��
class NineFoldIntestine : public ChineseFood {
public:
	NineFoldIntestine() : ChineseFood("Nine Fold Intestine", 15.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}

};

// С����Ģ�� - ����ѡ��
class ChickenMushroomSoup : public ChineseFood {
public:
	ChickenMushroomSoup() : ChineseFood("Chicken Mushroom Soup", 9.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ���������� - ����ѡ��
class PorkStewWithRiceNoodles : public ChineseFood {
public:
	PorkStewWithRiceNoodles() : ChineseFood("Pork Stew Rice Noodles", 11.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}

};

// �˲μ� - ����ѡ��
class GinsengChickenSoup : public ChineseFood {
public:
	GinsengChickenSoup() : ChineseFood("Ginseng Chicken Soup", 12.99) {}

	bool needsPreference() const override {
		return false;
	}

	void choosePreference() override {
		preference = "NULL";
	}
};

// ������Ѽ - ����ѡ��
class PekingDuck : public ChineseFood {
public:
    PekingDuck() : ChineseFood("Peking Duck", 24.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ը���� - ����ѡ��
class Zhajiangmian : public ChineseFood {
public:
    Zhajiangmian() : ChineseFood("Zhajiangmian", 9.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ������ - ѡ����������
class InstantBoiledMutton : public ChineseFood {
public:
    InstantBoiledMutton() : ChineseFood("Instant Boiled Mutton", 19.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Lamb Leg", "Lamb Rib", "Lamb Shoulder" };
        cout << "Please select the type of mutton:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// �Ŷ���� - ����ѡ��
class MendingMeatPie : public ChineseFood {
public:
    MendingMeatPie() : ChineseFood("Mending Meat Pie", 8.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ��ը���� - ����ѡ��
class DeepFriedMeatballs : public ChineseFood {
public:
    DeepFriedMeatballs() : ChineseFood("Deep Fried Meatballs", 10.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ���� - ѡ����ʳ��
class GrilledMeat : public ChineseFood {
public:
    GrilledMeat() : ChineseFood("Grilled Meat", 18.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Beef", "Lamb", "Pork" };
        cout << "Please select the type of meat:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// ��˾ - ѡ������
class Sushi : public JapaneseFood {
public:
    Sushi() : JapaneseFood("Sushi", 12.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Salmon", "Carp", "Eel" };
        cout << "Please select the type of fish:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// �츾�� - ѡ��ʳ��
class Tempura : public JapaneseFood {
public:
    Tempura() : JapaneseFood("Tempura", 10.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Shrimp", "Vegetable", "Fish" };
        cout << "Please select the type of tempura:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
		if (preference == "Shrimp")
			price = 12.99;
		else if(preference == "Vegetable")
			price = 10.99;
		else
			price = 14.99;
    }
};

// ���� - ѡ������
class Ramen : public JapaneseFood {
public:
    Ramen() : JapaneseFood("Ramen", 9.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Shoyu", "Miso", "Tonkotsu" };
        cout << "Please select the type of broth:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// ���� - ѡ������
class Sashimi : public JapaneseFood {
public:
    Sashimi() : JapaneseFood("Sashimi", 14.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Salmon", "Tuna", "Octopus" };
        cout << "Please select the type of sashimi:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
		if (preference == "Salmon")
			price = 16.99;
		else if(preference == "Tuna")
			price = 18.99;
		else
			price = 14.99;
    }
};

// ������ - ѡ����
class Yakitori : public JapaneseFood {
public:
    Yakitori() : JapaneseFood("Yakitori", 8.99) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Salt", "Tare (Sweet soy sauce)" };
        cout << "Please select the type of sauce:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
    }
};

// ������ - ����ѡ��
class Takoyaki : public JapaneseFood {
public:
    Takoyaki() : JapaneseFood("Takoyaki", 7.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ζ���� - ����ѡ��
class MisoSoup : public JapaneseFood {
public:
    MisoSoup() : JapaneseFood("Miso Soup", 3.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ʯ���跹 - ѡ������
class Bibimbap : public KoreanFood {
public:
    Bibimbap() : KoreanFood("Bibimbap", 0.0) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Beef", "Chicken", "Tofu" };
        cout << "Please select the ingredient:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Beef")
            price = 10.99;
        else if (preference == "Chicken")
            price = 9.99;
        else
            price = 8.99;
    }
};

// ������� - ����ѡ��
class Tteokbokki : public KoreanFood {
public:
    Tteokbokki() : KoreanFood("Tteokbokki", 7.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ��ţ�� - ѡ����
class Bulgogi : public KoreanFood {
public:
    Bulgogi() : KoreanFood("Bulgogi", 0.0) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Soy Sauce", "Spicy" };
        cout << "Please select the type of sauce:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Soy Sauce")
            price = 14.99;
        else
            price = 15.99;
    }
};

// �ݲ� - ����ѡ��
class Kimchi : public KoreanFood {
public:
    Kimchi() : KoreanFood("Kimchi", 5.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ���ӹ� - ѡ���������
class BudaeJjigae : public KoreanFood {
public:
    BudaeJjigae() : KoreanFood("Budae Jjigae", 0.0) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Cheese", "Ramen Noodles", "Extra Meat" };
        cout << "Please select the extra ingredient:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Cheese")
            price = 13.99;
        else if (preference == "Ramen Noodles")
            price = 14.99;
        else
            price = 16.99;
    }
};

// ̩ʽ���ӷ� - ѡ������
class PadThai : public ThaiFood {
public:
    PadThai() : ThaiFood("Pad Thai", 0.0) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Chicken", "Shrimp", "Tofu" };
        cout << "Please select the type of meat:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Chicken")
            price = 12.99;
        else if (preference == "Shrimp")
            price = 14.99;
        else
            price = 11.99;
    }
};

// ̩ʽ�������� - ����ѡ��
class TomYumGoong : public ThaiFood {
public:
    TomYumGoong() : ThaiFood("Tom Yum Goong", 13.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// �̿�଼� - ����ѡ��
class GreenCurry : public ThaiFood {
public:
    GreenCurry() : ThaiFood("Green Curry", 14.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ̩ʽ���� - ѡ������
class ThaiFriedRice : public ThaiFood {
public:
    ThaiFriedRice() : ThaiFood("Thai Fried Rice", 0.0) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Chicken", "Shrimp", "Vegetable" };
        cout << "Please select the type of meat:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Chicken")
            price = 11.99;
        else if (preference == "Shrimp")
            price = 13.99;
        else
            price = 10.99;
    }
};

// ̩ʽ�쿧� - ����ѡ��
class RedCurry : public ThaiFood {
public:
    RedCurry() : ThaiFood("Red Curry", 14.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ̩ʽ���ճ��� - ����ѡ��
class BasilChicken : public ThaiFood {
public:
    BasilChicken() : ThaiFood("Basil Chicken", 12.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ̩ʽ��ľ��ɳ�� - ����ѡ��
class PapayaSalad : public ThaiFood {
public:
    PapayaSalad() : ThaiFood("Papaya Salad", 9.99) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        preference = "NULL";
    }
};

// ̩ʽ��� - ѡ���ζ
class ThaiDessert : public ThaiFood {
public:
    ThaiDessert() : ThaiFood("Thai Dessert", 0.0) {}

    bool needsPreference() const override {
        return true;
    }

    void choosePreference() override {
        vector<string> options = { "Mango Sticky Rice", "Coconut Pudding", "Banana in Coconut Milk" };
        cout << "Please select the type of dessert:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }

        int choice;
        cout << "Enter the number of your choice: ";
        cin >> choice;

        while (choice < 1 || choice > options.size()) {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        preference = options[choice - 1];
        if (preference == "Mango Sticky Rice")
            price = 8.99;
        else if (preference == "Coconut Pudding")
            price = 7.99;
        else
            price = 6.99;
    }
};

#endif // FOOD_H
