#include "ants.h"
#include "harvester.h"
#include "thrower.h"
#include "fire.h"
#include "longThrower.h"
#include "shortThrower.h"
#include "wall.h"
#include "ninja.h"
#include "bodyguard.h"

//accessor
string Ants::getUserIn(){return userIn;}

//mutator
void Ants::setUserIn(string userIn){userIn = userIn;}

//constructor
int Ants::food = 50;
Ants::Ants():Insects(){
	userIn = "";
}

//virtual spawner
void Ants::spawning(string (&board)[5][11], int pos){
	cout << "This is the ant spawner\n" << pos << endl;
}

//virtual attack
void Ants::attacking(string (&board)[5][11], int pos){
	cout << "This is the basic attack\n" << pos << endl;
}

/*********************************************************************
** Function: pop board
** Description: populates the board initially
** Parameters: the board that is created in main is taken in
** Pre-Conditions: the board must be created in main
** Post-Conditions: the board is filled from here
*********************************************************************/ 
void Ants::popBoard(string (&board)[5][11]){
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
void Ants::printBoard(string (&board)[5][11]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 11; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: spawn type
** Description: allows the user to choose the ant they want to spawn
** Parameters: the board is taken in to pass around
** Pre-Conditions: the board must be filled
** Post-Conditions: the user chooses which ant they want
*********************************************************************/ 
void Ants::spawnType(string (&board)[5][11]){
		cout << "The codes for the ant types are:\n";
		cout << "h = harvester\nt = thrower\nf = fire\nl = long thrower\ns = short thrower\n";
		cout << "w = wall\nn = ninja\nb = bodyguard\n";
	do{
		cout << "\tPlease enter the type of ant you'd like to add:\n";
		cin >> userIn;
	}while(userIn != "h" && userIn != "t" && userIn != "f" && userIn != "l" && userIn != "s" && userIn != "w" && userIn != "n" && userIn != "b");
	int pos = 0;
	do{
		cout << "Enter the position you'd like to add the ant(1-10):\n";
		pos = intCheck();
	}while(pos < 1 && pos > 9);
	spawnAnt(board, userIn, pos);
}

/*********************************************************************
** Function: spawn ant
** Description: the hub for spawning each type of ant
** Parameters: the board and the users choice for ant are taken in
** Pre-Conditions: the user makes a decision
** Post-Conditions: the desired ant is added to the board
*********************************************************************/ 
void Ants::spawnAnt(string (&board)[5][11], string userIn, int pos){
	Harvester harv;
	Thrower thwr;
	Fire fire;
	LongThrower longT;
	ShortThrower shortT;
	Wall wall;
	Ninja ninja;
	Bodyguard body;
	if(userIn == "h")
		harv.spawning(board, pos);
	else if(userIn == "t")
		thwr.spawning(board, pos);
	else if(userIn == "f")
		fire.spawning(board, pos);
	else if(userIn == "l")
		longT.spawning(board, pos);
	else if(userIn == "s")
		shortT.spawning(board, pos);
	else if(userIn == "w")
		wall.spawning(board, pos);
	else if(userIn == "n")
		ninja.spawning(board, pos);
	else if(userIn == "b")
		body.spawning(board, pos);
}

/*********************************************************************
** Function: attacks
** Description: designates what attack is carried out
** Parameters: the board
** Pre-Conditions: the board is initialized
** Post-Conditions: the attacks are carried out
*********************************************************************/ 
void Ants::attacks(string (&board)[5][11]){
	Thrower thrower;
	LongThrower lThrower;
	ShortThrower sThrower;
	Ninja ninja;

	for(int i = 1; i < 11; i++){
		if(board[0][i] == "[t]")
			thrower.attacking(board);
		else if(board[0][i] == "[l]")
			lThrower.attacking(board);
		else if(board[0][i] == "[s]")
			sThrower.attacking(board);
		else if(board[0][i] == "[n]")
			ninja.attacking(board);
	}
}

/*********************************************************************
** Function: int check
** Description: checks if the user input is a valid integer
** Parameters: none
** Pre-Conditions: the integer is inputted from the user
** Post-Conditions: the correct input is returned
*********************************************************************/ 
int Ants::intCheck(){
	string checker;
	int integer = 0;
	bool test;
	do{
		cout << "Enter an integer: ";
		getline(cin, checker);
		int len = checker.length();

		for(int i = 0; i < len; i++){
			if(checker[i] < 48 || checker[i] > 57){
				test = false;
				break;
			}
			else{
			test = true;
			}
		}
	}while(test == false);
		int len2 = checker.length();
	for(int j = 0; j < len2; j++){
		integer += ((int)checker[j] - 48) * (pow(10, len2 - j - 1));
	}
	return integer;
}