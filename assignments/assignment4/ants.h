#ifndef ANTS_H
#define ANTS_H
#include "insects.h"


class Ants: public Insects{
	protected:
		string userIn;

	public:
		static int food;
		string getUserIn();
		void setUserIn(string);

		Ants();

		virtual void spawning(string (&board)[5][11], int);
		virtual void attacking(string (&board)[5][11], int);

		void popBoard(string (&board)[5][11]);
		void printBoard(string (&board)[5][11]);

		void spawnType(string (&board)[5][11]);
		void spawnAnt(string (&board)[5][11], string, int);
		void attacks(string (&board)[5][11]);

		int intCheck();
};
#endif