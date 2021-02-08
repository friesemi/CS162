#ifndef BUSINESS_COMPLEX_H
#define BUSINESS_COMPLEX_H
#include "property.h"

class Business: public Property{
	private:
		busPeople *busTens;
		Business *buses;
		int numTens;
	public:
		//accessors
		busPeople getBusTens();
		Business getBuses();
		int getNumTens();

		//mutators
		void setBusTens(busPeople &);
		void setBuses(Business &);
		void setNumTens(int numTens);

		//constructor
		Business();

		//destructor
		~Business();

		//copy constructor
		Business(const Business &);

		//AOO
		Business & operator=(const Business &);

		string getPlace();
		void businessListing();
		void printListing(Business *, int);
};

#endif