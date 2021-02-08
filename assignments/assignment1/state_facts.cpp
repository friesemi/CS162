/*
 *Program: state_facts.cpp
 *Author: Michael Friesen
 *Date: 04/09/2018
 *Description: This program contains the functions used in run_facts
 *Input: the file supplied and the command line arguments are taken in
 *Output: the program is executed from here
 */
#include "state_facts.h"

using namespace std;

/*
 *Function: is_valid_arguments()
 *Description: Checks if the command line arguments are valid
 *Parameters: an int and a character array
 *Input: the command line arguments are passed in
 *Output: a boolean determining validity is returned
 */
bool is_valid_arguments(int argc, char **argv){
	int count = 0;
	if(argc != 5)
		return false;
	for(int i = 0; i < argc; i++){
		if(argv[i][0] == '-' && argv[i][1] == 's')
			count++;
		else if(argv[i][0] == '-' && argv[i][1] == 'f')
			count++;
	}
	if(count == 2)
		return true;
	else
		return false;
}

/*
 *Function: is_valid_num()
 *Description: Determines if th number of states is valid
 *Parameters: an int and a character array
 *Input: the command line arguments are passed in
 *Output: an integer of the number of states is returned
 */
int is_valid_num(int argc, char **argv){
	int num_state = 0;
	for(int i = 0; i < argc; i++){
		if(argv[i][0] == '-' && argv[i][1] == 's'){
			num_state = atoi(argv[i+1]);
			if(num_state < 1){
				do{
					cout << "Please enter a correct number: ";

					cin >> num_state;
					while(getchar() != '\n');
					//hangs if incorrect number input then good number input
				}while(num_state < 1);
				return num_state;
			}
			else
				return num_state;
		}
	}
}

/*
 *Function: is_valid_file()
 *Description: Returns the file if the file exists
 *Parameters: an int and a character array
 *Input: the command line arguments are passed in
 *Output: a string for a valid filename is returned
 */
string is_valid_file(int argc, char **argv){
	string filename;
	for(int i = 0; i < argc; i++){
		if(argv[i][0] == '-' && argv[i][1] == 'f'){
			filename = argv[i+1];
			cout << filename << endl;
			do{
				if(ifstream(filename.c_str())){
					return filename;
				}
				else{
					cout << "File does not exist; enter a valid filename: ";
					getline(cin, filename);
				}
			}while(!ifstream(filename.c_str()));
		}
	}
	return filename;
}

/*
 *Function: save_file() 
 *Decription: creates a file for the user if they want to save the data elsewhere
 *Parameters: a charcter is input
 *Input: the filename is passed into the function
 *Output: a string is returned to main
 */
char save_file(char user_in){
	char write_file[256];

	if(user_in == 's'){
		cout << "Enter the name of the file (no need to add .txt): ";
		while(getchar() != '\n');
		cin.getline(write_file, 256);
		strcat(write_file, ".txt");
	}
	return write_file[0];
}

/*
 *Function: save_or_print()
 *Description: asks the user if they want to save or print the information
 *Parameters: none
 *Input: there are no inputs necessary
 *Output: the char input is returned
 */
char save_or_print(){
	char user_in;
	do{
		cout << "Would you like to print the info or save it? p/s: ";
		cin >> user_in;
	}while(user_in != 'p' && user_in != 's');
	return user_in;
}

/*
 *Function: state_run()
 *Description: holds most of the functions that will carry out the program
 *Parameters: the number of states, the user input, the ifstream and the string for the write file
 *Input: the parameters are taken into the function
 *Output: the functions for the program are ran from here
 */
void state_run(int num_states, char user_in, ifstream &st, char *write_file){
		if(st.is_open()){
			state *state_arr = create_states(num_states);
			get_state_data(state_arr, num_states, st);
			cout << write_file << endl;

			state_pop(state_arr, num_states, user_in, write_file);
			county_pop(state_arr, num_states, user_in, write_file);
			county_income(state_arr, num_states, user_in, write_file);
			avg_house(state_arr, num_states, user_in, write_file);
			state_name(state_arr, num_states);
			print_st_name(state_arr, num_states, user_in, write_file);
			sort_st_pop(state_arr, num_states);
			print_st_pop(state_arr, num_states, user_in, write_file);
			sort_c_name(state_arr, num_states, user_in, write_file);
			sort_c_pop(state_arr, num_states, user_in, write_file);
			print_c_pop(state_arr, num_states, user_in, write_file);

		}
		else
			cout << "Error opening file" << endl;
}

