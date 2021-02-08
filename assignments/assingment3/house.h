#ifndef HOUSE_H
#define HOUSE_H
#include "property.h"

//no dynamic memory in here (only 1 tenant)
class House:public Property{
	private:
		citizens tens;
		House *houses;
		int rent;
	public:
		//accessors
		citizens getTens();
		House getHouses();
		int getRent();

		//mutators
		void setTens(citizens &);
		void setHouses(House &);
		void setRent(int);

		//constructor
		House();

		//destructor
		~House();

		//copy constructor
		House(const House &);

		//AOO
		House & operator=(const House &);

		string getPlace();
		void popHouse();
		void houseListing();
		void printHouses(House *);
};

#endif