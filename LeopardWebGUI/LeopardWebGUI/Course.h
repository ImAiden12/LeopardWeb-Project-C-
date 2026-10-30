#pragma once

#include <string>
using std::string;

class Course
{
public:
	// Attribute
	int CRN;
	string type;
	string title;
	string subject;
	int credit_hours;
	string days_of_the_week;
	int start_time_hour;
	int start_time_min;
	int end_time_hour;
	int end_time_min;
	int professor_ID;

	// constructor
	Course();
};