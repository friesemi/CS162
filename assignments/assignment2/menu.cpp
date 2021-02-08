#include "menu.h"

using namespace std;
	//accessors
	int Menu::get_num_pizzas() const{
		return num_pizzas;
	}
	Pizza *Menu::get_pizzas() const{
		return pizzas;
	}

	//mutators
	void Menu::set_num_pizzas(int num_pizzas){
		num_pizzas = num_pizzas;
	}
	void Menu::set_pizzas(Pizza *pizzas, int num){
		for(int i = 0; i < num; i++)
		pizzas[i] = pizzas[i];
	}

	//nondefault constructor
	Menu::Menu(){
		num_pizzas = 0;
		pizzas = NULL;
	}
	//destructor
	Menu::~Menu(){
		delete [] pizzas;
	}
	//copy constructor
	Menu::Menu(const Menu &other){
		num_pizzas = other.num_pizzas;
		pizzas = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++){
			pizzas = other.pizzas;
		}
	}
	//operator overload
	Menu & Menu::operator=(const Menu &other){
		delete [] pizzas;
		num_pizzas = other.num_pizzas;
		pizzas = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++){
			pizzas = other.pizzas;
		}
		return *this;
	}

	/*
	 *Function: pop menu
	 *Description: populates the menu
	 *Parameters: none
	 *Input: none
	 *Output: populates the menu
	 */
	void Menu::pop_menu(){
		int num = 0;
		ifstream menu;
		menu.open("menu.txt");
		while(menu.ignore(256, '\n'))
			num += 1;
		menu.close();
		if(pizzas != NULL)
			delete [] pizzas;
		num_pizzas = num - 1;
		pizzas = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++)
			pizzas[i].pop_pizzas(i);
		cout << pizzas << endl;
	}

	/*
	 *Function: search cost
	 *Description: allows the customer to search by cost
	 *Parameters: none
	 *Input: none
	 *Output: returns a list of pizzas under cost
	 */
	void Menu::search_cost(){
		Pizza pizza;
		cout << "Enter the desired size (1, 2, 3):\n";
		int size = pizza.int_check(), index = 0;
		cout << "Enter the highest cost:\n";
		int cost = pizza.int_check(), arr_size = get_num_pizzas();
		string und_cost[arr_size];
		for(int i = 0; i < arr_size; i++){
			if(size == 1){
				if(pizzas[i].get_small_cost() < cost){
					und_cost[index] = pizzas[i].get_name();
					index += 1;
				}
			}
			else if(size == 2){
				if(pizzas[i].get_medium_cost() < cost){
					und_cost[index] = pizzas[i].get_name();
					index += 1;
					}
				}
			else if(size == 3){
				if(pizzas[i].get_large_cost() < cost){
					und_cost[index] = pizzas[i].get_name();
					index += 1;
				}
			}
		}
		cout << "The orders under the cost are:\n";
		for(int i = 0; i < index; i++)
			cout << und_cost[i] << endl;
	}

	/*
	 *Function: search ingr in
	 *Description: searches through ingredients and includes pizzas with ingredients
	 *Parameters: none
	 *Input: none
	 *Output: the inclusive list is returned
	 */
	void Menu::search_ingr_in(){
		Pizza pizza;
		char user_in = 'y';
		int index = 0;
		string ingr; string in_pizza[10];
		while(user_in == 'y'){
			cout << "Enter the ingredient to include (no spaces & capitalize first letter): ";
			cin >> ingr;
			for(int i = 0; i < get_num_pizzas(); i++){
				for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
					if(pizzas[i].get_ingredients()[j] == ingr){
						in_pizza[index] = pizzas[i].get_name();
						index += 1;
					}
				}
			}
			do{
				cout << "Include another ingredient? (y/n): ";
				cin >> user_in;
			}while(user_in != 'y' && user_in != 'n');
		}
		cout << "The list of pizzas is:\n";
		for(int i = 0; i < index; i++)
			cout << in_pizza[i] << endl;
	}

	/*
	 *Function: search ingr ex
	 *Description: searches through ingredients and excludes pizzas with ingredients
	 *Parameters: none
	 *Input: none
	 *Output: the exclusive list is returned
	 */
	void Menu::search_ingr_ex(){
		Pizza pizza;
		char user_in = 'y';
		int index = 0;
		string ingr; string ex_pizza[10];
		while(user_in == 'y'){
			cout << "Enter the ingredient to exclude (no spaces & capitalize first letter): ";
			cin >> ingr;
			for(int i = 0; i < get_num_pizzas(); i++){
				for(int j = 0; j < pizza.get_num_ingredients(); j++){
					if(pizzas[i].get_ingredients()[j] != ingr){
						ex_pizza[i] = pizzas[i].get_name();
						index += 1;
					}
				}
			}
			do{
				cout << "Exclude another ingredient? (y/n): ";
				cin >> user_in;
			}while(user_in != 'y' && user_in != 'n');
		}
		cout << "The list of pizzas is:\n";
		for(int i = 0; i < index; i++)
			cout << ex_pizza[i] << endl;
	}

	/*
	 *Function: add item
	 *Description: adds an item to the menu
	 *Parameters: none
	 *Input: none
	 *Output: added item to the menu
	 */
	void Menu::add_item(){
		Pizza * temp = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++){
			temp[i] = pizzas[i];
		}
		if(pizzas != NULL)
			delete [] pizzas;
		pizzas = new Pizza[num_pizzas+1];
		for(int i = 0; i < num_pizzas; i++)
			pizzas[i] = temp[i];
		delete [] temp;
		pizzas[num_pizzas].create_pizza();
	}

	/*
	 *Function: rm item
	 *Description: removes an item from the menu
	 *Parameters: none
	 *Input: none
	 *Output: an item is removed from the list
	 */
	void Menu::rm_item(string remove){
		Pizza * removed = new Pizza[num_pizzas];
		int index = 0;
		for(int i = 0; i < num_pizzas-1; i++){
			if(pizzas[index].get_name() == remove)
				index += 1;
			removed[i] = pizzas[index];
			index += 1;
		}
		delete [] pizzas;
		Pizza * pizzas = new Pizza[num_pizzas-1];
		for(int i = 0; i < num_pizzas-1; i++)
			pizzas[i] = removed[i];
		delete [] removed;
	}