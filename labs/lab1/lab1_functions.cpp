#include "header.h"
using namespace std;

bool check_args(int checked){
	if(checked > 0){
		return true;
	}
	else
		return false;
}

void set_mult_values(mult_div_values **table, int m, int n);
void set_div_values(mult_div_values **table, int m, int n);
void delete_table(mult_div_values ** table, int m);

mult_div_values** create_table(int m, int n){
	mult_div_values **table = new mult_div_values *[m + 1];
	for(int i = 1; i < m + 1; i++){
		table[i] = new mult_div_values[n + 1];
	}
	set_mult_values(table, m, n);
	set_div_values(table, m, n);
	delete_table(table, m);
}

void print_table_mult(mult_div_values **table, int m, int n){
	for(int i = 1; i < m + 1; i++){
		for(int j = 1; j < n + 1; j++){
			cout << table[i][j].mult << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_table_div(mult_div_values **table, int m, int n){
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			cout << table[i][j].div << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void set_mult_values(mult_div_values **table, int m, int n){
	for(int i = 1; i < m + 1; i++){
		for(int j = 1; j < n + 1; j++){
			table[i][j].mult = i * j;
		}
	}
	print_table_mult(table, m, n);
}

void set_div_values(mult_div_values **table, int m, int n){
	for(int i = 1; i < m + 1; i++){
		for(int j = 1; j < n + 1; j++){
			table[i][j].div = (float)i / (float)j;
		}
	}
	print_table_div(table, m, n);
}

void delete_table(mult_div_values ** table, int m){
	for(int i = 0; i < m; i++){
		delete [] table[i];
	}
	delete [] table;
}

