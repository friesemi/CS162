#include "rectangle.h"

int Rectangle::getLength(){return length;}
int Rectangle::getWidth(){return width;}

void Rectangle::setLength(int length){length = length;}
void Rectangle::setWidth(int width){width = width;}

Rectangle::Rectangle(){
	name = "rectangle";
	color = "blue ";
	length = 5;
	width = 4;
}

float Rectangle::calculateArea(){
	return (length * width);
}

void Rectangle::printArea(){

	cout << "The area of the " << color << name << " with length of: " << length << " and width of: " << width << " is: " << calculateArea() << endl;
}