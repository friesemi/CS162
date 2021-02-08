#include "weapon.h"

int Weapon::getDamage(){return damage;}

void Weapon::setDamage(int damage){damage = damage;}

Weapon::Weapon():Equipment(){
	name = "Excalibur";
	value = 15;
	damage = 12;
}

void Weapon::print(){
	cout << "The weapon is: " << name << "\nDealing " << damage << " damage and worth " << value << endl;
}