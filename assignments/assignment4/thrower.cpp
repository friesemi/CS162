#include "thrower.h"

Thrower::Thrower(){
	armor = 1;
}

//virtual function
void Thrower::spawning(string (&board)[5][11], int pos){
	if(board[0][pos] != "[ ]")
		cout << "Invalid spawn location" << endl;
	else{
		cout << "Spawning a thrower ant\n";
		board[0][pos] = "[t]";
		Ants::food -= 4;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}

//virtual function
void Thrower::attacking(string (&board)[5][11]){
	Bees bee;
	for(int i = 1; i < 11; i++){
		if(board[0][1] == "[t]" && (board[0][i] == "[B]" || board[1][i] == "[B]")){
			cout << "Attacks: " << endl;
			cout << bee.getArmor() << endl;
			bee.setArmor((bee.getArmor() - attack));
			cout << "New armor: " << bee.getArmor() << endl;
		}
	}
}