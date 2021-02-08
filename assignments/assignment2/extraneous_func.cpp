#include "structs.h"

	/*
	 *Function: int check
	 *Description: checks if an integer is valid
	 *Parameters: none
	 *Input: none
	 *Output: a valid integer
	 */
	int int_check(){
		string checker;
		int integer = 0;
		bool test;
		do{
			cout << "Enter an integer: ";
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