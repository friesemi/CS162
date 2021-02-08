#ifndef TRI
#define TRI
#include "shapes.h"

class Triangle: public Shapes{
	private:
		int base;
		int height;
	public:
		int getBase();
		int getHeight();
		void setBase(int);
		void setHeight(int);

		Triangle(int base, int height, string name, string color);

		void print();
		int calculate();
	};
	#endif