#include "shape.h"

class Circle: public Shape{
private:
	int radius;

public:
	int getRadius();
	void setRadius(int);

	Circle();
	float calculateArea();
	void printArea();
};