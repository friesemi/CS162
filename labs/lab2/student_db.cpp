#include "student_db.h"

using namespace std;

student *create_student_db(int num){
	student *array = new student[num];
	return array;
}

void get_student_db_info(student *array, int num, fstream &f){
	for(int i = 0; i < num; i++){
		f >> array[i].num_students;
		cout << array[i].num_students << " ";
		f >> array[i].first_name;
		cout << array[i].first_name << " ";
		f >> array[i].last_name;
		cout << array[i].last_name << " ";
		f >> array[i].major;
		cout << array[i].major << " ";
		cout << endl; 
	}
}

void sort_ID(student *array, int num, ofstream &o){
	int temp = 0;
	for(int i = 0; i < num - 1; i++){
		for(int j = 0; j < num - 1 - i; j++){
			if(array[j].num_students > array[j+1].num_students){
				temp = array[j].num_students;
				array[j].num_students = array[j+1].num_students;
				array[j+1].num_students = temp; 
			}
		}
	}
	o << "Sorted by ID\n";
	for(int i = 0; i < num; i++){
		o << array[i].num_students << " ";
		o << array[i].first_name << " ";
		o << array[i].last_name << " ";
		o << array[i].major;
		o << endl;
	}
	o << endl;
}

void sort_last_name(student *array, int num, ofstream &o){
	string temp;
	for(int i = 0; i < num - 1; i++){
		for(int j = 0; j < num - 1 - i; j++){
			if(array[j].last_name < array[j+1].last_name){
				temp = array[j].last_name;
				array[j].last_name = array[j+1].last_name;
				array[j+1].last_name = temp;
			}
		}
	}
	o << "Sorted by last name\n";
	for(int i = 0; i < num; i++){
		o << array[i].num_students << " ";
		o << array[i].first_name << " ";
		o << array[i].last_name << " ";
		o << array[i].major << " ";
		o << endl;
	}
	o << endl;
}

void unique_major(student *array, int num, ofstream &o){
	int count = 0;
	for(int i = 0; i < num - 1; i++){
		if(array[i].major == array[i+1].major);
			count += 1;
	}
	o << "The number of unique majors is: " << count << endl;
}


void delete_student_db_info(student **array, int num){
	delete [] *array;
}