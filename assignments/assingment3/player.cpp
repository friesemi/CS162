#include "player.h"
 
 //accessors
int Player::getBank(){
	return bank;
}

int Player::getNumHouses(){
	return numHouses;
}

int Player::getNumApps(){
	return numApps;
}

int Player::getNumBus(){
	return numBus;
}

House Player::getOHouse(){
	return *ownedHouse;
}

Apartment Player::getOApp(){
	return *ownApp;
}

Business Player::getOBus(){
	return *ownBus;
}


//mutators
void Player::setBank(int bank){
	bank = bank;
}

void Player::setNumHouses(int numHouses){
	numHouses = numHouses;
}

void Player::setNumApps(int numApps){
	numApps = numApps;
}

void Player::setNumBus(int numBus){
	numBus = numBus;
}

void Player::setOHouse(House *ownedHouse){
	ownedHouse = ownedHouse;
}

void Player::setOApp(Apartment *ownApp){
	ownApp = ownApp;	
}

void Player::setOBus(Business *ownBus){
	ownBus = ownBus;
}

//constructor
Player::Player(){
	bank = 500000;
	numHouses = 0;
	numApps = 0;
	numBus = 0;
}

//destructor
Player::~Player(){
	delete [] ownedHouse;
	delete [] ownApp;
	delete [] ownBus;
	cout << " Delete " << endl;
}

//copy constructor
Player::Player(const Player &other){
	bank = other.bank;
}

//AOO
Player & Player::operator=(const Player &other){
	bank = other.bank;
	return *this;
}

/*
 *Function: welcome
 *Description: the basic welcoming function
 *Parameters: none
 *Input: none
 *Output: the player is welcomed and the game continues
 */
void Player::welcome(){
	int turn = 1;
	cout << "\tWelcome to Property Tycoon!" << endl;
	cout << "The rules are simple...\nYou have $500,000 and need to make a $1,000,000\n";
	cout << "Can you become a millionare?\n";
	firstTurn();
	turn += 1;
	while(bank < 1000000 && bank > 0){
		cout << "\nYou have $" << bank << "\n\n";
		cout << "Turn: " << turn << endl;
		randEvent();
		if(turn == 12)
			;//run tax collection function
		choice();
		turn += 1;
		cout << "Investments gain you $100000!" << endl;
		bank += 100000;
	}
	if(bank >= 1000000){
		cout << "\n\tYou win!! Congratualations!!" << endl;
		exit(0);
	}
	else if(bank < 0){
		cout << "\n\tYou lose. Better luck next time." << endl;
		exit(0);
	}
}

/*
 *Function: first turn
 *Descriprion: carries out the first turn of the game
 *Parameters: none
 *Input: none
 *Output: the first turn is played out
 */
void Player::firstTurn(){
	int turn = 1;
	cout << "\nYou have $" << bank << "\n\n";
	cout << "Turn: " << turn << endl;
	choice();
}

/*
 *Function: choices
 *Description: allows the user to decide what they want to do
 *Parameters: none
 *Input: none
 *Output: the user chooses their action
 */
void Player::choice(){
	int choose = 0;
	Property prop;
	House house;
	Apartment app;
	Business bus;
	house.houseListing();
	app.apartmentListing();
	bus.businessListing();
	cout << "Would you like to buy, sell, or change rent? (1, 2, or 3): ";
	do{
		choose = prop.intCheck();
	}while(choose != 1 && choose != 2 && choose != 3);
}

/*
 *Function: random event
 *Description: decides if a random event occurs to the properties
 *Parameters: none
 *Input: none
 *Output: a random event occurs and property value is affected
 */
void Player::randEvent(){
	int event = 0;
	event = rand() % 6 + 1;
	if(event == 1){
		cout << "A Hurricane Occurs!\n\n";
		locEvent("SE", .5);
	}
	else if(event == 2){
		cout << "A Tornado Occurs!\n\n";
		locEvent("Midwest", .7);
	}
	else if(event == 3){
		cout << "An Earthquake Occurs!\n\n";
		locEvent("NW", .9);
	}
	else if(event == 4){
		cout << "A Wildfire Occurs!\n\n";
		locEvent("SW", .75);
	}
	else if(event == 5){
		cout << "The Stock Market Crashes!\n\n";
		locEvent1(.7);
	}
	else if(event == 6){
		cout << "Lucky You! Gentrification Occurs!\n\n";
		locEvent2(1.2);
	}
}

