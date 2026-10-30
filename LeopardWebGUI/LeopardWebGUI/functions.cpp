#include <iostream> 
#include <string> 
#include <stdio.h>
#include "sqlite3.h"
#include "Student.h"
#include "Instructor.h"
#include "Admin.h"
#include "login.h"
#include "Course.h"
#include "Roster.h"
#include "functions.h"

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void user_login(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, bool& logged_in, string in_email, string in_password, Login& login) {
    cout << "----- Sign In -----" << endl;
    cout << "Please enter your email: ";
    cin >> in_email;
    // SET SQL FUNCTION 
    sql = "SELECT ID, Role, Password, Email FROM Login WHERE Email = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, in_email.c_str(), in_email.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        login.ID = sqlite3_column_int(stmt, 0);
        login.role = (char*)sqlite3_column_text(stmt, 1);
        login.password = (char*)sqlite3_column_text(stmt, 2);
        login.email = (char*)sqlite3_column_text(stmt, 3);
    }
    else {
        login.ID = 0;
        login.role.clear();
        login.password.clear();
        login.email.clear();
    }
    cout << "Please enter your password: ";
    cin >> in_password;
    if (login.password == in_password) {
        cout << endl;
        logged_in = true;
    }
    else {
        cout << "Email or Password are incorrect." << endl << endl;
    }
}

void list_courses(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course &course, Instructor &instructor, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label) {
    sql = "SELECT CRN, Type, Title, Subject, Credit_Hours, Days_of_the_Week, Start_Time_Hour, Start_Time_Min, End_Time_Hour, End_Time_Min, Professor_ID FROM Course";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.type = (char*)sqlite3_column_text(stmt, 1);
        course.title = (char*)sqlite3_column_text(stmt, 2);
        course.subject = (char*)sqlite3_column_text(stmt, 3);
        course.credit_hours = sqlite3_column_int(stmt, 4);
        course.days_of_the_week = (char*)sqlite3_column_text(stmt, 5);
        course.start_time_hour = sqlite3_column_int(stmt, 6);
        course.start_time_min = sqlite3_column_int(stmt, 7);
        course.end_time_hour = sqlite3_column_int(stmt, 8);
        course.end_time_min = sqlite3_column_int(stmt, 9);
        course.professor_ID = sqlite3_column_int(stmt, 10);
        label->Text = label->Text + course.CRN + " | " + gcnew System::String(course.title.c_str()) + " (" + gcnew System::String(course.type.c_str()) + ") |";
        if (course.days_of_the_week[0] == '1') {
            label->Text = label->Text + " Monday";
        }
        if (course.days_of_the_week[1] == '1') {
            label->Text = label->Text + " Tuesday";
        }
        if (course.days_of_the_week[2] == '1') {
            label->Text = label->Text + " Wednesday";
        }
        if (course.days_of_the_week[3] == '1') {
            label->Text = label->Text + " Thursday";
        }
        if (course.days_of_the_week[4] == '1') {
            label->Text = label->Text + " Friday";
        }
        label->Text = label->Text + "\nSubject: " + gcnew System::String(course.subject.c_str()) + " | Credits: " + course.credit_hours + "\n";
        label->Text = label->Text + "Time: " + course.start_time_hour + ":" + course.start_time_min;
        if (course.start_time_min == 0) {
            label->Text = label->Text + "0";
        }
        label->Text = label->Text + " - " + course.end_time_hour + ":" + course.end_time_min;
        if (course.end_time_min == 0) {
            label->Text = label->Text + "0";
        }
        label->Text = label->Text + "\n";
        sql_nest = "SELECT ID, First_Name, Last_Name, School_or_Department, Email FROM Instructor WHERE ID = ?";
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        // BIND TEXT
        rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(course.professor_ID).c_str(), to_string(course.professor_ID).length(), SQLITE_TRANSIENT);
        // RUN SQL FUNCTION
        rc_nest = sqlite3_step(stmt_nest);
        if (rc_nest == SQLITE_ROW) {
            instructor.ID = sqlite3_column_int(stmt_nest, 0);
            instructor.first_name = (char*)sqlite3_column_text(stmt_nest, 1);
            instructor.last_name = (char*)sqlite3_column_text(stmt_nest, 2);
            instructor.school_or_department = (char*)sqlite3_column_text(stmt_nest, 3);
            instructor.email = (char*)sqlite3_column_text(stmt_nest, 4);
        }
        label->Text = label->Text + "Instructor: " + gcnew System::String(instructor.first_name.c_str()) + " " + gcnew System::String(instructor.last_name.c_str()) + "\n\n";
    }
}

