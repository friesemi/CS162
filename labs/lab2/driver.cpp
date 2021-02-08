#include "student_db.h"

using namespace std;

int main(){
	fstream f;
	ofstream o;
	int num = 0;
	f.open("input.txt");
	o.open("output.txt");
	if(f.is_open()){
		f >> num;
		cout << num << endl;
		student *array = create_student_db(num);
		get_student_db_info(array, num, f);
		sort_ID(array, num, o);
		sort_last_name(array, num, o);
		unique_major(array, num, o);
		delete_student_db_info(&array, num);
		
	}
	else
		cout << "Error opening file" << endl;
	f.close();

	return 0;
}