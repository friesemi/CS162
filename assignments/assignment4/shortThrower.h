#ifndef SHORTTHROWER_H
#define SHORTTHROWER_H
#include "ants.h"
#include "bees.h"

class ShortThrower: public Ants{
	private:


	public:
		ShortThrower();

		void spawning(string (&board)[5][11], int);
		void attacking(string (&board)[5][11]);
};
#endif