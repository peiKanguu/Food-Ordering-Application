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
	WesternRestaurant* hs = new WesternRestaurant("Hanouxi Snacks", 5);
    hs->addFood(new RoastChickenWing());
	hs->addFood(new TomatoBread());
	hs->addFood(new PanFriedFoieGras());
    hs->addFood(new FrenchFries());
    hs->addFood(new PopcornChicken());
    hs->addFood(new ChocolateThinCrisp());
	restaurants.push_back(hs);

    WesternRestaurant* fd = new WesternRestaurant("Flyok Delight", 1);
    fd->addFood(new GrilledRibeyeSteak());
    fd->addFood(new CaesarSalad());
    fd->addFood(new SpaghettiCarbonara());
    fd->addFood(new NewEnglandClamChowder());
    fd->addFood(new ApplePie());
    restaurants.push_back(fd);

    ArabicRestaurant* al = new ArabicRestaurant("Arz Lebanon", 5);
	al->addFood(new Hummus());
    al->addFood(new LambShawarma());
	al->addFood(new ShishKebab());
    al->addFood(new Labneh());
    al->addFood(new FalafelPlate());
    al->addFood(new ChickenKabsa());
    restaurants.push_back(al);

    ArabicRestaurant* ah = new ArabicRestaurant("Al Hallab", 10);
    ah->addFood(new LambShawarma());
    ah->addFood(new FalafelPlate());
    ah->addFood(new ChickenKabsa());
    ah->addFood(new FattoushSalad());
    ah->addFood(new Baklava());
    restaurants.push_back(ah);

    ChineseRestaurant* cs = new ChineseRestaurant("Chilli Secret", 5);
    cs->addFood(new BoiledFish());
	cs->addFood(new MapoTofu());
	cs->addFood(new KungPaoChicken());
	cs->addFood(new ChongqingChicken());
	cs->addFood(new TwiceCookedPork());
	cs->addFood(new SourPlumDrink());
    restaurants.push_back(cs);

	ChineseRestaurant* jg = new ChineseRestaurant("Jean-Georges", 10);
	jg->addFood(new SweetAndSourPork());
	jg->addFood(new NineFoldIntestine());
	jg->addFood(new ChickenMushroomSoup());
	jg->addFood(new PorkStewWithRiceNoodles());
	jg->addFood(new GinsengChickenSoup());
	restaurants.push_back(jg);

	ChineseRestaurant* qjd = new ChineseRestaurant("Quanjude", 1);
	qjd->addFood(new PekingDuck());
	qjd->addFood(new Zhajiangmian());
	qjd->addFood(new InstantBoiledMutton());
	qjd->addFood(new MendingMeatPie());
	qjd->addFood(new DeepFriedMeatballs());
	qjd->addFood(new GrilledMeat());
	restaurants.push_back(qjd);

	JapaneseRestaurant* sky = new JapaneseRestaurant("Sukiya", 10);
	sky->addFood(new Sushi());
	sky->addFood(new Tempura());
	sky->addFood(new Ramen());
	sky->addFood(new Sashimi());
	sky->addFood(new Yakitori());
	sky->addFood(new Takoyaki());
	sky->addFood(new MisoSoup());
	restaurants.push_back(sky);

	KoreanRestaurant* f = new KoreanRestaurant("Flavors", 10);
	f->addFood(new Bibimbap());
	f->addFood(new Tteokbokki());
	f->addFood(new Bulgogi());
	f->addFood(new Kimchi());
	f->addFood(new BudaeJjigae());
	restaurants.push_back(f);

	ThaiRestaurant* Saffron = new ThaiRestaurant("Saffron", 5);
	Saffron->addFood(new PadThai());
	Saffron->addFood(new TomYumGoong());
	Saffron->addFood(new GreenCurry());
	Saffron->addFood(new ThaiFriedRice());
	Saffron->addFood(new RedCurry());
	Saffron->addFood(new BasilChicken());
	Saffron->addFood(new PapayaSalad());
	Saffron->addFood(new ThaiDessert());
	restaurants.push_back(Saffron);

	//system.login();
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
			cout << "You are viewing your order history." << endl << endl;
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

