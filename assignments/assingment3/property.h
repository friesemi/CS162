#ifndef PROPERTY_H
#define PROPERTY_H
#include "structs.h"

class Property{
	protected:
		int index;
		float propertyValue;
		string location;
		float mortgage;
		float propertyTax;
		int numTens;

	public:
		//accessors
		int getIndex();
		float getPValue();
		string getLocation();
		float getMortgage();
		float getPTax();
		int getNumTens();

		//mutators
		void setIndex(int);
		void setPValue(float);
		void setLocation(string);
		void setMortgage(float);
		void setPTax(float);
		void setNumTens(int);

		//nondefault constructor
		Property();

		//copy constructor
		Property(const Property &);

		//AOO
		Property & operator=(const Property &);
		//bool operator>(const Property &);
		//bool operator<(const Property &);

		citizens fillCitizen();
		busPeople fillBusPeople();
		int intCheck();

};

#endif