#ifndef WALL_H
#define WALL_H
#include "ants.h"

class Wall: public Ants{
	private:


	public:
		Wall();
		
		void spawning(string (&board)[5][11], int);
};
#endif