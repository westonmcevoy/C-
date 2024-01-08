#ifndef ADDSTUDENT_HPP
#define ADDSTUDENT_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student{
    string name;
    string email;
    string birthday;
};

int addAstudent(student array[], string name, string birthday, string emailid, int count);

#endif 
