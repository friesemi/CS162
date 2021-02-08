#ifndef GAME_H
#define GAME_H
#include "bees.h"
#include "harvester.h"
#include "thrower.h"
#include "fire.h"
#include "longThrower.h"
#include "shortThrower.h"
#include "wall.h"
#include "ninja.h"
#include "bodyguard.h"

class Game{
	public:
		void play();
		void turn(string (&board)[5][11]);
};

#endif