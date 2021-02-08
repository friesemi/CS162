#include "shape.h"

class Cube: public Shape{
	private:
		int side, side1, side2;

	public:
		int getSides();
		void setSides(int, int, int);

		Cube();
		float calculateArea();
		void printArea();
};
