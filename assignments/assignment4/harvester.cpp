#include "harvester.h"

Harvester::Harvester(){
	armor = 1;
}

//virtual function
void Harvester::spawning(string (&board)[5][11], int pos){
	if(board[0][pos] != "[ ]")
		cout << "Invalid spawn location" << endl;
	else{
		cout << "Spawning a harvester ant\n";
		board[0][pos] = "[h]";
		Ants::food -= 2;
	}
	cout << "Remaining food is: " << Ants::food << endl << endl;
}

/*********************************************************************
** Function:add food
** Description: adds food to the users food
** Parameters: none
** Pre-Conditions: the food must be initiated
** Post-Conditions: for each harvester there is 1 food added to the total at the beginning of the turn
*********************************************************************/ 
void Harvester::addFood(string (&board)[5][11]){
int numHarv = 0;
for(int i = 1; i < 11; i++){
	if(board[0][i] == "[h]")
		numHarv++;
}
for(int i = 0; i < numHarv; i++){
	Ants::food += 1;
}
}