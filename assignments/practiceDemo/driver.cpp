#include "circle.h"
#include "triangle.h"

int main(){
	Circle cir(5, "circle", "green");
	cir.print();

	Triangle tri(5, 4, "triangle", "blue");
	tri.print();

	return 0;
}