void add_courses(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Login& login, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label) {
    // SET SQL FUNCTION 
    sql = "SELECT CRN, Title FROM Course WHERE CRN = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, misc_input.c_str(), misc_input.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.title = (char*)sqlite3_column_text(stmt, 1);
        misc_input = "INSERT INTO '" + misc_input;
        misc_input = misc_input + "' VALUES (?, ?, ?, ?, ?)";
        sql_nest = misc_input.c_str();
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(student.ID).c_str(), to_string(student.ID).length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_bind_text(stmt_nest, 2, login.role.c_str(), login.role.length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_bind_text(stmt_nest, 3, student.first_name.c_str(), student.first_name.length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_bind_text(stmt_nest, 4, student.last_name.c_str(), student.last_name.length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_bind_text(stmt_nest, 5, student.email.c_str(), student.email.length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_step(stmt_nest);
        label->Visible = true;
        label->Text = "Added " + gcnew System::String(course.title.c_str()) + " to schedule.\n";
    }
    else {
        label->Visible = true;
        label->Text = "Invalid CRN\n";
    }
    label->Text = label->Text + "\n";
}

void drop_courses(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Login& login, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label) {
    // SET SQL FUNCTION 
    sql = "SELECT CRN, Title FROM Course WHERE CRN = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, misc_input.c_str(), misc_input.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.title = (char*)sqlite3_column_text(stmt, 1);
        misc_input = "DELETE FROM '" + misc_input;
        misc_input = misc_input + "' WHERE ID = ?";
        sql_nest = misc_input.c_str();
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(student.ID).c_str(), to_string(student.ID).length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_step(stmt_nest);
        label->Visible = true;
        label->Text = "Removed " + gcnew System::String(course.title.c_str()) + " from schedule.\n";
    }
    else {
        label->Visible = true;
        label->Text = "Invalid CRN\n";
    }
    label->Text = label->Text + "\n";
}

void show_schedule(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course &course, Student &student, Instructor &instructor, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, Label^ label) {
    sql = "SELECT CRN, Type, Title, Subject, Credit_Hours, Days_of_the_Week, Start_Time_Hour, Start_Time_Min, End_Time_Hour, End_Time_Min, Professor_ID FROM Course";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.type = (char*)sqlite3_column_text(stmt, 1);
        course.title = (char*)sqlite3_column_text(stmt, 2);
        course.subject = (char*)sqlite3_column_text(stmt, 3);
        course.credit_hours = sqlite3_column_int(stmt, 4);
        course.days_of_the_week = (char*)sqlite3_column_text(stmt, 5);
        course.start_time_hour = sqlite3_column_int(stmt, 6);
        course.start_time_min = sqlite3_column_int(stmt, 7);
        course.end_time_hour = sqlite3_column_int(stmt, 8);
        course.end_time_min = sqlite3_column_int(stmt, 9);
        course.professor_ID = sqlite3_column_int(stmt, 10);
        misc_input = "SELECT ID FROM '" + to_string(course.CRN);
        misc_input = misc_input + "' WHERE ID = ?";
        sql_nest = misc_input.c_str();
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(student.ID).c_str(), to_string(student.ID).length(), SQLITE_TRANSIENT);
        while (sqlite3_step(stmt_nest) == SQLITE_ROW) {
            label->Text = label->Text + course.CRN + " | " + gcnew System::String(course.title.c_str()) + " (" + gcnew System::String(course.type.c_str()) + ") |";
            if (course.days_of_the_week[0] == '1') {
                label->Text = label->Text + " Monday";
            }
            if (course.days_of_the_week[1] == '1') {
                label->Text = label->Text + " Tuesday";
            }
            if (course.days_of_the_week[2] == '1') {
                label->Text = label->Text + " Wednesday";
            }
            if (course.days_of_the_week[3] == '1') {
                label->Text = label->Text + " Thursday";
            }
            if (course.days_of_the_week[4] == '1') {
                label->Text = label->Text + " Friday";
            }
            label->Text = label->Text + "\nSubject: " + gcnew System::String(course.subject.c_str()) + " | Credits: " + course.credit_hours + "\n";
            label->Text = label->Text + "Time: " + course.start_time_hour + ":" + course.start_time_min;
            if (course.start_time_min == 0) {
                label->Text = label->Text + "0";
            }
            label->Text = label->Text + " - " + course.end_time_hour + ":" + course.end_time_min;
            if (course.end_time_min == 0) {
                label->Text = label->Text + "0";
            }
            label->Text = label->Text + "\n";
            sql_nest2 = "SELECT ID, First_Name, Last_Name, School_or_Department, Email FROM Instructor WHERE ID = ?";
            rc_nest2 = sqlite3_prepare_v2(db, sql_nest2, -1, &stmt_nest2, 0);
            // BIND TEXT
            rc_nest2 = sqlite3_bind_text(stmt_nest2, 1, to_string(course.professor_ID).c_str(), to_string(course.professor_ID).length(), SQLITE_TRANSIENT);
            // RUN SQL FUNCTION
            rc_nest2 = sqlite3_step(stmt_nest2);
            if (rc_nest2 == SQLITE_ROW) {
                instructor.ID = sqlite3_column_int(stmt_nest2, 0);
                instructor.first_name = (char*)sqlite3_column_text(stmt_nest2, 1);
                instructor.last_name = (char*)sqlite3_column_text(stmt_nest2, 2);
                instructor.school_or_department = (char*)sqlite3_column_text(stmt_nest2, 3);
                instructor.email = (char*)sqlite3_column_text(stmt_nest2, 4);
            }
            label->Text = label->Text + "Instructor: " + gcnew System::String(instructor.first_name.c_str()) + " " + gcnew System::String(instructor.last_name.c_str()) + "\n\n";
        }
    }
}

