/*
 *Program: Mrun_facts.cpp
 *Author: Michael Friesen
 *Date: 04/09/2018
 *Description: This program holds only the main function
 *Input: the command lines are taken in at compile time
 *Output: the arguments are passed to state_facts and the program is carried out
 */
#include "state_facts.h"

using namespace std;

/*
 *Function: main()
 *Desciption: This is the main function of the program
 *Parameters: one integer and a character array
 *Input: the command line arguments are passed in
 *Output: every other function is called from here running the program
 */
int main(int argc, char **argv){
	ifstream st;
	ofstream wrst;

	if(is_valid_arguments(argc, argv)){
		int num_states = is_valid_num(argc, argv);
		string filename = is_valid_file(argc, argv);
		char user_in = save_or_print();
		char write_file = save_file(user_in);
		st.open(filename.c_str());
		cout << &write_file << endl;
		state_run(num_states, user_in, st, &write_file);
	}

	else
		exit(0);

	wrst.close();
	st.close();
	return 0;
}