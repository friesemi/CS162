#ifndef BEES_H
#define BEES_H
#include "insects.h"

class Bees: public Insects{
	private:
		int numBees;
		int beesOnBoard;

	public:
		int getNumBees();
		int getBeesOnBoard();
		void setNumBees(int);
		void setBeesOnBoard(int);

		Bees();

		void spawning(string (&board)[5][11], int);
		void attacking(string (&board)[5][11], int);
		void beeAttack(string (&board)[5][11], int);

		void popBoard(string (&board)[5][11]);
		void printBoard(string (&board)[5][11]);
		void moving(string (&board)[5][11]);
		int posCheck(string (&board)[5][11], int);
};
#endif