void check_conflicts(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course &course, Course& course2, Student &student, string misc_input, float time_start, float time_start2, float time_end, float time_end2, bool same_day, bool time_conflict, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, sqlite3_stmt* stmt_nest3, const char* sql_nest3, int rc_nest3, Label^ label) {
    sql = "SELECT CRN, Type, Title, Subject, Credit_Hours, Days_of_the_Week, Start_Time_Hour, Start_Time_Min, End_Time_Hour, End_Time_Min, Professor_ID FROM Course";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.type = (char*)sqlite3_column_text(stmt, 1);
        course.title = (char*)sqlite3_column_text(stmt, 2);
        course.subject = (char*)sqlite3_column_text(stmt, 3);
        course.credit_hours = sqlite3_column_int(stmt, 4);
        course.days_of_the_week = (char*)sqlite3_column_text(stmt, 5);
        course.start_time_hour = sqlite3_column_int(stmt, 6);
        course.start_time_min = sqlite3_column_int(stmt, 7);
        course.end_time_hour = sqlite3_column_int(stmt, 8);
        course.end_time_min = sqlite3_column_int(stmt, 9);
        course.professor_ID = sqlite3_column_int(stmt, 10);
        misc_input = "SELECT ID FROM '" + to_string(course.CRN);
        misc_input = misc_input + "' WHERE ID = ?";
        sql_nest = misc_input.c_str();
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(student.ID).c_str(), to_string(student.ID).length(), SQLITE_TRANSIENT);
        while (sqlite3_step(stmt_nest) == SQLITE_ROW) {
            // course is set to a course that the student is enrolled in in this while loop, repeat to get course 2
            sql_nest2 = "SELECT CRN, Type, Title, Subject, Credit_Hours, Days_of_the_Week, Start_Time_Hour, Start_Time_Min, End_Time_Hour, End_Time_Min, Professor_ID FROM Course";
            rc_nest2 = sqlite3_prepare_v2(db, sql_nest2, -1, &stmt_nest2, 0);
            while (sqlite3_step(stmt_nest2) == SQLITE_ROW) {
                course2.CRN = sqlite3_column_int(stmt_nest2, 0);
                course2.type = (char*)sqlite3_column_text(stmt_nest2, 1);
                course2.title = (char*)sqlite3_column_text(stmt_nest2, 2);
                course2.subject = (char*)sqlite3_column_text(stmt_nest2, 3);
                course2.credit_hours = sqlite3_column_int(stmt_nest2, 4);
                course2.days_of_the_week = (char*)sqlite3_column_text(stmt_nest2, 5);
                course2.start_time_hour = sqlite3_column_int(stmt_nest2, 6);
                course2.start_time_min = sqlite3_column_int(stmt_nest2, 7);
                course2.end_time_hour = sqlite3_column_int(stmt_nest2, 8);
                course2.end_time_min = sqlite3_column_int(stmt_nest2, 9);
                course2.professor_ID = sqlite3_column_int(stmt_nest2, 10);
                misc_input = "SELECT ID FROM '" + to_string(course2.CRN);
                misc_input = misc_input + "' WHERE ID = ?";
                sql_nest3 = misc_input.c_str();
                rc_nest3 = sqlite3_prepare_v2(db, sql_nest3, -1, &stmt_nest3, 0);
                rc_nest3 = sqlite3_bind_text(stmt_nest3, 1, to_string(student.ID).c_str(), to_string(student.ID).length(), SQLITE_TRANSIENT);
                while (sqlite3_step(stmt_nest3) == SQLITE_ROW) {
                    // course2 is set to a course that the student is enrolled in in this while loop
                    if (course2.CRN > course.CRN) {
                        time_start = course.start_time_hour + (float)course.start_time_min / 100;
                        time_end = course.end_time_hour + (float)course.end_time_min / 100;
                        time_start2 = course2.start_time_hour + (float)course2.start_time_min / 100;
                        time_end2 = course2.end_time_hour + (float)course2.end_time_min / 100;
                        for (int i = 0; i < 5; i++) {
                            if ((course.days_of_the_week[i] == '1') && (course2.days_of_the_week[i] == '1')) {
                                same_day = true;
                            }
                        }
                        if (same_day == true) {
                            if (((time_start2 >= time_start) && (time_start2 <= time_end)) || ((time_start >= time_start2) && (time_start <= time_end2))) {
                                time_conflict = true;
                                label->Text = label->Text + course.CRN + ": " + gcnew System::String(course.title.c_str()) + " conflicts with " + course2.CRN + ": " + gcnew System::String(course2.title.c_str()) + ".\n";
                            }
                        }
                    }
                }
                same_day = false;
            }
        }
    }
    if (time_conflict == false) {
        label->Text = label->Text + "There are no conflicts in your schedule.\n";
    }
    time_conflict = false;
    label->Text = label->Text + "\n";
}

