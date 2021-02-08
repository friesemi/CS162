/*
 *Program: state_facts.h
 *Author: Michael Friesen
 *Date: 04/09/2018
 *Description: This is the library that contains reference to the other functions
 *Input: there is no input
 *Output: the other cpp's call on this library
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>

using namespace std;

struct county{
	string name;
	string *city; //array of city names in county
	int cities;
	int population;
	float avg_income;
	float avg_house;
};

struct state{
	string name;
	county *c; //array of counties
	int counties;
	int population;
};

bool is_valid_arguments(int argc, char **argv);
int is_valid_num(int argc, char **argv);
string is_valid_file(int argc, char **argv);
char save_file(char user_in);
char save_or_print();
void state_run(int num_states, char user_in, ifstream &st, char *write_file);

//creates and populatates structs
state *create_states(int num_states);
void get_state_data(state *, int, ifstream &);
county *create_counties(int);
void get_county_data(county *, int, ifstream &);

//sorting functions
void state_pop(state *state_arr, int num_states, char user_in, char *write_file);
void county_pop(state *state_arr, int num_states, char user_in, char *write_file);
void state_name(state *state_arr, int num_states);
void print_st_name(state *state_arr, int num_states, char user_in, char *write_file);
void sort_st_pop(state *state_arr, int num_states);
void print_st_pop(state *state_arr, int num_states, char user_in, char *write_file);

void county_income(state *state_arr, int num_states, char user_in, char *write_file);
void avg_house(state *state_arr, int num_states, char user_in, char *write_file);
void sort_c_pop(state *state_arr, int num_states, char user_in, char *write_file);
void print_c_pop(state *state_arr, int num_states, char user_in, char *write_file);
void sort_c_name(state *state_arr, int num_states, char user_in, char *write_file);


void delete_info(state **, int);
