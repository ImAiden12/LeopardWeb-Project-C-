#pragma once

#include <string>
using std::string;

class Instructor
{
public:
	// Attribute
	string first_name;
	string last_name;
	int ID;
	string school_or_department;
	string email;

	// constructor
	Instructor();
};