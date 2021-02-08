#include "pizza.h"

using namespace std;

	//accessors
	string Pizza::get_name() const{
		return name;
	}
	int Pizza::get_small_cost() const{
		return small_cost;
	}
	int Pizza::get_medium_cost() const{
		return medium_cost;
	}
	int Pizza::get_large_cost() const{
		return large_cost;
	}
	int Pizza::get_num_ingredients() const{
		return num_ingredients;
	}
	string *Pizza::get_ingredients() const{
		return ingredients;
	}
	int Pizza::get_num_pizzas() const{
		return num_pizzas;
	}

	//mutators
	void Pizza::set_name(string name){
		name = name;
	}
	void Pizza::set_small_cost(int small_cost){
		small_cost = small_cost;
	}
	void Pizza::set_medium_cost(int medium_cost){
		medium_cost = medium_cost;
	}
	void Pizza::set_large_cost(int large_cost){
		large_cost = large_cost;
	}
	void Pizza::set_num_ingredients(int num_ingredients){
		num_ingredients = num_ingredients;
	}
	void Pizza::set_ingredients(string *ingredients, int x){
		for(int i = 0; i < x; i++)
		ingredients[i] = ingredients[i];
	}
	void Pizza::set_num_pizzas(int num_pizzas){
		num_pizzas = num_pizzas;
	}

	//nondefault constructor
	Pizza::Pizza(){
		name = "";
		small_cost = 0;
		medium_cost = 0;
		large_cost = 0;
		num_ingredients = 0;
		ingredients = NULL;
	}
	//destructor
	Pizza::~Pizza(){
		delete [] ingredients;
	}
	//copy constructor
	Pizza::Pizza(const Pizza &other){
		name = other.name;
		small_cost = other.small_cost;
		medium_cost = other.medium_cost;
		large_cost = other.large_cost;
		num_ingredients = other.num_ingredients;
		ingredients = new string[num_ingredients];
		for(int i = 0; i < num_ingredients; i++){
			other.ingredients[i] = ingredients[i];
		}
	}
	//operator overload
	Pizza & Pizza::operator=(const Pizza &other){
		delete [] ingredients;
		name = other.name;
		small_cost = other.small_cost;
		medium_cost = other.medium_cost;
		large_cost = other.large_cost;
		num_ingredients = other.num_ingredients;
		ingredients = new string[num_ingredients];
		for(int i = 0; i< num_ingredients; i++){
			ingredients = other.ingredients;
		}
		return *this;
	}

	/*
	 *Function: pop_pizzas
	 *Description: populates the pizza variables
	 *Parameters: number of pizzas
	 *Input: num pizzas is taken in
	 *Output: the variables are populated
	 */
	void Pizza::pop_pizzas(int num_pizzas){
		ifstream piz;
		piz.open("menu.txt");
		if(piz.is_open()){
			for(int i = 0; i < num_pizzas; i++)
				piz.ignore(256, '\n');
			piz >> name;
			piz >> small_cost;
			piz >> medium_cost;
			piz >> large_cost;
			piz >> num_ingredients;
			if(ingredients != NULL)
				delete [] ingredients;
			ingredients = new string[num_ingredients];
			for(int j = 0; j < num_ingredients; j++){
				piz >> ingredients[j];
			}
		}
		else
			cout << "Error opening file" << endl;
		piz.close();
	}

	/*
	 *Function: create pizza
	 *Description: creates a pizza (all from scratct!)
	 *Parameters: none
	 *Input: none
	 *Output: pizza is added to the menu
	 */
	void Pizza::create_pizza(){
		cout << "Enter the name of the pizza:\n";
		cin >> name;
		cout << "Enter the small cost:\n";
		small_cost = int_check();
		cout << "Enter the medium cost:\n";
		medium_cost = int_check();
		cout << "Enter the large cost:\n";
		large_cost = int_check();
		cout << "How many ingredients are there:\n";
		num_ingredients = int_check();
		for(int i = 0; i < num_ingredients; i++){
			cout << "Enter an ingredient (no spaces): ";
			cin >> ingredients[i];
		}
	}

	/*
	 *Function: int check
	 *Description: checks if an integer is valid
	 *Parameters: none
	 *Input: none
	 *Output: a valid integer
	 */
	int Pizza::int_check(){
		string checker;
		int integer = 0;
		bool test;
		do{
			cout << "Enter an integer: ";
			while(cin.get() != '\n');
			getline(cin, checker);
			int len = checker.length();

			for(int i = 0; i < len; i++){
				if(checker[i] < 48 || checker[i] > 57){
					test = false;
					break;
				}
				else{
				test = true;
				}
			}
		}while(test == false);

		int len2 = checker.length();
		for(int j = 0; j < len2; j++){
			integer += ((int)checker[j] - 48) * (pow(10, len2 - j - 1));
		}
		return integer;
	}