void show_teaching_schedule(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Login& login, Instructor& instructor, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, Label^ label) {
    sql = "SELECT CRN, Type, Title, Subject, Credit_Hours, Days_of_the_Week, Start_Time_Hour, Start_Time_Min, End_Time_Hour, End_Time_Min, Professor_ID FROM Course";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.type = (char*)sqlite3_column_text(stmt, 1);
        course.title = (char*)sqlite3_column_text(stmt, 2);
        course.subject = (char*)sqlite3_column_text(stmt, 3);
        course.credit_hours = sqlite3_column_int(stmt, 4);
        course.days_of_the_week = (char*)sqlite3_column_text(stmt, 5);
        course.start_time_hour = sqlite3_column_int(stmt, 6);
        course.start_time_min = sqlite3_column_int(stmt, 7);
        course.end_time_hour = sqlite3_column_int(stmt, 8);
        course.end_time_min = sqlite3_column_int(stmt, 9);
        course.professor_ID = sqlite3_column_int(stmt, 10);
        misc_input = "SELECT ID FROM '" + to_string(course.CRN);
        misc_input = misc_input + "' WHERE ID = ?";
        sql_nest = misc_input.c_str();
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(login.ID).c_str(), to_string(login.ID).length(), SQLITE_TRANSIENT);
        while (sqlite3_step(stmt_nest) == SQLITE_ROW) {
            label->Text = label->Text + course.CRN + " | " + gcnew System::String(course.title.c_str()) + " (" + gcnew System::String(course.type.c_str()) + ") |";
            if (course.days_of_the_week[0] == '1') {
                label->Text = label->Text + " Monday";
            }
            if (course.days_of_the_week[1] == '1') {
                label->Text = label->Text + " Tuesday";
            }
            if (course.days_of_the_week[2] == '1') {
                label->Text = label->Text + " Wednesday";
            }
            if (course.days_of_the_week[3] == '1') {
                label->Text = label->Text + " Thursday";
            }
            if (course.days_of_the_week[4] == '1') {
                label->Text = label->Text + " Friday";
            }
            label->Text = label->Text + "\nSubject: " + gcnew System::String(course.subject.c_str()) + " | Credits: " + course.credit_hours + "\n";
            label->Text = label->Text + "Time: " + course.start_time_hour + ":" + course.start_time_min;
            if (course.start_time_min == 0) {
                label->Text = label->Text + "0";
            }
            label->Text = label->Text + " - " + course.end_time_hour + ":" + course.end_time_min;
            if (course.end_time_min == 0) {
                label->Text = label->Text + "0";
            }
            label->Text = label->Text + "\n";
            sql_nest2 = "SELECT ID, First_Name, Last_Name, School_or_Department, Email FROM Instructor WHERE ID = ?";
            rc_nest2 = sqlite3_prepare_v2(db, sql_nest2, -1, &stmt_nest2, 0);
            // BIND TEXT
            rc_nest2 = sqlite3_bind_text(stmt_nest2, 1, to_string(course.professor_ID).c_str(), to_string(course.professor_ID).length(), SQLITE_TRANSIENT);
            // RUN SQL FUNCTION
            rc_nest2 = sqlite3_step(stmt_nest2);
            if (rc_nest2 == SQLITE_ROW) {
                instructor.ID = sqlite3_column_int(stmt_nest2, 0);
                instructor.first_name = (char*)sqlite3_column_text(stmt_nest2, 1);
                instructor.last_name = (char*)sqlite3_column_text(stmt_nest2, 2);
                instructor.school_or_department = (char*)sqlite3_column_text(stmt_nest2, 3);
                instructor.email = (char*)sqlite3_column_text(stmt_nest2, 4);
            }
            label->Text = label->Text + "Instructor: " + gcnew System::String(instructor.first_name.c_str()) + " " + gcnew System::String(instructor.last_name.c_str()) + "\n\n";
        }
    }
}

