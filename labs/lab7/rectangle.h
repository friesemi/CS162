#include "shape.h"

class Rectangle: public Shape{
private:
	int length, width;

public:
	int getLength();
	int getWidth();
	void setLength(int);
	void setWidth(int);

	Rectangle();
	float calculateArea();
	void printArea();

};