/*
 *Function: location event
 *Description: checks the location of properties to see if they're affected
 *Parameters: a string
 *Input: the location is passed to the function
 *Output: it is decided if the event affects the properties
 */
void Player::locEvent(string loc, float mult){
	for(int i = 0; i < numHouses; i++){
		if(ownedHouse[i].getLocation() == loc)
			ownedHouse[i].getPValue() * mult;
	}
	for(int i = 0; i < numApps; i++){
		if(ownApp[i].getLocation() == loc)
			ownApp[i].getPValue() * mult;
	}
	for(int i = 0; i < numBus; i++){
		if(ownBus[i].getLocation() == loc)
			ownBus[i].getPValue() * mult;
	}
}

/*
 *Function: location event 1
 *Description: changes property value of all properties
 *Parameters: a float
 *Input: the multiplier is passed in
 *Output: the property value of all properties is changed
 */
void Player::locEvent1(float mult){
	for(int i = 0; i < numHouses; i++)
		ownedHouse[i].getPValue() * mult;
	for(int i = 0; i < numApps; i++)
		ownApp[i].getPValue() * mult;
	for(int i = 0; i < numBus; i++)
		ownBus[i].getPValue() * mult;
}


/*
 *Function: location event 2
 *Description: chooses a random location to be affected
 *Parameters: a float
 *Input: the multiplier is passed in
 *Output: the property value is changed
 */
void Player::locEvent2(float mult){
	int location = rand() % 5 + 1;
	if(location == 1){
		for(int i = 0; i < numHouses; i++){
			if(ownedHouse[i].getLocation() == "SE")
				ownedHouse[i].getPValue() * mult;
		}
		for(int i = 0; i < numApps; i++){
			if(ownApp[i].getLocation() == "SE")
				ownApp[i].getPValue() * mult;
		}
		for(int i = 0; i < numBus; i++){
			if(ownBus[i].getLocation() == "SE")
				ownBus[i].getPValue() * mult;
		}
	}
	else if(location == 2){
		for(int i = 0; i < numHouses; i++){
			if(ownedHouse[i].getLocation() == "NE")
				ownedHouse[i].getPValue() * mult;
		}
		for(int i = 0; i < numApps; i++){
			if(ownApp[i].getLocation() == "NE")
				ownApp[i].getPValue() * mult;
		}
		for(int i = 0; i < numBus; i++){
			if(ownBus[i].getLocation() == "NE")
				ownBus[i].getPValue() * mult;
		}
	}
	else if(location == 3){
		for(int i = 0; i < numHouses; i++){
			if(ownedHouse[i].getLocation() == "Midwest")
				ownedHouse[i].getPValue() * mult;
		}
		for(int i = 0; i < numApps; i++){
			if(ownApp[i].getLocation() == "Midwest")
				ownApp[i].getPValue() * mult;
		}
		for(int i = 0; i < numBus; i++){
			if(ownBus[i].getLocation() == "Midwest")
				ownBus[i].getPValue() * mult;
		}
	}
	else if(location == 4){
		for(int i = 0; i < numHouses; i++){
			if(ownedHouse[i].getLocation() == "SW")
				ownedHouse[i].getPValue() * mult;
		}
		for(int i = 0; i < numApps; i++){
			if(ownApp[i].getLocation() == "SW")
				ownApp[i].getPValue() * mult;
		}
		for(int i = 0; i < numBus; i++){
			if(ownBus[i].getLocation() == "SW")
				ownBus[i].getPValue() * mult;
		}
	}
	else if(location == 5){
		for(int i = 0; i < numHouses; i++){
			if(ownedHouse[i].getLocation() == "NE")
				ownedHouse[i].getPValue() * mult;
		}
		for(int i = 0; i < numApps; i++){
			if(ownApp[i].getLocation() == "NE")
				ownApp[i].getPValue() * mult;
		}
		for(int i = 0; i < numBus; i++){
			if(ownBus[i].getLocation() == "NE")
				ownBus[i].getPValue() * mult;
		}
	}
}