void show_student_schedule(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course& course, Student& student, Instructor& instructor, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest2, const char* sql_nest2, int rc_nest2, Label^ label) {
    sql = "SELECT ID, First_Name, Last_Name, Expected_Graduation_Year, Major, Email FROM Student WHERE ID = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    rc = sqlite3_bind_text(stmt, 1, misc_input.c_str(), misc_input.length(), SQLITE_TRANSIENT);
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        student.ID = sqlite3_column_int(stmt, 0);
        student.first_name = (char*)sqlite3_column_text(stmt, 1);
        student.last_name = (char*)sqlite3_column_text(stmt, 2);
        student.expected_graduation_year = (char*)sqlite3_column_text(stmt, 3);
        student.major = (char*)sqlite3_column_text(stmt, 4);
        student.email = (char*)sqlite3_column_text(stmt, 5);
        label->Visible = true;
        label->Text = gcnew System::String(student.first_name.c_str()) + " " + gcnew System::String(student.last_name.c_str()) + "'s Schedule:\n\n";
        show_schedule(db, stmt, sql, rc, course, student, instructor, misc_input, stmt_nest, sql_nest, rc_nest, stmt_nest2, sql_nest2, rc_nest2, label);
    }
    else {
        label->Visible = true;
        label->Text = "Invalid Student ID!";
    }
}

void show_class_roster(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Course &course, Roster &roster, string misc_input, sqlite3_stmt* stmt_nest, const char* sql_nest, int rc_nest, Label^ label)  {
    sql = "SELECT CRN, Type, Title, Subject, Credit_Hours, Days_of_the_Week, Start_Time_Hour, Start_Time_Min, End_Time_Hour, End_Time_Min, Professor_ID FROM Course WHERE CRN = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    rc = sqlite3_bind_text(stmt, 1, misc_input.c_str(), misc_input.length(), SQLITE_TRANSIENT);
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        course.CRN = sqlite3_column_int(stmt, 0);
        course.type = (char*)sqlite3_column_text(stmt, 1);
        course.title = (char*)sqlite3_column_text(stmt, 2);
        course.subject = (char*)sqlite3_column_text(stmt, 3);
        course.credit_hours = sqlite3_column_int(stmt, 4);
        course.days_of_the_week = sqlite3_column_int(stmt, 5);
        course.start_time_hour = sqlite3_column_int(stmt, 6);
        course.start_time_min = sqlite3_column_int(stmt, 7);
        course.end_time_hour = sqlite3_column_int(stmt, 8);
        course.end_time_min = sqlite3_column_int(stmt, 9);
        course.professor_ID = sqlite3_column_int(stmt, 10);
        // Course is now set to the course with the user input CRN
        misc_input = "SELECT ID, Role, First_Name, Last_Name, Email FROM '" + misc_input;
        misc_input = misc_input + "'";
        sql_nest = misc_input.c_str();
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        label->Text = "";
        while (sqlite3_step(stmt_nest) == SQLITE_ROW) {
            roster.ID = sqlite3_column_int(stmt_nest, 0);
            roster.role = (char*)sqlite3_column_text(stmt_nest, 1);
            roster.first_name = (char*)sqlite3_column_text(stmt_nest, 2);
            roster.last_name = (char*)sqlite3_column_text(stmt_nest, 3);
            roster.email = (char*)sqlite3_column_text(stmt_nest, 4);
            label->Visible = true;
            label->Text = label->Text + gcnew System::String(roster.first_name.c_str()) + " " + gcnew System::String(roster.last_name.c_str()) + " (" + gcnew System::String(roster.role.c_str()) + ")" + "\n";
        }
        label->Text = label->Text + "\n";
    }
    else {
        label->Visible = true;
        label->Text = "Invalid CRN!\n\n";
    }
}

