#include "triangle.h"

int Triangle::getBase(){return base;}
int Triangle::getHeight(){return height;}

void Triangle::setBase(int base){base = base;}
void Triangle::setHeight(int height){height = height;}

Triangle::Triangle(int base, int height, string name, string color): base(base), height(height), Shapes(name, color){}

void Triangle::print(){
	cout << "The area of the " << color << " " << name << " is " << calculate() << endl;
}

int Triangle::calculate(){
	int sum = 0;
	sum = (base*height)/2;
	return sum;
}