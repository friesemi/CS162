#ifndef EQUIP
#define EQUIP
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Equipment{
	protected:
		string name;
		int value;
	public:
		string getName();
		int getValue();

		void setName(string);
		void setValue(int);

		Equipment();
		virtual void print();
};

#endif