void admin_add_course(sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, string misc_input, Course inCourse, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label) {
    misc_input = "INSERT INTO Course";
    misc_input = misc_input + " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    sql_nest = misc_input.c_str();
    rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inCourse.CRN).c_str(), to_string(inCourse.CRN).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 2, inCourse.type.c_str(), inCourse.type.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 3, inCourse.title.c_str(), inCourse.title.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 4, inCourse.subject.c_str(), inCourse.subject.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 5, to_string(inCourse.credit_hours).c_str(), to_string(inCourse.credit_hours).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 6, inCourse.days_of_the_week.c_str(), inCourse.days_of_the_week.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 7, to_string(inCourse.start_time_hour).c_str(), to_string(inCourse.start_time_hour).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 8, to_string(inCourse.start_time_min).c_str(), to_string(inCourse.start_time_min).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 9, to_string(inCourse.end_time_hour).c_str(), to_string(inCourse.end_time_hour).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 10, to_string(inCourse.end_time_min).c_str(), to_string(inCourse.end_time_min).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 11, to_string(inCourse.professor_ID).c_str(), to_string(inCourse.professor_ID).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_step(stmt_nest);

    misc_input = to_string(inCourse.CRN);
    // SET SQL FUNCTION 
    misc_input = "CREATE TABLE '" + misc_input;
    misc_input = misc_input + "' (ID INTEGER PRIMARY KEY, Role TEXT NOT NULL, First_Name TEXT NOT NULL, Last_Name TEXT NOT NULL, Email TEXT NOT NULL)";
    sql = misc_input.c_str();
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, misc_input.c_str(), misc_input.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    label->Visible = true;
    label->Text = gcnew System::String(inCourse.title.c_str()) + " Created";
}

void admin_add_student(Student inStudent, Login inLogin, string misc_input, const char* sql_nest, int rc_nest, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, sqlite3_stmt* stmt_nest, Label^ label) {
    //Insert into Student Database
    misc_input = "INSERT INTO Student";
    misc_input = misc_input + " VALUES (?, ?, ?, ?, ?, ?)";
    sql_nest = misc_input.c_str();
    rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inStudent.ID).c_str(), to_string(inStudent.ID).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 2, inStudent.first_name.c_str(), inStudent.first_name.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 3, inStudent.last_name.c_str(), inStudent.last_name.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 4, inStudent.expected_graduation_year.c_str(), inStudent.expected_graduation_year.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 5, inStudent.major.c_str(), inStudent.major.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 6, inStudent.email.c_str(), inStudent.email.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_step(stmt_nest);

    //Gather Password information
    inLogin.email = inStudent.email;
    inLogin.ID = inStudent.ID;
    inLogin.role = "Student";

    //Insert into Login Database
    misc_input = "INSERT INTO Login";
    misc_input = misc_input + " VALUES (?, ?, ?, ?)";
    sql_nest = misc_input.c_str();
    rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inLogin.ID).c_str(), to_string(inLogin.ID).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 2, inLogin.role.c_str(), inLogin.role.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 3, inLogin.password.c_str(), inLogin.password.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 4, inLogin.email.c_str(), inLogin.email.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_step(stmt_nest);

    label->Visible = true;
    label->Text = gcnew System::String(inStudent.first_name.c_str()) + " " + gcnew System::String(inStudent.last_name.c_str()) + " Added";
}

void admin_add_instructor(Instructor inInstructor, Login inLogin, string misc_input, const char* sql_nest, int rc_nest, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, sqlite3_stmt* stmt_nest, Label^ label) {
    //Insert into Student Database
    misc_input = "INSERT INTO Instructor";
    misc_input = misc_input + " VALUES (?, ?, ?, ?, ?)";
    sql_nest = misc_input.c_str();
    rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inInstructor.ID).c_str(), to_string(inInstructor.ID).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 2, inInstructor.first_name.c_str(), inInstructor.first_name.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 3, inInstructor.last_name.c_str(), inInstructor.last_name.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 4, inInstructor.school_or_department.c_str(), inInstructor.school_or_department.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 5, inInstructor.email.c_str(), inInstructor.email.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_step(stmt_nest);

    //Gather Password information
    inLogin.email = inInstructor.email;
    inLogin.ID = inInstructor.ID;
    inLogin.role = "Instructor";

    //Insert into Login Database
    misc_input = "INSERT INTO Login";
    misc_input = misc_input + " VALUES (?, ?, ?, ?)";
    sql_nest = misc_input.c_str();
    rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inLogin.ID).c_str(), to_string(inLogin.ID).length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 2, inLogin.role.c_str(), inLogin.role.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 3, inLogin.password.c_str(), inLogin.password.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_bind_text(stmt_nest, 4, inLogin.email.c_str(), inLogin.email.length(), SQLITE_TRANSIENT);
    rc_nest = sqlite3_step(stmt_nest);
    label->Visible = true;
    label->Text = gcnew System::String(inInstructor.first_name.c_str()) + " " + gcnew System::String(inInstructor.last_name.c_str()) + " Added";
}

