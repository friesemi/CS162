#include "shortThrower.h"

ShortThrower::ShortThrower(){
	armor = 1;
}

//virtual function
void ShortThrower::spawning(string (&board)[5][11], int pos){
	if(board[0][pos] != "[ ]")
		cout << "Invalid spawn location" << endl;
	else{
		cout << "Spawning a short thrower ant\n";
		board[0][pos] = "[s]";
		Ants::food -= 3;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}

//virtual function
void ShortThrower::attacking(string (&board)[5][11]){
	Bees bee;
	for(int i = 1; i < 11; i++){
		if(board[0][1] == "[s]" && (board[0][i+2] == "[B]" || board[1][i+2] == "[B]")){
			cout << "Attacks: " << endl;
			cout << bee.getArmor() << endl;
			bee.setArmor((bee.getArmor() - attack));
			cout << "New armor: " << bee.getArmor() << endl;
		}
	}
}