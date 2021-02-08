#include "ninja.h"

Ninja::Ninja(){
	armor = 1;
	attack = 1;
}

//virtual function
void Ninja::spawning(string (&board)[5][11],int pos){
	if(board[0][pos] != "[ ]")
		cout << "Invalid spawn location" << endl;
	else{
		cout << "Spawning a ninja ant\n";
		board[0][pos] = "[n]";
		Ants::food -= 6;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}

//virtual function
void Ninja::attacking(string (&board)[5][11]){
	Bees bee;
	for(int i = 1; i < 11; i++){
		if(board[0][i] == "[n]" && (board[1][i] == "[B]" || board[2][i] == "[B]")){
			cout << "Attacks: " << endl;
			cout << bee.getArmor() << endl;
			bee.setArmor((bee.getArmor() - attack));
			cout << "New armor: " << bee.getArmor() << endl;
			//bee.getArmor() = bee.getArmor() - attack;
		}
	}
}