void admin_assign_user_class(Login inLogin, string in_ID, string in_CRN, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Student inStudent, Instructor inInstructor, Course course, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label) {
    //SET UP inLogin
    // SET SQL FUNCTION 
    sql = "SELECT Role FROM Login WHERE ID = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, in_ID.c_str(), in_ID.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        inLogin.role = (char*)sqlite3_column_text(stmt, 0);
    }
    else {
        label->Visible = true;
        label->Text = "Invalid ID\n";
    }
    cout << endl;

    //SET UP inStudent
    // SET SQL FUNCTION 
    if (inLogin.role == "Student") {
        sql = "SELECT ID, First_Name, Last_Name, Email FROM Student WHERE ID = ?";
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        // BIND TEXT
        rc = sqlite3_bind_text(stmt, 1, in_ID.c_str(), in_ID.length(), SQLITE_TRANSIENT);
        // RUN SQL FUNCTION
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            inStudent.ID = sqlite3_column_int(stmt, 0);
            inStudent.first_name = (char*)sqlite3_column_text(stmt, 1);
            inStudent.last_name = (char*)sqlite3_column_text(stmt, 2);
            inStudent.email = (char*)sqlite3_column_text(stmt, 3);
        }
    }
    else if (inLogin.role == "Instructor") {
        sql = "SELECT ID, First_Name, Last_Name, Email FROM Instructor WHERE ID = ?";
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        // BIND TEXT
        rc = sqlite3_bind_text(stmt, 1, in_ID.c_str(), in_ID.length(), SQLITE_TRANSIENT);
        // RUN SQL FUNCTION
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            inInstructor.ID = sqlite3_column_int(stmt, 0);
            inInstructor.first_name = (char*)sqlite3_column_text(stmt, 1);
            inInstructor.last_name = (char*)sqlite3_column_text(stmt, 2);
            inInstructor.email = (char*)sqlite3_column_text(stmt, 3);
        }
    }

    // SET SQL FUNCTION 
    sql = "SELECT CRN, Title FROM Course WHERE CRN = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, in_CRN.c_str(), in_CRN.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        if (inLogin.role == "Student") {
            course.CRN = sqlite3_column_int(stmt, 0);
            course.title = (char*)sqlite3_column_text(stmt, 1);
            in_CRN = "INSERT INTO '" + in_CRN;
            in_CRN = in_CRN + "' VALUES (?, ?, ?, ?, ?)";
            sql_nest = in_CRN.c_str();
            rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
            rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inStudent.ID).c_str(), to_string(inStudent.ID).length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 2, inLogin.role.c_str(), inLogin.role.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 3, inStudent.first_name.c_str(), inStudent.first_name.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 4, inStudent.last_name.c_str(), inStudent.last_name.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 5, inStudent.email.c_str(), inStudent.email.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_step(stmt_nest);
            label->Visible = true;
            label->Text = "Added " + gcnew System::String(course.title.c_str()) + " to " + gcnew System::String(inStudent.first_name.c_str()) + "'s schedule.";
        }
        else if (inLogin.role == "Instructor") {
            course.CRN = sqlite3_column_int(stmt, 0);
            course.title = (char*)sqlite3_column_text(stmt, 1);
            in_CRN = "INSERT INTO '" + in_CRN;
            in_CRN = in_CRN + "' VALUES (?, ?, ?, ?, ?)";
            sql_nest = in_CRN.c_str();
            rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
            rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inInstructor.ID).c_str(), to_string(inInstructor.ID).length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 2, inLogin.role.c_str(), inLogin.role.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 3, inInstructor.first_name.c_str(), inInstructor.first_name.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 4, inInstructor.last_name.c_str(), inInstructor.last_name.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_bind_text(stmt_nest, 5, inInstructor.email.c_str(), inInstructor.email.length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_step(stmt_nest);
            label->Visible = true;
            label->Text = "Added " + gcnew System::String(course.title.c_str()) + " to " + gcnew System::String(inInstructor.first_name.c_str()) + "'s schedule.";
        }
    }
    else {
        label->Visible = true;
        label->Text = "Invalid CRN";
    }
}

