#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   vector<int> v1;
   vector<int> v2 = v;    //calls copy constructor
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v = v1;                //calls AOO
   v.push_back(23);
   stdv.push_back(23);
   
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   return 0;
}
