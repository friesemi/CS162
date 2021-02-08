#ifndef PLAYER_H
#define PLAYER_H
#include "house.h"
#include "apartment_complex.h"
#include "business_complex.h"

class Player{
	private:
		int bank;
		int numHouses;
		int numApps;
		int numBus;
		House *ownedHouse;
		Apartment *ownApp;
		Business *ownBus;

	public:
		//accessor
		int getBank();
		int getNumHouses();
		int getNumApps();
		int getNumBus();
		House getOHouse();
		Apartment getOApp();
		Business getOBus();

		//mutator
		void setBank(int);
		void setNumHouses(int);
		void setNumApps(int);
		void setNumBus(int);
		void setOHouse(House *);
		void setOApp(Apartment *);
		void setOBus(Business *);

		//constructor
		Player();

		//destructor
		~Player();

		//copy constructor
		Player(const Player &);

		//AOO
		Player & operator=(const Player &);


		void welcome();
		void firstTurn();
		void choice();

		void randEvent();
		void locEvent(string, float);
		void locEvent1(float);
		void locEvent2(float);
};

#endif