void admin_unassign_user_class(Login inLogin, string in_ID, string in_CRN, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, Student inStudent, Instructor inInstructor, Course course, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label) {
    //I know this is overkill but I just wanted it to say the student and to have the Invalid ID part included
    //Find ID of Student to put in class
    //SET UP inLogin
    // SET SQL FUNCTION 
    sql = "SELECT Role FROM Login WHERE ID = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, in_ID.c_str(), in_ID.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        inLogin.role = (char*)sqlite3_column_text(stmt, 0);
    }
    else {
        label->Visible = true;
        label->Text = "Invalid ID";
    }

    //SET UP inStudent
    // SET SQL FUNCTION 
    if (inLogin.role == "Student") {
        sql = "SELECT ID, First_Name, Last_Name, Email FROM Student WHERE ID = ?";
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        // BIND TEXT
        rc = sqlite3_bind_text(stmt, 1, in_ID.c_str(), in_ID.length(), SQLITE_TRANSIENT);
        // RUN SQL FUNCTION
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            inStudent.ID = sqlite3_column_int(stmt, 0);
            inStudent.first_name = (char*)sqlite3_column_text(stmt, 1);
            inStudent.last_name = (char*)sqlite3_column_text(stmt, 2);
            inStudent.email = (char*)sqlite3_column_text(stmt, 3);
        }
    }
    else if (inLogin.role == "Instructor") {
        sql = "SELECT ID, First_Name, Last_Name, Email FROM Instructor WHERE ID = ?";
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        // BIND TEXT
        rc = sqlite3_bind_text(stmt, 1, in_ID.c_str(), in_ID.length(), SQLITE_TRANSIENT);
        // RUN SQL FUNCTION
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            inInstructor.ID = sqlite3_column_int(stmt, 0);
            inInstructor.first_name = (char*)sqlite3_column_text(stmt, 1);
            inInstructor.last_name = (char*)sqlite3_column_text(stmt, 2);
            inInstructor.email = (char*)sqlite3_column_text(stmt, 3);
        }
    }

    //Find CRN of Class
    // SET SQL FUNCTION 
    sql = "SELECT CRN, Title FROM Course WHERE CRN = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, in_CRN.c_str(), in_CRN.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        if (inLogin.role == "Student") {
            course.CRN = sqlite3_column_int(stmt, 0);
            course.title = (char*)sqlite3_column_text(stmt, 1);
            in_CRN = "DELETE FROM '" + in_CRN;
            in_CRN = in_CRN + "' WHERE ID = ?";
            sql_nest = in_CRN.c_str();
            rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
            rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inStudent.ID).c_str(), to_string(inStudent.ID).length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_step(stmt_nest);
            label->Visible = true;
            label->Text = "Deleted " + gcnew System::String(course.title.c_str()) + " from " + gcnew System::String(inStudent.first_name.c_str()) + "'s schedule.";
        }
        else if (inLogin.role == "Instructor") {
            course.CRN = sqlite3_column_int(stmt, 0);
            course.title = (char*)sqlite3_column_text(stmt, 1);
            in_CRN = "DELETE FROM '" + in_CRN;
            in_CRN = in_CRN + "' WHERE ID = ?";
            sql_nest = in_CRN.c_str();
            rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
            rc_nest = sqlite3_bind_text(stmt_nest, 1, to_string(inInstructor.ID).c_str(), to_string(inInstructor.ID).length(), SQLITE_TRANSIENT);
            rc_nest = sqlite3_step(stmt_nest);
            label->Visible = true;
            label->Text = "Deleted " + gcnew System::String(course.title.c_str()) + " from " + gcnew System::String(inInstructor.first_name.c_str()) + "'s schedule.";
        }
    }
    else {
        label->Visible = true;
        label->Text = "Invalid CRN";
    }
}

void update_password(string in_email, string in_password, sqlite3* db, sqlite3_stmt* stmt, const char* sql, int rc, const char* sql_nest, int rc_nest, sqlite3_stmt* stmt_nest, Label^ label) {
    sql = "SELECT ID FROM Login WHERE email = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // BIND TEXT
    rc = sqlite3_bind_text(stmt, 1, in_email.c_str(), in_email.length(), SQLITE_TRANSIENT);
    // RUN SQL FUNCTION
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        sql_nest = "UPDATE Login SET password = ? WHERE email = ?";
        rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
        // BIND TEXT
        rc_nest = sqlite3_bind_text(stmt_nest, 1, in_password.c_str(), in_password.length(), SQLITE_TRANSIENT);
        rc_nest = sqlite3_bind_text(stmt_nest, 2, in_email.c_str(), in_email.length(), SQLITE_TRANSIENT);
        // RUN SQL FUNCTION
        rc_nest = sqlite3_step(stmt_nest);
        label->Visible = true;
        label->Text = "Password updated for " + gcnew System::String(in_email.c_str());
    }
    else {
        label->Visible = true;
        label->Text = "Invalid Email";
    }
}