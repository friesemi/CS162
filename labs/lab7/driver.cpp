 #include "circle.h"
#include "rectangle.h"
#include "cube.h"

int main(){
	Rectangle rect;
	Circle circ;
	Cube cub;

	/*Shape *ptrShape1 = &rect;
	Shape *ptrShape2 = &circ;
	Shape *ptrShape3 = &cub;

	ptrShape1->printArea();
	ptrShape2->printArea(); 
	ptrShape3->printArea();*/

	Shape **ptrShape = new Shape*[3];
	ptrShape[0] = &rect;
	ptrShape[1] = &circ;
	ptrShape[2] = &cub;

	for(int i = 0; i < 3; i++){
		ptrShape[i]->printArea();
	}
	delete ptrShape;
	return 0;
}