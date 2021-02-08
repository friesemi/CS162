/*
 *Program Filename: driver.cpp 
 *Author: Michael Friesen
 *Date: 4/28/2018
 *Description: A classic pizza ordering system
 *Input: Several files input information
 *Output: The same files receive the output of the functions
 */
#include "pizza.h"
#include "menu.h"
#include "restaurant.h"
#include "structs.h"

using namespace std;

int main(){
	Restaurant restObj;

	restObj.pop_rest();
	restObj.pop_emp();
	restObj.pop_menu();

	restObj.welcome_fun(restObj.get_name());

	return 0;
}