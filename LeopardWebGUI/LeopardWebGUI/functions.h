#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void user_login(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, bool& logged_in, string in_email, string in_password, Login& login);
void list_courses(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Instructor& instructor, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label);
void add_courses(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Login& login, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label);
void drop_courses(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Login& login, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label);
void show_schedule(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Instructor& instructor, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, Label^ label);
void check_conflicts(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Course& course2, Student& student, string misc_input, float time_start, float time_start2, float time_end, float time_end2, bool same_day, bool time_conflict, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, sqlite3_stmt* stmt_nest3, const char* sql_nest3, int rc_nest3, Label^ label);
void show_teaching_schedule(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Login& login, Instructor& instructor, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, Label^ label);
void show_student_schedule(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Instructor& instructor, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, Label^ label);
void show_class_roster(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Roster& roster, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label);
void admin_add_course(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, string misc_input, Course inCourse, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label);
void admin_add_student(Student inStudent, Login inLogin, string misc_input, const char* sql_nest, int rc_nest, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, sqlite3_stmt* stmt_nest, Label^ label);
void admin_add_instructor(Instructor inInstructor, Login inLogin, string misc_input, const char* sql_nest, int rc_nest, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, sqlite3_stmt* stmt_nest, Label^ label);
void admin_assign_user_class(Login inLogin, string in_ID, string in_CRN, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Student inStudent, Instructor inInstructor, Course course, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label);
void admin_unassign_user_class(Login inLogin, string in_ID, string in_CRN, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Student inStudent, Instructor inInstructor, Course course, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label);
void update_password(string in_email, string in_password, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label);