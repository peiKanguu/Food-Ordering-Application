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
};

class WesternFood : public Food {
public:
    WesternFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }
};

class ArabicFood : public Food {
public:
    ArabicFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }
};

class ChineseFood : public Food {
public:
    ChineseFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }
};

class JapaneseFood : public Food {
public:
    JapaneseFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }
};

class KoreanFood : public Food {
public:
    KoreanFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }
};

class ThaiFood : public Food {
public:
    ThaiFood(string n, double p) : Food(n, p) {}

    string getName() override {
        return Food::name;
    }

    double getPrice() override {
        return Food::price;
    }
};

// Specific food classes inheriting from their respective cuisine classes
class GrilledRibeyeSteak : public WesternFood {
public:
    GrilledRibeyeSteak() : WesternFood("Grilled Ribeye Steak", 25.99) {}
};

class CaesarSalad : public WesternFood {
public:
    CaesarSalad() : WesternFood("Caesar Salad", 10.99) {}
};

class SpaghettiCarbonara : public WesternFood {
public:
    SpaghettiCarbonara() : WesternFood("Spaghetti Carbonara", 15.99) {}
};

class NewEnglandClamChowder : public WesternFood {
public:
    NewEnglandClamChowder() : WesternFood("New England Clam Chowder", 8.99) {}
};

class ApplePie : public WesternFood {
public:
    ApplePie() : WesternFood("Apple Pie", 6.99) {}
};

class LambShawarma : public ArabicFood {
public:
    LambShawarma() : ArabicFood("Lamb Shawarma", 15.99) {}
};

class FalafelPlate : public ArabicFood {
public:
    FalafelPlate() : ArabicFood("Falafel Plate", 9.99) {}
};

class ChickenKabsa : public ArabicFood {
public:
    ChickenKabsa() : ArabicFood("Chicken Kabsa", 13.99) {}
};

class FattoushSalad : public ArabicFood {
public:
    FattoushSalad() : ArabicFood("Fattoush Salad", 7.99) {}
};

class Baklava : public ArabicFood {
public:
    Baklava() : ArabicFood("Baklava", 5.99) {}
};

class KungPaoChicken : public ChineseFood {
public:
    KungPaoChicken() : ChineseFood("Kung Pao Chicken", 12.99) {}
};

class DimSumPlatter : public ChineseFood {
public:
    DimSumPlatter() : ChineseFood("Dim Sum Platter", 14.99) {}
};

class PekingDuck : public ChineseFood {
public:
    PekingDuck() : ChineseFood("Peking Duck", 25.99) {}
};

class MapoTofu : public ChineseFood {
public:
    MapoTofu() : ChineseFood("Mapo Tofu", 11.99) {}
};

class SweetAndSourPork : public ChineseFood {
public:
    SweetAndSourPork() : ChineseFood("Sweet and Sour Pork", 13.99) {}
};

class SushiPlatter : public JapaneseFood {
public:
    SushiPlatter() : JapaneseFood("Sushi Platter", 20.99) {}
};

class RamenBowl : public JapaneseFood {
public:
    RamenBowl() : JapaneseFood("Ramen Bowl", 12.99) {}
};

class Tempura : public JapaneseFood {
public:
    Tempura() : JapaneseFood("Tempura", 14.99) {}
};

class TeriyakiChicken : public JapaneseFood {
public:
    TeriyakiChicken() : JapaneseFood("Teriyaki Chicken", 13.99) {}
};

class MatchaIceCream : public JapaneseFood {
public:
    MatchaIceCream() : JapaneseFood("Matcha Ice Cream", 6.99) {}
};

class Bibimbap : public KoreanFood {
public:
    Bibimbap() : KoreanFood("Bibimbap", 14.99) {}
};

class KimchiJjigae : public KoreanFood {
public:
    KimchiJjigae() : KoreanFood("Kimchi Jjigae", 11.99) {}
};

class KoreanBBQ : public KoreanFood {
public:
    KoreanBBQ() : KoreanFood("Korean BBQ", 19.99) {}
};

class Japchae : public KoreanFood {
public:
    Japchae() : KoreanFood("Japchae", 13.99) {}
};

class Tteokbokki : public KoreanFood {
public:
    Tteokbokki() : KoreanFood("Tteokbokki", 9.99) {}
};

class PadThai : public ThaiFood {
public:
    PadThai() : ThaiFood("Pad Thai", 13.99) {}
};

class GreenCurry : public ThaiFood {
public:
    GreenCurry() : ThaiFood("Green Curry", 12.99) {}
};

class TomYumSoup : public ThaiFood {
public:
    TomYumSoup() : ThaiFood("Tom Yum Soup", 10.99) {}
};

class MangoStickyRice : public ThaiFood {
public:
    MangoStickyRice() : ThaiFood("Mango Sticky Rice", 8.99) {}
};

class SomTum : public ThaiFood {
public:
    SomTum() : ThaiFood("Som Tum", 9.99) {}
};
#endif // FOOD_H
