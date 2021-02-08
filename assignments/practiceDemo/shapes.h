#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Shapes{
	protected:
		string name;
		string color;
	public:
		string getName();
		string getColor();
		void setName(string);
		void setColor(string);
		Shapes(string name, string color);
		virtual void print();
};

#endif
