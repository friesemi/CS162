
#ifndef STRUCT_H
#define STRUCT_H
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

struct employee{
	string id;
	string first_name;
	string last_name;
	string password;
};

struct hours{
	string day;
	string open_hour;
	string close_hour;
};

#endif