#include "restaurant.h"

	//accessors
	Menu Restaurant::get_menu() const{
		return menu;
	}
	employee *Restaurant::get_employee() const{
		return employees;
	}
	hours *Restaurant::get_week() const{
		return week;
	}
	string Restaurant::get_name() const{
		return name;
	}
	string Restaurant::get_phone() const{
		return phone;
	}
	string Restaurant::get_address() const{
		return address;
	}
	int Restaurant::get_num_days() const{
		return num_days;
	}

	//mutators
	void Restaurant::set_menu(Menu menu){
		menu = menu;
	}
	void Restaurant::set_employee(employee *employees, int num){
		for(int i = 0; i < num; i++)
			employees[i] = employees[i];
	}
	void Restaurant::set_week(hours *week, int num){
		for(int i = 0; i < num; i++)
			week[i] = week[i];
	}
	void Restaurant::set_name(string name){
		name = name;
	}
	void Restaurant::set_phone(string phone){
		phone = phone;
	}
	void Restaurant::set_address(string address){
		address = address;
	}
	void Restaurant::set_num_days(int num_days){
		num_days = num_days;
	}

	//nondefault constructor
	Restaurant::Restaurant(){
		menu;
		employees = NULL;
		week = NULL;
		name = "";
		phone = "";
		address = "";
	}
	//destructor
	Restaurant::~Restaurant(){
		delete [] employees;
		delete [] week;
	}
	//copy constructor
	Restaurant::Restaurant(const Restaurant &other){
		menu = other.menu;
		int num_employees = get_num_employees();
		employees = new employee[num_employees];
		for(int i = 0; i < num_employees; i++){
			employees[i] = other.employees[i];
		}
		week = new hours[7];
		for(int i = 0; i < 7; i++){
			week[i] = other.week[i];
		}
		name = other.name;
		phone = other.phone;
		address = other.address;
	}
	//operator overload
	Restaurant & Restaurant::operator=(const Restaurant &other){
		delete employees;
		delete [] week;
		menu = other.menu;
		int num_employees = get_num_employees();
		employees = new employee[num_employees];		//make the size a function that gets the size
		for(int i = 0; i < num_employees; i++){
			employees[i] = other.employees[i];
		}
		week = new hours[7];
		for(int i = 0; i < 7; i++){
			week[i] = other.week[i];
		}
		name = other.name;
		phone = other.phone;
		address = other.address;
		return *this;
	}

	/*
	 *Function: pop rest
	 *Description: populates the restaurants info
	 *Parameters: none
	 *Input: none
	 *Output: populates the restaurants info
	 */
	void Restaurant::pop_rest(){
		ifstream rest_info;
		rest_info.open("restaurant info.txt");
		if(rest_info.is_open()){
			getline(rest_info, name);
			getline(rest_info, phone);
			getline(rest_info, address);
			rest_info >> num_days;
			if(week != NULL)
				delete week;
			week = new hours[num_days];
			for(int i = 0; i < num_days; i++){
				rest_info >> week[i].day;
				rest_info >> week[i].open_hour;
				rest_info >> week[i].close_hour;
			}
		}
		else
			cout << "Error opening file" << endl;
	}

	/*
	 *Function: pop menu
	 *Description: populates menu
	 *Parameters: none
	 *Input: none
	 *Output: populates the menu with pizzas
	 */
	void Restaurant::pop_menu(){
		menu.pop_menu();
	}

	/*
	 *Function: pop emp
	 *Description: populates the employee list
	 *Parameters: none
	 *Input: none
	 *Output: the employee list is populated
	 */
	void Restaurant::pop_emp(){
		int num_employees = get_num_employees();
		ifstream emp_i;
		if(employees != NULL)
			delete [] employees;
		employees = new employee[num_employees];
		emp_i.open("employee.txt");
		for(int i = 0; i < num_employees; i++){
			emp_i >> employees[i].id;
			emp_i >> employees[i].first_name;
			emp_i >> employees[i].last_name;
			emp_i >> employees[i].password;
		}
		emp_i.close();
	}

	/*
	 *Function: get num employees
	 *Description: gets the number of employees
	 *Parameters: none
	 *Input: none
	 *Output: returns the number of employees in the file
	 */
	int Restaurant::get_num_employees(){
		int num_employees = 0;
		ifstream emp_info;
		emp_info.open("employee.txt");
		while(emp_info.ignore(256, '\n')){
			num_employees += 1;
			}
		emp_info.close();
		return num_employees;
	}

	int Restaurant::get_num_orders(){
		int num_orders = 0;
		ifstream ord;
		ord.open("orders.txt");
		while(ord.ignore(256, '\n'))
			num_orders += 1;
		ord.close();
		return num_orders;
	}

	/*
	 *Function: pizza exist
	 *Description: checks if the pizza is on the menu
	 *Parameters: a string to check
	 *Input: the string is taken in
	 *Output: the string checks if the pizza exists
	 */
	bool Restaurant::pizza_exist(string exist){
		for(int i = 0; i < menu.get_num_pizzas(); i++){
			if(exist == menu.get_pizzas()[i].get_name())
				return true;
		}
		return false;
	}

	/*
	 *Function: welcome fun
	 *Description: welcomes the user and serves as the hub to run the program from
	 *Parameters: the name of the pizza shop
	 *Input: the string is taken in
	 *Output: the program is run mainly from here
	 */
	void Restaurant::welcome_fun(string name){
		char user_choice;
		bool run = true;
		while(run == true){
			cout << "Welcome to " << name << endl;
			cout << "Are you a customer(C), an employee(E), or exit(Q)" << endl;
			cin >> user_choice;
			while(user_choice != 'C' && user_choice != 'E' && user_choice != 'Q'){
				cout << "Please enter a correct letter (C, E, or Q): ";
				cin >> user_choice;
			}
			if(user_choice == 'E'){
				login();
				employee_actions();
			}
			else if(user_choice == 'C'){
				customer_actions();
			}
			else{
				exit(0);
			}
		}
	}

	/*
	 *Function: login
	 *Description: allows the employee to login
	 *Parameters: none
	 *Input: none
	 *Output: allows the user to choose employee actions
	 */
	void Restaurant::login(){
		string id, pass;
		bool temp = false;
		int num_employees = get_num_employees();
		do{
			cout << "Enter you're ID: ";
			cin >> id;
			cout << "Enter you're password: ";
			cin >> pass;
			for(int i = 0; i < num_employees; i++){
				if(employees[i].id == id && employees[i].password == pass)
					temp = true;
			}
		}while(temp == false);
		cout << "Hello " << employees[(int)id[0]-49].first_name << " " << employees[(int)id[0]-49].last_name << endl;
	}

	/*
	 *Function: see menu
	 *Description: displays the current menu
	 *Parameters: the menu variable
	 *Input: menu is passed in
	 *Output: displays the menu
	 */
	void Restaurant::see_menu(Menu menu){
		cout << "The current menu is:" << endl;
		for(int i = 0; i < menu.get_num_pizzas(); i++){
			cout << menu.get_pizzas()[i].get_name() << " ";
			cout << menu.get_pizzas()[i].get_small_cost() << " ";
			cout << menu.get_pizzas()[i].get_medium_cost() << " ";
			cout << menu.get_pizzas()[i].get_large_cost() << " ";
			for(int j = 0; j < menu.get_pizzas()[i].get_num_ingredients(); j++)
				cout << menu.get_pizzas()[i].get_ingredients()[j] << " ";
			cout << endl;
		}
	}

	/*
	 *Function: search cost
	 *Description: the hub for the other search functions
	 *Parameters: none
	 *Input: none
	 *Output: gives the choice for which search to do
	 */
	void Restaurant::search_ingr(){
		string user_in;
		char user_pick;
		see_menu(menu);
		cout << endl;
		do{
			cout << "Would you like to include (in) or exclude (ex) ingredients?: ";
			cin >> user_in;
		}while(user_in != "in" && user_in != "ex");
		if(user_in == "in"){
			menu.search_ingr_in();
		}
		else if(user_in == "ex"){
			menu.search_ingr_ex();
		}
		cout << "Would you ike to place an order? (y/n): ";
		while(user_pick != 'y' && user_pick != 'n')
			cin >> user_pick;
		if(user_pick == 'y')
			make_order();
	}

	/*
	 *Function: make order
	 *Description: allows the customer to order pizza
	 *Parameters: none
	 *Input: none
	 *Output: an order is added to the list
	 */
	void Restaurant::make_order(){
		ofstream orders;
		ifstream og_order;
		og_order.open("orders.txt");
		orders.open("ORDERS.txt");
		string fn, ln, add, size, type, order_list;
		int order_num = get_num_orders(), cc = 0, ph = 0, num = 0;
		for(int i = 0; i < order_num; i++){
			getline(og_order, order_list);
			orders << order_list << endl;
		}
		cout << "What is your name seperated by spaces?: ";
		cin >> fn; cin >> ln;
		cout << "Please enter your credit card info (no spaces):\n";
		cc = int_check();
		cout << "Please enter your address: ";
		cin >> add;
		cout << "Please enter your phone number (no spaces):\n";
		ph = int_check();
		while(pizza_exist(type) != true){
			cout << "What pizza would you like?: ";
			cin >> type;
		}
		cout << "What size? (S, M, L): ";
		cin >> size;
		cout << "How many pizzas?:\n";
		num = int_check();
		orders << order_num + 1 << " " << fn << " " << ln << " " << cc << " " << add << " " << ph << " " << type << " " << size << " " << num << endl; 
		og_order.close();
		orders.close();
		remove("orders.txt");
		rename("ORDERS.txt", "orders.txt");
	}

	/*
	 *Function: see hours
	 *Description: displays the hours
	 *Parameters: none
	 *Input: none
	 *Output: displays the hours
	 */
	void Restaurant::see_hours(){
		cout << "Current operating hours are: " << endl;
		for(int i = 0; i < get_num_days(); i++){
			cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
		}
	}

	/*
	 *Function: see address
	 *Description: displays the address
	 *Parameters: none
	 *Input: none
	 *Output: displays the address
	 */
	void Restaurant::see_address(){
		cout << "The current address is: " << address << endl;
	}

	/*
	 *Function: see phone
	 *Description: displays the phone
	 *Parameters: none
	 *Input: none
	 *Output: displays the phone number
	 */
	void Restaurant::see_phone(){
		cout << "The phone number is: " << phone << endl;
	}

	/*
	 *Function: chg hours
	 *Descriprion: allows employees to change hours
	 *Parameters: none
	 *Input: none
	 *Output: the restaurant info text file is modified
	 */
	void Restaurant::chg_hours(){
		string temp;
		int st = 0, end = 0, index = 0;
		see_hours();
		do{
		cout << "Enter a day to change (S, M, T, W, R, F, S): ";
		cin >> temp;
		}while(temp != "S" && temp != "M" && temp != "T" && temp != "W" && temp != "R" && temp != "F");
		index = day_to_num(temp);

		cout << "Start time" << endl;
		cin >> week[index].open_hour;

		cout << "End time" << endl;
		cin >> week[index].close_hour;


		cout << "The new hours are:" << endl;
		see_hours();
	}

	/*
	 *Function: day to num
	 *Description: converts the desired day to an index
	 *Parameters: an indexed string
	 *Input: the string is taken in
	 *Output: an integer is returned
	 */
	int Restaurant::day_to_num(string index){
		if(index == "S"){return 0;}
		else if(index == "M"){return 1;}
		else if(index == "T"){return 2;}
		else if(index == "W"){return 3;}
		else if(index == "R"){return 4;}
		else if(index == "F"){return 5;}
	}

	/*
	 *Function: see orders
	 *Description: shows the current orders
	 *Parameters: none
	 *Input: none
	 *Output: displays the current orders
	 */
	void Restaurant::see_orders(){
		int num_orders = get_num_orders();
		string temp;
		ifstream ord;
		ord.open("orders.txt");
		for(int i = 0; i < num_orders; i++){
			for(int j = 0; j < 9; j++){
				ord >> temp;
				cout << temp << " ";
			}
			cout << endl;
		}
		ord.close();
	}

	/*
	 *Function: rm orders
	 *Description: removes orders as desired
	 *Parameters: none
	 *Input: none
	 *Output: revised orders list is saved
	 */
	void Restaurant::rm_orders(){
		see_orders();
		string tempOrder;
		cout << "Please enter an order to delete (just the first number):\n";
		int rmOrder = int_check(), i2 = 0;
		ifstream orders;
		ofstream new_order;
		new_order.open("ORDERS.txt");
		orders.open("orders.txt");
		for(int i = 0; i < get_num_orders(); i++){
			orders >> tempOrder;
			if(i == rmOrder)
				i2 = rmOrder;
			orders.ignore(256, '\n');
		}
		for(int i = 0; i < i2; i++){
			new_order << tempOrder;
		}
		remove("orders.txt");
		rename("ORDERS.txt", "orders.txt");
	}

	/*
	 *Function: add item
	 *Description: adds item to the menu
	 *Parameters: none
	 *Input: none
	 *Output: added menu item is added
 	 */
	void Restaurant::add_item(){
		see_menu(menu);
		menu.add_item();
		see_menu(menu);
	}

	/*
	 *Function: rm item
	 *Description: removes item from the menu
	 *Parameters: none
	 *Input: none
	 *Output: item is removed from the menu
	 */
	void Restaurant::rm_item(){
		see_menu(menu);
		string removal = " ";
		while(pizza_exist(removal) == false){
			cout << "Please enter the pizza to remove (name with no spaces (_'s)): ";
			cin >> removal;
		}
		menu.rm_item(removal);
		cout << "The new list is:\n";
		see_menu(menu);
	}

	/*
	 *Function: print customer choices
	 *Description: prints the choices for the user
	 *Parameters: none
	 *Input: none
	 *Output: prints stuff
	 */
	void Restaurant::print_ca(){
		cout << "1. View Menu\n2. Search by Cost\n";
		cout << "3. Search by Ingredients\n4. Place Order\n";
		cout << "5. View Hours\n6. View Address\n";
		cout << "7. View Phone\n8. Logout\n";
	}

	/*
	 *Function: customer actions
	 *Descition: gives the ui for the customer and allows them to choose what to do
	 *Parameters: none
	 *Input: none
	 *Output: the customer chooses what they want to do
	 */
	void Restaurant::customer_actions(){
		bool run = true;
		while(run == true){
			print_ca();
			int num = int_check();
			if(num < 9){
				if(num == 1)
					see_menu(menu);
				else if(num == 2){
					menu.search_cost();
					cout << "Would you ike to place an order? (y/n): ";
					char user_in;
					while(user_in != 'y' && user_in != 'n')
						cin >> user_in;
					if(user_in == 'y')
						make_order();
				}
				else if(num == 3){
					search_ingr();
				}
				else if(num == 4){
					make_order();
				}
				else if(num == 5){
					see_hours();
				}
				else if(num == 6){
					see_address();
				}
				else if(num == 7){
					see_phone();
				}
				else if(num == 8){
					//menu_write();
					rest_write();
					run = false;
				}
			}
		}
	}

	/*
	 *Function: print employee choices
	 *Description: prints choices for the employee
	 *Parameters: none
	 *Input: none
	 *Output: prints things
	 */
	void Restaurant::print_ea(){
		cout << "1. Change Hours\n2. View Orders\n";
		cout << "3. Remove Order\n4. Add Item to Menu\n";
		cout << "5. Remove Item From Menu\n6. View Menu\n";
		cout << "7. View Hours\n8. View Address\n";
		cout << "9. View Phone\n10. Logout\n";
	}

	/*
	 *Function: employee actions
	 *Description: gives the ui for the employees and allows them to take actions
	 *Parameters: none
	 *Input: none
	 *Output: employee chooses desired action
	 */
	void Restaurant::employee_actions(){
		bool run = true;
		while(run == true){
			print_ea();
			int num = int_check();
			if(num < 11){
				if(num == 1){
					chg_hours();
				}
				else if(num == 2){
					see_orders();
				}
				else if(num == 3){
					rm_orders();
				}
				else if(num == 4){
					add_item();
				}
				else if(num == 5){
					rm_item();
				}
				else if(num == 6){
					see_menu(menu);
				}
				else if(num == 7){
					see_hours();
				}
				else if(num == 8){
					see_address();
				}
				else if(num == 9){
				see_phone();
				}
				else if(num == 10){
					//menu_write();
					rest_write();
					run = false;
				}
			}
		}
	}

	/*
	 *Function: menu write
	 *Description: writes the files for continuity
	 *Parameters: none
	 *Input: none
	 *Output: the new file is written to and saved
	 */
	void Restaurant::menu_write(){
		ofstream m;
		m.open("MENU.txt");
		for(int i = 0; i < menu.get_num_pizzas(); i++){
			m << menu.get_pizzas()[i].get_name() << " ";
			m << menu.get_pizzas()[i].get_small_cost() << " ";
			m << menu.get_pizzas()[i].get_medium_cost() << " ";
			m << menu.get_pizzas()[i].get_large_cost() << " ";
			m << menu.get_pizzas()[i].get_num_ingredients() << " ";
			for(int j = 0; j < menu.get_pizzas()[i].get_num_ingredients(); j++){
				m << menu.get_pizzas()[i].get_ingredients()[j] << " ";
			}
			m << endl;
		}
		m.close();
		remove("menu.txt");
		rename("MENU.txt", "menu.txt");
	}

	/*
	 *Function: rest write
	 *Description: writes the files for continuity
	 *Parameters: none
	 *Input: none
	 *Output: the new file is written to and saved
	 */
	void Restaurant::rest_write(){
		ofstream r;
		r.open("REST_INFO.txt");
		r << name << endl;
		r << phone << endl;
		r << address << endl;
		r << num_days << endl;
		for(int i = 0; i < get_num_days(); i++){
			r << week[i].day << " ";
			r << week[i].open_hour << " ";
			r << week[i].close_hour << " ";
			r << endl;
		}
		r << endl;
		r.close();
		remove("restaurant info.txt");
		rename("REST_INFO.txt", "restaurant info.txt");
	}

	/*
	 *Function: int check
	 *Description: checks if an integer is valid
	 *Parameters: none
	 *Input: none
	 *Output: a valid integer
	 */
	int Restaurant::int_check(){
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