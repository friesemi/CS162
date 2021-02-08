#ifndef BODYGUARD_H
#define BODYGUARD_H
#include "ants.h"

class Bodyguard: public Ants{
	private:


	public:
		Bodyguard();

		void spawning(string (&board)[5][11], int);
};
#endif