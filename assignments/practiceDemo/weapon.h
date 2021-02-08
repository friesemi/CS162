#ifndef WEAPON
#define WEAPON
#include "equipment.h"

class Weapon:public Equipment{
	private:
		int damage;
	public:
		int getDamage();

		void setDamage(int);

		Weapon();

		void print();
}; 	


#endif