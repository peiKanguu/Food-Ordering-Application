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
// 烤鸡翅 - 3种酱料选择
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

// 番茄面包 - 无需选择
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

// 香煎鹅肝面包 - 无需选择
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

// 法式薯条 - 2种份量选择
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

// 鸡米花 - 2种蘸料选择
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

// 巧克力薄脆饼干 - 无需选择
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

// 烤肋眼牛排 - 4种熟度选择
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

// 凯撒沙拉 - 无需选择
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

// 碳烤三文鱼 - 无需选择
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

// 新英格兰蛤蜊浓汤 - 无需选择
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

// 苹果派 - 无需选择
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

// 鹰嘴豆泥 - 无需选择
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

// 羊肉沙威玛 - 无需选择
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

// 烤肉串 - 3种食材选择
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

// 浓缩酸奶 - 2种酱料选择
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

// 沙拉三明治拼盘 - 无需选择
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

// 鸡肉卡布萨 - 无需选择
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

// 法图沙拉 - 无需选择
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

// 肉丸汤 - 2种份量选择
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

// 水煮鱼 - 3种食材选择
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

// 麻婆豆腐 - 2种辣度选择
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

// 宫保鸡丁 - 无需选择
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

// 辣子鸡 - 无需选择
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

// 回锅肉 - 无需选择
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

// 酸梅汤 - 无需选择
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

// 锅包肉 - 无需选择
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

// 九转大肠 - 无需选择
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

// 小鸡炖蘑菇 - 无需选择
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

// 猪肉炖粉条 - 无需选择
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

// 人参鸡 - 无需选择
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

// 北京烤鸭 - 无需选择
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

// 炸酱面 - 无需选择
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

// 涮羊肉 - 选择羊肉种类
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

// 门丁肉饼 - 无需选择
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

// 干炸丸子 - 无需选择
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

// 烤肉 - 选择烤肉食材
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

// 寿司 - 选择鱼类
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

// 天妇罗 - 选择食材
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

// 拉面 - 选择汤底
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

// 刺身 - 选择鱼类
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

// 烤鸡串 - 选择酱料
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

// 章鱼烧 - 无需选择
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

// 味增汤 - 无需选择
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

// 石锅拌饭 - 选择配料
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

// 辣炒年糕 - 无需选择
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

// 烤牛肉 - 选择酱料
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

// 泡菜 - 无需选择
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

// 部队锅 - 选择额外配料
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

// 泰式炒河粉 - 选择肉类
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

// 泰式冬阴功汤 - 无需选择
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

// 绿咖喱鸡 - 无需选择
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

// 泰式炒饭 - 选择肉类
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

// 泰式红咖喱 - 无需选择
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

// 泰式罗勒炒鸡 - 无需选择
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

// 泰式青木瓜沙拉 - 无需选择
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

// 泰式甜点 - 选择口味
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
