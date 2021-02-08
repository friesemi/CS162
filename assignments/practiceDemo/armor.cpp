#include "armor.h"

int Armor::getProt(){return armor;}

void Armor::setProt(int armor){armor = armor;}

Armor::Armor(){
	armor = 23;
	name = "Chestpiece of Truth";
	value = 100;
}

void Armor::print(){
	cout << "This is the: " << name << " worth " << value << " gold and providing " << armor << " protection" << endl;
}