/*
 *Function: create_states()
 *Description: Creates an array for the state info
 *Parameters: an int
 *Input: the integer for the number of states is passed in
 *Output: the state_arr is returned
 */
state *create_states(int num_states){
	state *state_arr = new state[num_states];
	return state_arr;
}

/*
 *Function: get_state_data()
 *Description: Populates the state array with information from the file 
 *Parameters: the state array, an int, and the stream of the file
 *Input: the parameters are all passed in
 *Output: the array is populated for later use
 */
void get_state_data(state *state_arr, int num_states, ifstream &st){
	for(int i = 0; i < num_states; i++){
		st >> state_arr[i].name;
		cout << "Name is: " << state_arr[i].name << endl;
		st >> state_arr[i].population;
		cout << "Population is: " << state_arr[i].population << endl;
		st >> state_arr[i].counties;
		cout << "# of counties: " << state_arr[i].counties << endl;
		state_arr[i].c = create_counties(state_arr[i].counties);
		get_county_data(state_arr[i].c, state_arr[i].counties, st);
	}
}

/*
 *Function: create_counties()
 *Description: Creates an array for the county info
 *Parameters: an int
 *Input: the number of counties is passed in
 *Output: the county_arr is returned
 */
county *create_counties(int num_counties){
	county *county_arr = new county[num_counties];
	return county_arr;
}

/*
 *Function: get_county_data()
 *Description: Populates the county array
 *Parameters: the county array, an int, and the stream of the file
 *Input: the parameters are passed in
 *Output: the array is populated for later use
 */
void get_county_data(county *county_arr, int num_counties, ifstream &st){
	for(int i = 0; i < num_counties; i++){
		st >> county_arr[i].name;
		cout << county_arr[i].name << " ";
		st >> county_arr[i].population;
		cout << county_arr[i].population << " ";
		st >> county_arr[i].avg_income;
		cout << county_arr[i].avg_income << " ";
		st >> county_arr[i].avg_house;
		cout << county_arr[i].avg_house << " ";
		st >> county_arr[i].cities;
		cout << county_arr[i].cities << " ";

		county_arr[i].city = new string[county_arr[i].cities];
		for(int j = 0; j < county_arr[i].cities; j++){
			st >> county_arr[i].city[j];
			cout << county_arr[i].city[j] << endl;
		}
	}
	cout << endl;
}

/*
 *Function: state_pop()
 *Description: Determines the largest population and either prints it or writes it to a file
 *Parameters: the state array and an int
 *Input: the state array and the number of states is passed in
 *Output: the poulation is either printed or written to another file
 */
void state_pop(state *state_arr, int num_states, char user_in, char *write_file){ //another variable for user input to tell if write or print
	int temp = 0;
	ofstream wrst;
	wrst.open(write_file);
	for(int i = 0; i < num_states; i++){
		for(int j = 0; j < num_states - 1 - j; j++){
			if(state_arr[j].population < state_arr[j+1].population){
				temp = state_arr[j].population;
				state_arr[j].population = state_arr[j+1].population;
				state_arr[j+1].population = temp;
			}
		}
	}
	if(user_in == 's'){
		wrst << "The state with the largest poulation is: " << state_arr[0].name << endl;
	}
	else{
		cout << "The state with the largest population is: ";
		cout << state_arr[0].name << endl;
	}
	wrst.close();
}

/*
 *Function: county_pop()
 *Description: finds the highest population county
 *Parameters: the state array, the number of states, the user input and the ofstream
 *Input: the parameters are all passed into the function
 *Output: the highest population county is either printed or saved
 */
void county_pop(state *state_arr, int num_states, char user_in, char *write_file){
	int temp = 0;
	ofstream wrst;
	wrst.open(write_file);
	string temp_name;
	int *high_counties = new int[num_states];
	string *high_c_name = new string[num_states];
	for(int i = 0; i < num_states - 1; i++){
		for (int j = 0; j < num_states - 1 - i; ++j){
			if(state_arr[i].c[j].population < state_arr[i].c[j+1].population){
				temp = state_arr[i].c[j].population;
				state_arr[i].c[j].population = state_arr[i].c[j+1].population;
				state_arr[i].c[j+1].population = temp;
			}
		}
		high_counties[i] = state_arr[i].c[0].population;
		high_c_name[i] = state_arr[i].c[0].name;
	}
	for(int i = 0; i < num_states - 1; i++){
		for(int j = 0; j < num_states - 1 - i; j++){
			if(high_counties[i] < high_counties[i+1]){
				temp = high_counties[i];
				temp_name = high_c_name[i];
				high_counties[i] = high_counties[i+1];
				high_c_name[i] = high_c_name[i+1];
				high_counties[i+1] = temp;
				high_c_name[i+1] = temp_name;
			}
		}
	}
	if(user_in == 's'){
		wrst << "The county with the largest poulation is: " << high_c_name[0] << endl << endl;
	}
	else{
		cout << "The county with the largest population is: ";
		cout << high_c_name[0] << endl << endl;
	}

	delete [] high_counties;
	delete [] high_c_name;
	wrst.close();
}

