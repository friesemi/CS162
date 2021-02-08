#include "header.h"

using namespace std;

int main(int argc, char **argv){
	int rows = 0, cols = 0;
	rows = atoi(argv[1]);
	if(check_args(rows) == false){
		cout << "Incorrect Integer\nEnter new integer: ";
		cin >> rows;
	}
	cols = atoi(argv[2]);
		if(check_args(cols) == false){
		cout << "Incorrect Integer\nEnter new integer: ";
		cin >> cols;
	}
	create_table(rows, cols);

	return 0;
}