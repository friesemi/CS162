#include "house.h"

citizens House::getTens(){
	return tens;
}

House House::getHouses(){
	return *houses;
}

int House::getRent(){
	return rent;
}



void House::setTens(citizens &tens){
	tens = tens;
}

void House::setHouses(House &houses){
	houses = houses;
}

void House::setRent(int rent){
	rent = rent;
}

//constructor
House::House():Property(){
	tens;
	houses = NULL;
	rent = 0;

}

//destructor
House::~House(){
	//for(int i = 0; i < 3; i++)
		delete [] houses;
}

//copy constructor
House::House(const House &other):Property(other){
	tens = other.tens;
	houses = other.houses;
	rent = other.rent;
}

//AOO
House & House::operator=(const House &other){
	if(houses != NULL)
		delete [] houses;
	tens = other.tens;
	*houses = *other.houses;
	rent = other.rent;

	return *this;
}

/*
 *Function: get place
 *Description: decides the destination of the property
 *Parameters: none
 *Input: none
 *Output: a location is returned to be assigned to the property
 */
string House::getPlace(){
	int temp = 0;
	temp = rand() % 5 + 1;
	if(temp == 1){return "SE";}
	else if(temp == 2){return "NE";}
	else if(temp == 3){return "Midwest";}
	else if(temp == 4){return "SW";}
	else return "NW";

}

/*
 *Function: house listing
 *Description: creates an array of houses to buy
 *Parameters: none
 *Input: none
 *Output: the list of houses is created
 */
void House::houseListing(){
	Property property;
	houses = new House[3];
	for(int i = 0; i < 3; i++){
		houses[i].index = i + 1;
		houses[i].propertyValue = rand() % 500001 + 100000;
		houses[i].location = getPlace();
		houses[i].mortgage = rand() % 5001;
		houses[i].tens = property.fillCitizen();
	}
	printHouses(houses);
	cout << "\n";
}

/*
 *Function: print houses
 *Description: prints the list of houses to buy
 *Parameters: the list of houses
 *Input: the list of houses is taken in
 *Output: the lsit of houses is printed to the screen
 */
void House::printHouses(House *houses){
	cout << "The available houses are listed as such (index, property value, location, mortgage, number tenants):\n";
	for(int i = 0; i < 3; i++){
		cout << houses[i].index << " " << houses[i].propertyValue << " " << houses[i].location << " " << houses[i].mortgage << " " << "1 tenant\n";
	}
}