/*
 *Function: county_income();
 *Description: displays or saves the counties over a certain income level
 *Parameters: the state array, the number of states, the user input and the ofstream
 *Input: the parameters are passed into the function
 *Output: saves or displays the counties above the income level
 */
void county_income(state *state_arr, int num_states, char user_in, char *write_file){
	int income = 0;
	ofstream wrst;
	wrst.open(write_file);
	cout << "Give an income amount to check for: ";
	cin >> income;
	if(user_in == 's')
		wrst << "The counties with income above " << income << " are:\n";
	else
		cout << "The countries with income above " << income << " are:\n";

	for(int i = 0; i < num_states; i++){
		for(int j = 0; j < state_arr[i].counties; j++){
			if(state_arr[i].c[j].avg_income > income){
				if(user_in == 's')
					wrst << state_arr[i].c[j].name << " ";
				else
					cout << state_arr[i].c[j].name << " ";
			}
		}
		wrst << endl;
		cout << endl;
	}
	cout << endl;
	wrst.close();
}

/*
 *Function: avg_house()
 *Description: calculates and displays/saves the average cost of housing
 *Parameters: the state array, the number of states, the user input, and the ofstream
 *Input: the parameters are taken into the function
 *Output: the average housing cost is either saved or printed
 */
void avg_house(state *state_arr, int num_states, char user_in, char *write_file){
	float cost = 0, avg = 0;
	int num_counties = 0;
	ofstream wrst;
	wrst.open(write_file);
	for(int i = 0; i < num_states; i++){
		for(int j = 0; j < state_arr[i].counties; j++){
			cost += state_arr[i].c[j].avg_house;
			num_counties += 1;
		}
		avg = cost / num_counties;
		if(user_in == 's')
			wrst << "The average housing cost for " << state_arr[i].name << " is: " << avg << endl;
		else
			cout << "The average housing cost for " << state_arr[i].name << " is: " << avg << endl;
	}
	wrst.close();
}

/*
 *Function: state_name()
 *Description: sorts the state by name
 *Parameters: a state struct, an int, a char
 *Input: the parameters are all passed into the function
 *Output: the sorted states are either printed or saved
 */
void state_name(state *state_arr, int num_states){
	string temp;
	for(int i = 0; i < num_states - 1; i++){
		for(int j = 0; j < num_states - i - 1; j++){
			if(state_arr[j].name[0] > state_arr[j+1].name[0]){
				temp = state_arr[j].name;
				state_arr[j].name = state_arr[j+1].name;
				state_arr[j+1].name = temp;					
			}
		}
	}
}

/*
 *Function: print_st_name()
 *Description: prints or saves the sorted states
 *Parameters: the state array, the number of states, a char, and the ofsteam
 *Input: the parameters are all passed into the function
 *Output: the information is either printed or sorted
 */
void print_st_name(state *state_arr, int num_states, char user_in, char *write_file){
	ofstream wrst;
	wrst.open(write_file);
	if(user_in == 's'){
		wrst << "Sorted states by name:\n";
		for(int i = 0; i < num_states; i++){
			wrst << state_arr[i].name << endl;
		}
	}
	else{
		cout << "Sorted states by name:\n";
		for(int i = 0; i < num_states; i++){
			cout << state_arr[i].name << endl;
		}
	}
	wrst.close();
}

/*
 *Function: sort_st_pop()
 *Description: prints or saves the list of states sorted by population
 *Parameters: the state array & the number of states
 *Input: the parameters are taken into the function
 *Output: the list of sorted states is either saved or written
 */
void sort_st_pop(state *state_arr, int num_states){
	int temp;
	for(int i = 0; i < num_states - 1; i++){
		for(int j = 0; j < num_states - i - 1; j++){
			if(state_arr[j].population > state_arr[j+1].population){
				temp = state_arr[j].population;
				state_arr[j].population = state_arr[j+1].population;
				state_arr[j+1].population = temp;					
			}
		}
	}
}

