#include "shapes.h"

string Shapes::getName(){return name;}
string Shapes::getColor(){return color;}
void Shapes::setName(string name){name = name;}
void Shapes::setColor(string color){color = color;}

Shapes::Shapes(string name, string color): name(name), color(color){}

void Shapes::print(){
	cout << "Name is: " << name << endl;
}