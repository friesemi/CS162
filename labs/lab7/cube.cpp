#include "cube.h"

int Cube::getSides(){
	return side, side1, side2;
}

void Cube::setSides(int side, int side1, int side2){
	side = side;
	side1 = side1;
	side2 = side2;
}

Cube::Cube(){
	name = "\"cube\"";
	color = "green ";
	side = 5;
	side1 = 5;
	side2 = 3;
}

float Cube::calculateArea(){
	return (side * side1 * side2); 
}

void Cube::printArea(){
	cout << "The volume of the " << color << name << "is: " << calculateArea() << endl;
}