#include "property.h"


//accessors
int Property::getIndex(){
	return index;
}
float Property::getPValue(){
	return propertyValue;
}

string Property::getLocation(){
	return location;
}

float Property::getMortgage(){
	return mortgage;
}

float Property::getPTax(){
	return propertyTax;
}

int Property::getNumTens(){
	return numTens;
}


//mutators
void Property::setIndex(int index){
	index = index;
}

void Property::setPValue(float propertyValue){
	propertyValue = propertyValue;
}

void Property::setLocation(string location){
	location = location;
}

void Property::setMortgage(float mortgage){
	mortgage = mortgage;
}

void Property::setPTax(float propertyTax){
	propertyTax = propertyTax;
}

void Property::setNumTens(int numTens){
	numTens = numTens;
}


//nondefault constructor
Property::Property(){
	index = 0;
	propertyValue = 0;
	location = "";
	mortgage = 0;
	propertyTax = .015;
	numTens = 0;
}

//copy constructor
Property::Property(const Property &other){
	index = other.index;
	propertyValue = other.propertyValue;
	location = other.location;
	mortgage = other.mortgage;
	propertyTax = other.propertyTax;
}

//AOO
Property & Property::operator=(const Property &other){
	index = other.index;
	propertyValue = other.propertyValue;
	location = other.location;
	mortgage = other.mortgage;
	propertyTax = other.propertyTax;
	return *this;
}

/*bool Property::operator>(const Property &p){
	if(propertyValue > p.propertyValue && numTens > p.numTens)
		return true;
	return false;
}

bool Property::operator<(const Property &p){
	if(propertyValue < p.propertyValue && numTens < p.numTens)
		return true;
	return false;
}*/

/*
 *Function: fill citizen
 *Description: creates a citizen with a monthly budget and agreeability
 *Parameters: none
 *Input: none
 *Output: a citizen is output to the system
 */
citizens Property::fillCitizen(){
	citizens cit;
	cit.agreeability = rand() % 5 + 1;
	cit.monthlyBudget = rand() % 4501 + 500;
	return cit;
}

/*
 *Function: fill business
 *Description: creates a business with agreeability and budget
 *Parameters: none
 *Input: none
 *Output: a business is output to the system
 */
busPeople Property::fillBusPeople(){
	busPeople bus;
	bus.agreeability = rand() % 5 + 1;
	bus.monthlyBudget = rand() % 8001 + 2000;
	return bus;
}

/*
 *Function: int check
 *Description: checks if an integer is valid
 *Parameters: none
 *Input: none
 *Output: a valid integer
 */
int Property::intCheck(){
	string checker;
	int integer = 0;
	bool test;
	do{
		cout << "Enter an integer: ";
		getline(cin, checker);
		int len = checker.length();

		for(int i = 0; i < len; i++){
			if(checker[i] < 48 || checker[i] > 57){
				test = false;
				break;
			}
			else{
			test = true;
			}
		}
	}while(test == false);
		int len2 = checker.length();
	for(int j = 0; j < len2; j++){
		integer += ((int)checker[j] - 48) * (pow(10, len2 - j - 1));
	}
	return integer;
}