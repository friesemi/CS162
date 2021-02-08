#ifndef THROWER_H
#define THROWER_H
#include "ants.h"
#include "bees.h"

class Thrower: public Ants{
	private:

	public:
		Thrower();

		void spawning(string (&board)[5][11], int);
		void attacking(string (&board)[5][11]);
};

#endif