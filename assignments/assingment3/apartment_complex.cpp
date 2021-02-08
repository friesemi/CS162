#include "apartment_complex.h"

//accessors
citizens Apartment::getTens(){
	return *tens;
}

Apartment Apartment::getApps(){
	return *apps;
}

int Apartment::getNumTens(){
	return numTens;
}

//mutators
void Apartment::setTens(citizens &tens){
	tens = tens;
}

void Apartment::setApps(Apartment &apps){
	apps = apps;
}

void Apartment::setNumTens(int numTens){
	numTens = numTens;
}

//constructor
Apartment::Apartment():Property(){
	numTens = rand() % 10 + 1;
	tens = new citizens[numTens];
}

//destructor
Apartment::~Apartment(){
	//for(int i = 0; i < 3; i++)
		delete [] tens;
}


//copy constructor
Apartment::Apartment(const Apartment &other):Property(other){
	numTens = other.numTens;
	for(int i = 0; i < numTens; i++)
		tens[i] = other.tens[i];
}

//AOO
Apartment & Apartment::operator=(const Apartment &other){
	if(tens != NULL)
		delete [] tens;
	numTens = other.numTens;
	for(int i = 0; i < numTens; i++)
		tens[i] = other.tens[i];

	return *this;
}


/*
 *Function: get place
 *Description: gets the location of the apartment
 *Parameters: none
 *Input: none
 *Output: the location is returned for the apartments
 */
string Apartment::getPlace(){
	int temp = 0;
	temp = rand() % 5 + 1;
	if(temp == 1){return "SE";}
	else if(temp == 2){return "NE";}
	else if(temp == 3){return "Midwest";}
	else if(temp == 4){return "SW";}
	else return "NW";
}

/*
 *Function: apartment listing
 *Description: creates the list of apartments to buy
 *Parameters: none
 *Input: none
 *Output: creates a list of apartments
 */
void Apartment::apartmentListing(){
	Property property;
	apps = new Apartment[3];
	cout << "The available apartments are listed as such (index, property value, location, mortgage, number tenants):\n";
	for(int i = 0; i < 3; i++){
		int num = rand() % 9 + 1;
		apps[i].index = i + 4;
		apps[i].propertyValue = rand() % 300001 + 300000;
		apps[i].location = getPlace();
		apps[i].mortgage = rand() % 5001;
		apps[i].numTens = num;
		for(int j = 0; j < num; j++)
			apps[i].tens[j] = property.fillCitizen();
		printListing(apps, i);
	}
	cout << "\n";
}

/*
 *Function: print listings
 *Description: prints the list of available apartments
 *Parameters: the list of apartments
 *Input: the apartments are passed in
 *Output: outputs the apartments to the user
 */
void Apartment::printListing(Apartment *apps, int i){
	cout << apps[i].index << " " << apps[i].propertyValue << " " << apps[i].location << " " << apps[i].mortgage << " ";
	cout << apps[i].numTens << " tenant(s)\n";
}


Apartment Apartment::buyApp(int index){
	Apartment *temp = new Apartment[1];
	temp[0] = apps[index];
	apps = temp;
	return apps[0];
}