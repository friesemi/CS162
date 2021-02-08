#include "game.h"

void Game::play(){
	Bees bee;
	Ants ant;
	Harvester harv;

	string board[5][11]; //2d to allow for stacking of ants/bees
	bee.popBoard(board);

	bee.spawning(board, 10);
	ant.spawnType(board);
	bee.printBoard(board);

	turn(board);
	if(board[0][0] == "[B]")
		cout << "RIP Queen" << endl;
	else
		cout << "Congrats! You win" << endl;
}

void Game::turn(string (&board)[5][11]){
	Bees bee;
	Ants ant;
	Harvester harv;

	while(bee.getBeesOnBoard() > -1 && board[0][0] == "[Q]"){	//add if statement for if queen is reached
		bee.moving(board);
		bee.spawning(board, 10);
		ant.spawnType(board);
		harv.addFood(board);
		ant.attacks(board);
		bee.printBoard(board);
	}
}