#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace std;

class Shape{
protected:
	string name;
	string color;

public:
	string getName();
	string getColor();
	void setName(string);
	void setColor(string);


	Shape();
	virtual float calculateArea();
	virtual void printArea();
};
#endif