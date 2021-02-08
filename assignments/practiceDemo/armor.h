#ifndef ARMOR
#define ARMOR
#include "equipment.h"

class Armor:public Equipment{
	private:
		int armor;
	public:
		int getProt();

		void setProt(int);

		Armor();

		void print();
};

#endif