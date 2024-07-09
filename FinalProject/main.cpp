#include "System.h"
#include "Restaurant.h"

int main() {
	System system;
	// Add users
	system.addUsers(new User("Pei", "Kang", "Pei Kang", "pk123456", "123456"));  // Admin
	system.addUsers(new User("John", "Doe", "John Doe", "jd123456", "123456"));
	system.addUsers(new User("Jane", "Doe", "Jane Doe", "jd654321", "654321"));
	system.addUsers(new User("Alice", "Smith", "Alice Smith", "as123456", "123456"));
	system.addUsers(new User("Bob", "Brown", "Bob Brown", "bb123456", "123456"));
	system.addUsers(new User("Charlie", "White", "Charlie White", "cw123456", "123456"));
	system.addUsers(new User("David", "Black", "David Black", "db123456", "123456"));
    
    // Display a default user for teacher to test
	cout << "Default account for teachers: " << endl;
	system.getDefaultUser()->displayAccount();

    vector<Restaurant*> restaurants;
    // Add restaurant and corresponding food items
    WesternRestaurant* wr = new WesternRestaurant("Western Delight", 1);
    wr->addFood(new GrilledRibeyeSteak());
    wr->addFood(new CaesarSalad());
    wr->addFood(new SpaghettiCarbonara());
    wr->addFood(new NewEnglandClamChowder());
    wr->addFood(new ApplePie());
    restaurants.push_back(wr);

    ArabicRestaurant* ar1 = new ArabicRestaurant("Arabic Feast", 5);
    ar1->addFood(new LambShawarma());
    ar1->addFood(new FalafelPlate());
    ar1->addFood(new ChickenKabsa());
    ar1->addFood(new FattoushSalad());
    ar1->addFood(new Baklava());
    restaurants.push_back(ar1);

    ArabicRestaurant* ar2 = new ArabicRestaurant("Bedouin Feast", 10);
    ar2->addFood(new LambShawarma());
    ar2->addFood(new FalafelPlate());
    ar2->addFood(new ChickenKabsa());
    ar2->addFood(new FattoushSalad());
    ar2->addFood(new Baklava());
    restaurants.push_back(ar2);

    ArabicRestaurant* ar3 = new ArabicRestaurant("Oasis Delights", 1);
    ar3->addFood(new LambShawarma());
    ar3->addFood(new FalafelPlate());
    ar3->addFood(new ChickenKabsa());
    ar3->addFood(new FattoushSalad());
    ar3->addFood(new Baklava());
    restaurants.push_back(ar3);

    ChineseRestaurant* cr = new ChineseRestaurant("Chinese Delight", 5);
    cr->addFood(new KungPaoChicken());
    cr->addFood(new DimSumPlatter());
    cr->addFood(new PekingDuck());
    cr->addFood(new MapoTofu());
    cr->addFood(new SweetAndSourPork());
    restaurants.push_back(cr);

    JapaneseRestaurant* jr = new JapaneseRestaurant("Japanese Cuisine", 10);
    jr->addFood(new SushiPlatter());
    jr->addFood(new RamenBowl());
    jr->addFood(new Tempura());
    jr->addFood(new TeriyakiChicken());
    jr->addFood(new MatchaIceCream());
    restaurants.push_back(jr);

    KoreanRestaurant* kr = new KoreanRestaurant("Korean Delight",1 );
    kr->addFood(new Bibimbap());
    kr->addFood(new KimchiJjigae());
    kr->addFood(new KoreanBBQ());
    kr->addFood(new Japchae());
    kr->addFood(new Tteokbokki());
    restaurants.push_back(kr);

    ThaiRestaurant* tr = new ThaiRestaurant("Thai Spice", 5);
    tr->addFood(new PadThai());
    tr->addFood(new GreenCurry());
    tr->addFood(new TomYumSoup());
    tr->addFood(new MangoStickyRice());
    tr->addFood(new SomTum());
    restaurants.push_back(tr);

	system.login();
	system.clearScreen();

	int choice;
	do {
		printMenu();
		cout << CYAN << "===> Enter your choice: ";
		cin >> choice;
		cout << RESET;
		switch (choice) {
        case 1: {
            system.clearScreen();
            cout << "You are taking a new order." << endl << endl;
            system.newOrder(restaurants);
            break;
        }
        case 2: {
			system.clearScreen();
			// check if previous orders exist
			if (system.getOrders().empty()) {
				cout << RED << "No previous orders found." << RESET << endl;
				break;
			}
			cout << "You are viewing your order history." << endl;
			system.viewOrderHistory();
			system.reorder();
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << RED << "Invalid choice. Try again.\n" << RESET;
        }
    }while (choice != 3);

	return 0;
}

