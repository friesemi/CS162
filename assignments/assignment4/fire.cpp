#include "fire.h"

Fire::Fire(){
	armor = 1;
}

//virtual function
void Fire::spawning(string (&board)[5][11], int pos){
	if(board[0][pos] != "[ ]")
		cout << "Invalid spawn location" << endl;
	else{
		cout << "Spawning a fire ant\n";
		board[0][pos] = "[f]";
		Ants::food -= 4;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}