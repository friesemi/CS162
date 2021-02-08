#ifndef PIZZA_H
#define PIZZA_H
#include "structs.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

class Pizza{
private:
	string name;
	int small_cost;
	int medium_cost;
	int large_cost;
	int num_ingredients;
	string *ingredients;
	int num_pizzas;
public:
	//accessors
	string get_name() const;
	int get_small_cost() const;
	int get_medium_cost() const;
	int get_large_cost() const;
	int get_num_ingredients() const;
	string *get_ingredients() const;
	int get_num_pizzas() const;

	//mutators
	void set_name(string);
	void set_small_cost(int);
	void set_medium_cost(int);
	void set_large_cost(int);
	void set_num_ingredients(int);
	void set_ingredients(string *, int);
	void set_num_pizzas(int);

	Pizza();
	~Pizza();
	Pizza(const Pizza &);
	Pizza & operator=(const Pizza &);

	void pop_pizzas(int);
	void create_pizza();

	int int_check();
};
#endif