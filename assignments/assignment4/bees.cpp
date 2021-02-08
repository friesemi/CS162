#include "bees.h"

//accessor
int Bees::getNumBees(){return numBees;}
int Bees::getBeesOnBoard(){return beesOnBoard;}

//mutator
void Bees::setNumBees(int numBees){numBees = numBees;}
void Bees::setBeesOnBoard(int beesOnBoard){beesOnBoard = beesOnBoard;}

//constructor
Bees::Bees():Insects(){
	attack = 1;
	armor = 3;
	numBees = 5;
	beesOnBoard = 0;
}

//virtual function
void Bees::spawning(string (&board)[5][11], int pos){
	board[0][pos] = "[B]";
	numBees -= 1;
	beesOnBoard += 1;
}

//virtual function
void Bees::attacking(string (&board)[5][11], int pos){
	cout << "Bees attack" << endl;
	for(int i = 1; i < 11; i++){
		for(int j = 1; j < 5; j++){
			if(board[j][i] == "[B]")
				beeAttack(board, j);
		}
	}
}

/*********************************************************************
** Function: bee attack
** Description: the bees attack the ants
** Parameters: the board and the position of the bee
** Pre-Conditions: the board is initialized and a bee is in attack range
** Post-Conditions: the ants are attacked
*********************************************************************/ 
void Bees::beeAttack(string (&board)[5][11], int pos){
	for(int i = 0; i < 1; i++){
		if(board[pos][i] != "[B]" && board[pos][i] != "[ ]"){
			//get type of ant to attack
		}
	}
}

/*********************************************************************
** Function: pop board
** Description: populates the board initially
** Parameters: the board that is created in main is taken in
** Pre-Conditions: the board must be created in main
** Post-Conditions: the board is filled from here
*********************************************************************/ 
void Bees::popBoard(string (&board)[5][11]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 11; j++){
			board[i][j] = "[ ]";
		}
	}
	board[0][0] = "[Q]";
	printBoard(board);
}

/*********************************************************************
** Function: print board
** Description: prints the board every turn
** Parameters: the board that is initialized is passed in by reference
** Pre-Conditions: the board is initialized
** Post-Conditions: the board is printed
*********************************************************************/ 
void Bees::printBoard(string (&board)[5][11]){
	cout << "Remaining bees: " << (numBees + beesOnBoard) << endl;
	for(int i = 0; i < 11; i++)
		cout << " " << i << " ";
	cout << endl;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 11; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: moving
** Description: handles movement of the bees
** Parameters: none
** Pre-Conditions: there needs to be a bee on the board
** Post-Conditions: the bee is moved one spot
*********************************************************************/ 
void Bees::moving(string (&board)[5][11]){
	int pos = 0;
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 5; j++){
			if(board[j][i] == "[B]"){
				pos = posCheck(board, i);
				board[pos][i-1] = "[B]";
				board[j][i] = "[ ]";
			}
		}
	}
}

/*********************************************************************
** Function: pos check
** Description: checks if the position of the movement is filled or not
** Parameters: an integer is passed in
** Pre-Conditions: the position is passed in
** Post-Conditions: the next open index is returned
*********************************************************************/ 
int Bees::posCheck(string (&board)[5][11], int pos){
	for(int i = 0; i < 5; i++){
		if(board[i][pos-1] != "[ ]" && board[i][pos-1] != "[Q]")
			;
		else
			return i;
	}
}