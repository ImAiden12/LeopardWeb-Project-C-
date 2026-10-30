#pragma once

#include <string>
using std::string;

class Roster
{
public:
	// Attribute
	int ID;
	string role;
	string first_name;
	string last_name;
	string email;

	// constructor
	Roster();
};