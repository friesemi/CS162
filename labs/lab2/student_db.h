#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

struct student{
	int num_students;
	string first_name;
	string last_name;
	string major;
};

student *create_student_db(int);
void get_student_db_info(student *, int, fstream &);
void delete_student_db_info(student **, int);
void sort_ID(student *, int, ofstream &);
void sort_last_name(student *, int, ofstream &);
void unique_major(student *, int, ofstream &);