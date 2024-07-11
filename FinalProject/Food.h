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

// 创建一个无需选择偏好的基类模板
template <typename BaseFood>
class NoPreferenceFood : public BaseFood {
public:
    NoPreferenceFood(const std::string& name, double price) : BaseFood(name, price) {}

    bool needsPreference() const override {
        return false;
    }

    void choosePreference() override {
        this->preference = "NULL";
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
class TomatoBread : public NoPreferenceFood<WesternFood> {
public:
	TomatoBread() : NoPreferenceFood<WesternFood>("Tomato Bread", 20.00) {}
};

// 香煎鹅肝 - 无需选择
class PanFriedFoieGras : public NoPreferenceFood<WesternFood> {
public:
	PanFriedFoieGras() : NoPreferenceFood<WesternFood>("Pan-Fried Foie Gras", 25.69) {}
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
class ChocolateThinCrisp : public NoPreferenceFood<WesternFood> {
public:
    ChocolateThinCrisp() : NoPreferenceFood<WesternFood>("Chocolate Thin Crisp", 26.00) {}
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
class CaesarSalad : public NoPreferenceFood<WesternFood> {
public:
    CaesarSalad() : NoPreferenceFood<WesternFood>("Caesar Salad", 10.99) {}
};

// 碳烤三文鱼 - 无需选择
class SpaghettiCarbonara : public NoPreferenceFood<WesternFood> {
public:
    SpaghettiCarbonara() : NoPreferenceFood<WesternFood>("Spaghetti Carbonara", 15.99) {}
};

// 新英格兰蛤蜊浓汤 - 无需选择
class NewEnglandClamChowder : public NoPreferenceFood<WesternFood> {
public:
    NewEnglandClamChowder() : NoPreferenceFood<WesternFood>("New England Clam Chowder", 8.99) {}
};

// 苹果派 - 无需选择
class ApplePie : public NoPreferenceFood<WesternFood> {
public:
    ApplePie() : NoPreferenceFood<WesternFood>("Apple Pie", 6.99) {}
};

// 鹰嘴豆泥 - 无需选择
class Hummus : public NoPreferenceFood<ArabicFood> {
public:
    Hummus() : NoPreferenceFood<ArabicFood>("Hummus", 6.99) {}
};

// 羊肉沙威玛 - 无需选择
class LambShawarma : public NoPreferenceFood<ArabicFood> {
public:
    LambShawarma() : NoPreferenceFood<ArabicFood>("Lamb Shawarma", 15.99) {}
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
class FalafelPlate : public NoPreferenceFood<ArabicFood> {
public:
    FalafelPlate() : NoPreferenceFood<ArabicFood>("Falafel Plate", 9.99) {}
};

// 鸡肉卡布萨 - 无需选择
class ChickenKabsa : public NoPreferenceFood<ArabicFood> {
public:
    ChickenKabsa() : NoPreferenceFood<ArabicFood>("Chicken Kabsa", 13.99) {}
};

// 法图沙拉 - 无需选择
class FattoushSalad : public NoPreferenceFood<ArabicFood> {
public:
    FattoushSalad() : NoPreferenceFood<ArabicFood>("Fattoush Salad", 7.99) {}
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
class KungPaoChicken : public NoPreferenceFood<ChineseFood> {
public:
    KungPaoChicken() : NoPreferenceFood<ChineseFood>("Kung Pao Chicken", 12.99) {}
};

// 辣子鸡 - 无需选择
class ChongqingChicken : public NoPreferenceFood<ChineseFood> {
public:
	ChongqingChicken() : NoPreferenceFood<ChineseFood>("Chongqing Chicken", 13.99) {}
};

// 回锅肉 - 无需选择
class TwiceCookedPork : public NoPreferenceFood<ChineseFood> {
public:
	TwiceCookedPork() : NoPreferenceFood<ChineseFood>("Twice Cooked Pork", 14.99) {}
};

// 酸梅汤 - 无需选择
class SourPlumDrink : public NoPreferenceFood<ChineseFood> {
public:
	SourPlumDrink() : NoPreferenceFood<ChineseFood>("Sour Plum Drink", 3.99) {}
};

// 锅包肉 - 无需选择
class SweetAndSourPork : public NoPreferenceFood<ChineseFood> {
public:
	SweetAndSourPork() : NoPreferenceFood<ChineseFood>("Sweet and Sour Pork", 13.99) {}
};

// 九转大肠 - 无需选择
class NineFoldIntestine : public NoPreferenceFood<ChineseFood> {
public:
	NineFoldIntestine() : NoPreferenceFood<ChineseFood>("Nine Fold Intestine", 15.99) {}
};

// 小鸡炖蘑菇 - 无需选择
class ChickenMushroomSoup : public NoPreferenceFood<ChineseFood> {
public:
	ChickenMushroomSoup() : NoPreferenceFood<ChineseFood>("Chicken Mushroom Soup", 9.99) {}
};

// 猪肉炖粉条 - 无需选择
class PorkStewWithRiceNoodles : public NoPreferenceFood<ChineseFood> {
public:
	PorkStewWithRiceNoodles() : NoPreferenceFood<ChineseFood>("Pork Stew Rice Noodles", 11.99) {}
};

// 人参鸡 - 无需选择
class GinsengChickenSoup : public NoPreferenceFood<ChineseFood> {
public:
    GinsengChickenSoup() : NoPreferenceFood<ChineseFood>("Ginseng Chicken Soup", 12.99) {}
};

// 北京烤鸭 - 无需选择
class PekingDuck : public NoPreferenceFood<ChineseFood> {
public:
    PekingDuck() : NoPreferenceFood<ChineseFood>("Peking Duck", 24.99) {}
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

// 炸酱面 - 无需选择
class Zhajiangmian : public NoPreferenceFood<ChineseFood> {
public:
    Zhajiangmian() : NoPreferenceFood<ChineseFood>("Zhajiangmian", 9.99) {}
};

// 门丁肉饼 - 无需选择
class MendingMeatPie : public NoPreferenceFood<ChineseFood> {
public:
    MendingMeatPie() : NoPreferenceFood<ChineseFood>("Mending Meat Pie", 8.99) {}
};

// 干炸丸子 - 无需选择
class DeepFriedMeatballs : public NoPreferenceFood<ChineseFood> {
public:
    DeepFriedMeatballs() : NoPreferenceFood<ChineseFood>("Deep Fried Meatballs", 10.99) {}
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
class Takoyaki : public NoPreferenceFood<JapaneseFood> {
public:
    Takoyaki() : NoPreferenceFood<JapaneseFood>("Takoyaki", 7.99) {}
};

// 味增汤 - 无需选择
class MisoSoup : public NoPreferenceFood<JapaneseFood> {
public:
    MisoSoup() : NoPreferenceFood<JapaneseFood>("Miso Soup", 3.99) {}
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
class Tteokbokki : public NoPreferenceFood<KoreanFood> {
public:
    Tteokbokki() : NoPreferenceFood<KoreanFood>("Tteokbokki", 7.99) {}
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
class Kimchi : public NoPreferenceFood<KoreanFood> {
public:
    Kimchi() : NoPreferenceFood<KoreanFood>("Kimchi", 5.99) {}
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
class TomYumGoong : public NoPreferenceFood<ThaiFood> {
public:
    TomYumGoong() : NoPreferenceFood<ThaiFood>("Tom Yum Goong", 13.99) {}
};

// 绿咖喱鸡 - 无需选择
class GreenCurry : public NoPreferenceFood<ThaiFood> {
public:
    GreenCurry() : NoPreferenceFood<ThaiFood>("Green Curry", 14.99) {}
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
class RedCurry : public NoPreferenceFood<ThaiFood> {
public:
    RedCurry() : NoPreferenceFood<ThaiFood>("Red Curry", 14.99) {}
};

// 泰式罗勒炒鸡 - 无需选择
class BasilChicken : public NoPreferenceFood<ThaiFood> {
public:
    BasilChicken() : NoPreferenceFood<ThaiFood>("Basil Chicken", 12.99) {}
};

// 泰式青木瓜沙拉 - 无需选择
class PapayaSalad : public NoPreferenceFood<ThaiFood> {
public:
    PapayaSalad() : NoPreferenceFood<ThaiFood>("Papaya Salad", 9.99) {}
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
