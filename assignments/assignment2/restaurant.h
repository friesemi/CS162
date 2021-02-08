#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "menu.h"
#include "structs.h"

using namespace std;

class Restaurant{
private:
	Menu menu;
	employee *employees;
	hours *week;
	string name;
	string phone;
	string address;
	int num_days;
public:
	
	//accessors
	Menu get_menu() const;
	employee *get_employee() const;
	hours *get_week() const;
	string get_name() const;
	string get_phone() const;
	string get_address() const;
	int get_num_days() const;

	//mutators
	void set_menu(Menu);
	void set_employee(employee *, int);
	void set_week(hours *, int);
	void set_name(string);
	void set_phone(string);
	void set_address(string);
	void set_num_days(int);

	Restaurant();
	~Restaurant();
	Restaurant(const Restaurant &);
	Restaurant & operator=(const Restaurant &);

	void pop_rest();
	void pop_menu();
	void pop_emp();
	int get_num_employees();
	int get_num_orders();
	bool pizza_exist(string);
	void welcome_fun(string);
	void login();

	//customer functions
	void see_menu(Menu menu);
	void search_ingr();
	void make_order();
	void see_hours();
	void see_address();
	void see_phone();

	//employee functions
	void chg_hours();
	int day_to_num(string);
	void see_orders();
	void rm_orders();
	void add_item();
	void rm_item();

	void print_ca();
	void customer_actions();
	void print_ea();
	void employee_actions();

	void menu_write();
	void rest_write();
	int int_check();
};


#endif