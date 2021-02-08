#ifndef FIRE_H
#define FIRE_H
#include "ants.h"

class Fire: public Ants{
	private:


	public:
		Fire();

		void spawning(string (&board)[5][11], int);
		void attacking();
};

#endif