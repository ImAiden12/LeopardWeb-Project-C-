#pragma once

#include <string>
using std::string;

class Login
{
public:
	// Attribute
	int ID;
	string role;
	string password;
	string email;

	// constructor
	Login();
};