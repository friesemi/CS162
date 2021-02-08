#include "circle.h"

int Circle::getRadius(){return radius;}
void Circle::setRadius(int radius){radius = radius;}

Circle::Circle(int radius, string name, string color): radius(radius), Shapes(name, color){}

void Circle::print(){
	cout << "The area of the " << color << name << " is: " << calculate(radius) << endl;
}

int Circle::calculate(int radius){
	int sum = 0;
	sum = radius * radius * 3.14;
	return sum;
}