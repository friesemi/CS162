#include "circle.h"

int Circle::getRadius(){return radius;}
void Circle::setRadius(int){radius = radius;}

Circle::Circle(){
	name = "circle";
	color = "red ";
	radius = 3;
}

float Circle::calculateArea(){
	return (3.14 * (radius * radius));
}

void Circle::printArea(){
	cout << "The area of the " << color << name << " with radius of: " << radius << " is: " << calculateArea() << endl;
}