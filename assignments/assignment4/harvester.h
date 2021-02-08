#ifndef HARVESTER_H
#define HARVESTER_H
#include "ants.h"

class Harvester: public Ants{
	private:


	public:
		Harvester();

		void spawning(string (&board)[5][11], int);
		void addFood(string (&board)[5][11]);
};
#endif