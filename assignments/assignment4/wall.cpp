#include "wall.h"

Wall::Wall(){
	armor = 4;
}

//virtual function
void Wall::spawning(string (&board)[5][11], int pos){
	if(board[0][pos] != "[ ]")
		cout << "Invalid spawn location" << endl;
	else{
		cout << "Spawning a wall\n";
		board[0][pos] = "[w]";
		Ants::food -= 4;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}