/*
 *Program Name: Property Tycoon
 *Author: Michael Friesen
 *Date: 5/12/2018
 *Description: A game for becoming a millionaire through property management
 *Input: the user inputs several minor commands
 *Output: the game is carried out, displaying property information along the way
 */
#include "player.h"

int main(){
	srand(time(NULL));
	Player play;
	play.welcome();
	return 0;
}
