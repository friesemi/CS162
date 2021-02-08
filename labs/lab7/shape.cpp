#include "shape.h"

string Shape::getName(){return name;}
string Shape::getColor(){return color;}

void Shape::setName(string name){name = name;}
void Shape::setColor(string color){color = color;}

Shape::Shape(){
	name ="none";
	color = "none";
}

float Shape::calculateArea(){
	return (1 * 1);
}

void Shape::printArea(){
	cout << "The area is: " << calculateArea() << endl;
}