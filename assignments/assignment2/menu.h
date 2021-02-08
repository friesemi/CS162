#ifndef MENU_H
#define MENU_H
#include "pizza.h"

using namespace std;

class Menu{
private:
	int num_pizzas;
	Pizza *pizzas;
public:

	//accessors
	int get_num_pizzas() const;
	Pizza *get_pizzas() const;

	//mutators
	void set_num_pizzas(int);
	void set_pizzas(Pizza *, int);


	Menu();
	~Menu();
	Menu(const Menu &other);
	Menu & operator=(const Menu &);

	void pop_menu();
	void search_cost();
	void search_ingr_in();
	void search_ingr_ex();
	void add_item();
	void rm_item(string);

};
#endif
