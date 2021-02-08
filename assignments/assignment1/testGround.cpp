#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main(){
string name = "Love", name1 = "Llove";
string temp;
cout << "Presorted: " << name << " and " << name1 << " and " << endl;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				if(name[k] > name1[k]){
					temp = name;
					name = name1;
					name1 = temp;
					break;
				}
				k++;
			}
		}
	}
	cout << "Sorted: " << name << " and " << name1 << endl;
}