#pragma once

#include <string>
using std::string;

class Student
{
public:
	// Attribute
	string first_name;
	string last_name;
	int ID;
	string expected_graduation_year;
	string major;
	string email;

	// constructor
	Student();
};