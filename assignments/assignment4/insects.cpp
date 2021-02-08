#include "insects.h"

//accessors
string Insects::getName(){return name;}
int Insects::getArmor(){return armor;}
int Insects::getAttack(){return attack;}

//mutators
void Insects::setName(string name){name = name;}
void Insects::setArmor(int armor){armor = armor;}
void Insects::setAttack(int attack){attack = attack;}

//default constructor
Insects::Insects(){
	name = "none";
	armor = 0;
	attack = 0;
}

