#ifndef LONGTHROWER_H
#define LONGTHROWER_H
#include "ants.h"
#include "bees.h"

class LongThrower: public Ants{
	private:


	public:
		LongThrower();

		void spawning(string (&board)[5][11], int);
		void attacking(string (&board)[5][11]);
};
#endif