#ifndef APARTMENT_COMPLEX_H
#define APARTMENT_COMPLEX_H
#include "property.h"

class Apartment: public Property{
	private:
		citizens *tens;
		Apartment *apps;
		int numTens;
	public:
		//accessors
		citizens getTens();
		Apartment getApps();
		int getNumTens();

		//mutators
		void setTens(citizens &);
		void setApps(Apartment &);
		void setNumTens(int);

		//constructor
		Apartment();

		//destructor
		~Apartment();

		//copy constructor
		Apartment(const Apartment &);

		//AOO
		Apartment & operator=(const Apartment &);


		string getPlace();
		void apartmentListing();
		void printListing(Apartment *, int);
		Apartment buyApp(int);
};

#endif