#include "equipment.h"

string Equipment::getName(){return name;}
int Equipment::getValue(){return value;}

void Equipment::setName(string name){name = name;}
void Equipment::setValue(int value){value = value;}

Equipment::Equipment(){
	name = "";
	value = 0;
}

void Equipment::print(){
	cout << "Name: " << name << "\nValue: " << value << endl;
}