#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct mult_div_values{
	int mult;
	float div;
};

bool check_args(int checked);
void set_mult_values(mult_div_values **table, int m, int n);
void set_div_values(mult_div_values **table, int m, int n);
void delete_table(mult_div_values ** table, int m);
mult_div_values** create_table(int m, int n);
void print_table_mult(mult_div_values **table, int m, int n);
void print_table_div(mult_div_values **table, int m, int n);