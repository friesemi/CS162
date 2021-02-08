#ifndef CIRCLE
#define CIRCLE
#include "shapes.h"

class Circle: public Shapes{
	private:
		int radius;
	public:
		int getRadius();
		void setRadius(int radius);

		Circle(int radius, string name, string color); 

		void print();
		int calculate(int);
};
#endif