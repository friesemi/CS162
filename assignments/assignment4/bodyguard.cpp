#include "bodyguard.h"

Bodyguard::Bodyguard(){
	armor = 2;
}

//virtual function
void Bodyguard::spawning(string (&board)[5][11], int pos){
	if(board[0][pos] != "[ ]" && board[1][pos] != "[ ]")
		cout << "invalid spawn location" << endl;
	else if(board[0][pos] != "[B]" && board[0][pos] != "[ ]"){
		cout << "Spawning a bodyguard\n";
		board[1][pos] = "[b]";
		food -= 4;
	}
	else{
		cout << "Spawning a bodyguard\n";
		board[0][pos] = "[b]";
		food -= 4;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}