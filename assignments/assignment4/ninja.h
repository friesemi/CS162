#ifndef NINJA_H
#define NINJA_H
#include "ants.h"
#include "bees.h"

class Ninja: public Ants{
	private:


	public:
		Ninja();

		void spawning(string (&board)[5][11], int);
		void attacking(string (&board)[5][11]);
};
#endif