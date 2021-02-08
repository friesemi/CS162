#include "business_complex.h"

busPeople Business::getBusTens(){
	return *busTens;
}

Business Business::getBuses(){
	return *buses;
}

int Business::getNumTens(){
	return numTens;
}


void Business::setBusTens(busPeople &busTens){
	busTens = busTens;
}

void Business::setBuses(Business &buses){
	buses = buses;
}

void Business::setNumTens(int numTens){
	numTens = numTens;
}

//constructor
Business::Business():Property(){
	numTens = rand() % 5 + 1;
	busTens = new busPeople[numTens];
}

//destructor
Business::~Business(){
	//for(int i = 0; i < 3; i++)
		delete [] busTens;
}

//copy constructor
Business::Business(const Business &other):Property(other){
	numTens = other.numTens;
	for(int i = 0; i < numTens; i++){
		busTens[i] = other.busTens[i];
	}
}

//AOO
Business & Business::operator=(const Business &other){
	if(busTens != NULL)
		delete [] busTens;
	numTens = other.numTens;
	for(int i = 0; i < numTens; i++){
		busTens[i] = other.busTens[i];
	}
	return *this;
}

/*
 *Function: get place
 *Desription: gets the location of the business
 *Parameters: none
 *Input: none
 *Output: returns the location of the business
 */
string Business::getPlace(){
	int temp = 0;
	temp = rand() % 5 + 1;
	if(temp == 1){return "SE";}
	else if(temp == 2){return "NE";}
	else if(temp == 3){return "Midwest";}
	else if(temp == 4){return "SW";}
	else return "NW";
}

/*
 *Function: business listing
 *Desription: creates a list of businesses
 *Parameters: none
 *Input: none
 *Output: the list of businesses is created
 */
void Business::businessListing(){
	Property property;
	buses = new Business[3];
	cout << "The available businesses are listed as such (index, property value, location, mortgage, number businesses):\n";
	for(int i= 0; i < 3; i++){
		int num = rand() % 5 + 1;
		buses[i].index = i + 7;
		buses[i].propertyValue = rand() % 200001 + 400000;
		buses[i].location = getPlace();
		buses[i].mortgage = rand() % 5001;
		buses[i].numTens = num;
		for(int j = 0; j < num; j++)
			buses[i].busTens[j] = property.fillBusPeople();
		printListing(buses, i);
	}
	cout << "\n";
}

/*
 *Function: print listings
 *Desription: prints the list of businesses
 *Parameters: the list of businesses is given 
 *Input: the list is taken in
 *Output: the list of businesses is printed to the screen
 */
void Business::printListing(Business *buses, int i){
	cout << buses[i].index << " " << buses[i].propertyValue << " " << buses[i].location << " ";
	cout << buses[i].mortgage << " " << buses[i].numTens << " tenant(s)\n";
}