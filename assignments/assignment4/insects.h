#ifndef INSECTS_H
#define INSECTS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Insects{
	protected:
		string name;		//bees or types of ants
		int armor, attack;	//health and attack values
		
	public:
		string getName();
		int getArmor();
		int getAttack();

		void setName(string);
		void setArmor(int);
		void setAttack(int);

		Insects();

		virtual void popBoard(string (&board)[5][11])=0;
		virtual void printBoard(string (&board)[5][11])=0;

		virtual void spawning(string (&board)[5][11], int)=0;
		virtual void attacking(string (&board)[5][11], int)=0;

};
#endif