/*
 *Function: print_st_pop()
 *Description: prints or saves the sorted states
 *Parameters: the state array, the number of states, a char, and the ofsteam
 *Input: the parameters are all passed into the function
 *Output: the information is either printed or sorted
 */
void print_st_pop(state *state_arr, int num_states, char user_in, char *write_file){
	ofstream wrst;
	wrst.open(write_file);
	if(user_in == 's'){
		wrst << "Sorted states by population:\n";
		for(int i = 0; i < num_states; i++){
			wrst << state_arr[i].name << endl;
		}
	}
	else{
		cout << "Sorted states by population:\n";
		for(int i = 0; i < num_states; i++){
			cout << state_arr[i].name << endl;
		}
	}
	wrst.close();
}

/*
 *Function: sort_c_pop()
 *Description: sorts the counties in order of population
 *Parameters: the state array, the number of states, the user input and the ofstream
 *Input: the parameters are taken into the function
 *Output: the sorted list of counties is either saved or printed
 */
void sort_c_pop(state *state_arr, int num_states, char user_in, char *write_file){
	ofstream wrst;
	wrst.open(write_file);
	int temp;
	for(int i = 0; i < num_states - 1; i++){
		for(int j = 0; j < state_arr[i].counties - i - 1; j++){
			if(state_arr[i].c[j].population > state_arr[i].c[j+1].population){
				temp = state_arr[i].c[j].population;
				state_arr[i].c[j].population = state_arr[i].c[j+1].population;
				state_arr[i].c[j+1].population = temp;					
			}
		}
	}
	wrst.close();
}

/*
 *Function: print_c_pop()
 *Description: prints or saves the sorted counties
 *Parameters: the state array, the number of states, a char, and the ofsteam
 *Input: the parameters are all passed into the function
 *Output: the information is either printed or sorted
 */
void print_c_pop(state *state_arr, int num_states, char user_in, char *write_file){
	ofstream wrst;
	wrst.open(write_file);
	if(user_in == 's'){
		wrst << "Sorted counties by population:\n";
		for(int i = 0; i < num_states; i++){
			wrst << state_arr[i].c->name << endl;
		}
	}
	else{
		cout << "Sorted counties by population:\n";
		for(int i = 0; i < num_states; i++){
			cout << state_arr[i].c->name << endl;
		}
	}
	wrst.close();
}

/*
 *Function: sort_c_name()
 *Description: alphabetically sorts the counties for each state
 *Parameters: the state array, the number of states, the user input, and the ofstream
 *Input: the parameters are taken into the function
 *Output: the sorted list of counties is either saved or printed
 */
void sort_c_name(state *state_arr, int num_states, char user_in, char *write_file){
	ofstream wrst;
	wrst.open(write_file);
	string temp;
	for(int i = 0; i < num_states - 1; i++){
		for(int j = 0; j < state_arr[i].counties - 1 - i; j++){
			if(state_arr[i].c[j].name < state_arr[i].c[j+1].name){
				temp = state_arr[i].c[j].name;
				state_arr[i].c[j].name = state_arr[i].c[j+1].name;
				state_arr[i].c[j+1].name = temp;
			}
		}
	}
	if(user_in == 's'){
		wrst << "The counties sorted by name are:\n";
		for(int i = 0; i < num_states - 1; i++){
			for(int j = 0; j < state_arr[i].counties - 1 - i; j++){
				wrst << state_arr[i].c[j].name << endl;
			}
		}
		wrst << endl;
	}
	else{
		cout << "The counties sorted by name are:\n";
		for(int i = 0; i < num_states - 1; i++){
			for(int j = 0; j < state_arr[i].counties - 1; j++){
				cout << state_arr[i].c[j].name << endl;
			}
		}
	}
	wrst.close();
	delete [] state_arr;
}

/*
 *Function: delete_info()
 *Description: deletes the dynamic arrays off of the heap
 *Parameters: the array of the state array and the number of states
 *Input: the parameters are taken into the function
 *Output: the array is deleted and reset to NULL
 */
void delete_info(state **state_arr, int num_states){
	for(int i = 0; i < num_states; i++){
		for(int j = 0; j < (*state_arr)[i].counties; j++){
			delete [] (*state_arr)[i].c[j].city;
		}
		delete [] (*state_arr)[i].c;
	}
	delete [] *state_arr;
	state_arr = NULL;
}