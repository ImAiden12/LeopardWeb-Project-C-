#pragma once

#include <iostream> 
#include <string> 
#include <stdio.h>
#include "sqlite3.h"
#include "Student.h"
#include "Instructor.h"
#include "Admin.h"
#include "Login.h"
#include "Course.h"
#include "Roster.h"
#include "functions.h"

using namespace System;

Student student;
Instructor instructor;
Admin admin;
Login login;
Course course;
Course course2;
Roster roster;

bool logged_in = false;
string in_email;
string in_password;
int choice = 0;
bool run_program = true;

sqlite3* db;
sqlite3_stmt* stmt;
const char* sql;
int rc;
sqlite3_stmt* stmt_nest;
const char* sql_nest;
int rc_nest;
sqlite3_stmt* stmt_nest2;
const char* sql_nest2;
int rc_nest2;
sqlite3_stmt* stmt_nest3;
const char* sql_nest3;
int rc_nest3;

bool same_day = false;
bool time_conflict = false;
float time_start = 0;
float time_end = 0;
float time_start2 = 0;
float time_end2 = 0;

string misc_input;

//System String to std string from Microsoft
void MarshalString(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

namespace LeopardWebGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::TextBox^ textBox17;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::TextBox^ textBox18;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::TextBox^ textBox20;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::Button^ button28;
private: System::Windows::Forms::TextBox^ textBox21;
private: System::Windows::Forms::TextBox^ textBox22;
private: System::Windows::Forms::TextBox^ textBox23;
private: System::Windows::Forms::TextBox^ textBox24;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Label^ label42;
private: System::Windows::Forms::Label^ label43;
private: System::Windows::Forms::Button^ button29;
private: System::Windows::Forms::TextBox^ textBox28;
private: System::Windows::Forms::TextBox^ textBox29;
private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::Button^ button30;
private: System::Windows::Forms::TextBox^ textBox19;
private: System::Windows::Forms::TextBox^ textBox25;
private: System::Windows::Forms::Label^ label45;
private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::Button^ button31;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::Button^ button32;
private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::Label^ label52;
private: System::Windows::Forms::Button^ button33;
private: System::Windows::Forms::TextBox^ textBox27;
private: System::Windows::Forms::TextBox^ textBox26;
private: System::Windows::Forms::Label^ label51;
private: System::Windows::Forms::Label^ label50;
private: System::Windows::Forms::Label^ label53;














	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel12->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label1->Location = System::Drawing::Point(22, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Username:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label2->Location = System::Drawing::Point(29, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 39);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->textBox1->Location = System::Drawing::Point(211, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(232, 30);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->button1->Location = System::Drawing::Point(25, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(418, 42);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(24, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(419, 29);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Incorrect Username or Password!";
			this->label3->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->textBox2->Location = System::Drawing::Point(211, 90);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(232, 30);
			this->textBox2->TabIndex = 6;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(898, 451);
			this->panel1->TabIndex = 7;
			this->panel1->Visible = false;
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->Controls->Add(this->button9);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(444, 62);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(444, 386);
			this->panel2->TabIndex = 7;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(122, 51);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 4;
			this->button9->Text = L"Enter";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 79);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 16);
			this->label6->TabIndex = 3;
			this->label6->Text = L"label6";
			this->label6->Visible = false;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(122, 51);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Enter";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(16, 52);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 1;
			this->textBox3->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 16);
			this->label5->TabIndex = 0;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(20, 302);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(257, 42);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Logout";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(20, 254);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(257, 42);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Display Schedule";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(20, 206);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(257, 42);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Check Schedule Conflicts";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(20, 158);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(257, 42);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Drop Courses";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(20, 110);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(257, 42);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Add Courses";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(20, 62);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(257, 42);
			this->button2->TabIndex = 1;
			this->button2->Text = L"List Courses";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label4->Location = System::Drawing::Point(17, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(264, 39);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Welcome USER";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->button13);
			this->panel3->Controls->Add(this->button14);
			this->panel3->Controls->Add(this->button15);
			this->panel3->Controls->Add(this->button16);
			this->panel3->Controls->Add(this->button17);
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(898, 451);
			this->panel3->TabIndex = 8;
			this->panel3->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label9->Location = System::Drawing::Point(17, 13);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(264, 39);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Welcome USER";
			// 
			// panel4
			// 
			this->panel4->AutoScroll = true;
			this->panel4->Controls->Add(this->button11);
			this->panel4->Controls->Add(this->button10);
			this->panel4->Controls->Add(this->label7);
			this->panel4->Controls->Add(this->textBox4);
			this->panel4->Controls->Add(this->label8);
			this->panel4->Location = System::Drawing::Point(444, 62);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(444, 386);
			this->panel4->TabIndex = 7;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(122, 51);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 2;
			this->button11->Text = L"Enter";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Visible = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(122, 51);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 4;
			this->button10->Text = L"Enter";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Visible = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 79);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 16);
			this->label7->TabIndex = 3;
			this->label7->Text = L"label7";
			this->label7->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(16, 52);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 1;
			this->textBox4->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(13, 16);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 16);
			this->label8->TabIndex = 0;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(20, 254);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(257, 42);
			this->button13->TabIndex = 5;
			this->button13->Text = L"Logout";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(20, 206);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(257, 42);
			this->button14->TabIndex = 4;
			this->button14->Text = L"Show Class Roster";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(20, 158);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(257, 42);
			this->button15->TabIndex = 3;
			this->button15->Text = L"Show Student Schedule";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(20, 110);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(257, 42);
			this->button16->TabIndex = 2;
			this->button16->Text = L"Show Teaching Schedule";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(20, 62);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(257, 42);
			this->button17->TabIndex = 1;
			this->button17->Text = L"List Courses";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->panel11);
			this->panel5->Controls->Add(this->panel10);
			this->panel5->Controls->Add(this->panel9);
			this->panel5->Controls->Add(this->panel8);
			this->panel5->Controls->Add(this->panel7);
			this->panel5->Controls->Add(this->button25);
			this->panel5->Controls->Add(this->button24);
			this->panel5->Controls->Add(this->label10);
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->button19);
			this->panel5->Controls->Add(this->button20);
			this->panel5->Controls->Add(this->button21);
			this->panel5->Controls->Add(this->button22);
			this->panel5->Controls->Add(this->button23);
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(898, 451);
			this->panel5->TabIndex = 9;
			this->panel5->Visible = false;
			// 
			// panel11
			// 
			this->panel11->AutoScroll = true;
			this->panel11->Controls->Add(this->label36);
			this->panel11->Controls->Add(this->label44);
			this->panel11->Controls->Add(this->button30);
			this->panel11->Controls->Add(this->textBox19);
			this->panel11->Controls->Add(this->textBox25);
			this->panel11->Controls->Add(this->label45);
			this->panel11->Controls->Add(this->label46);
			this->panel11->Location = System::Drawing::Point(444, 62);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(444, 386);
			this->panel11->TabIndex = 31;
			this->panel11->Visible = false;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(13, 104);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(51, 16);
			this->label36->TabIndex = 24;
			this->label36->Text = L"label36";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(13, 301);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(0, 16);
			this->label44->TabIndex = 23;
			this->label44->Visible = false;
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(9, 66);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(213, 32);
			this->button30->TabIndex = 22;
			this->button30->Text = L"Remove User";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(122, 38);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(100, 22);
			this->textBox19->TabIndex = 10;
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(122, 10);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(100, 22);
			this->textBox25->TabIndex = 9;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(13, 44);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(39, 16);
			this->label45->TabIndex = 1;
			this->label45->Text = L"CRN:";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(13, 16);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(23, 16);
			this->label46->TabIndex = 0;
			this->label46->Text = L"ID:";
			// 
			// panel10
			// 
			this->panel10->AutoScroll = true;
			this->panel10->Controls->Add(this->label42);
			this->panel10->Controls->Add(this->label43);
			this->panel10->Controls->Add(this->button29);
			this->panel10->Controls->Add(this->textBox28);
			this->panel10->Controls->Add(this->textBox29);
			this->panel10->Controls->Add(this->label47);
			this->panel10->Controls->Add(this->label48);
			this->panel10->Location = System::Drawing::Point(444, 62);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(444, 386);
			this->panel10->TabIndex = 30;
			this->panel10->Visible = false;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(13, 104);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(51, 16);
			this->label42->TabIndex = 24;
			this->label42->Text = L"label42";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(13, 301);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(0, 16);
			this->label43->TabIndex = 23;
			this->label43->Visible = false;
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(9, 66);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(213, 32);
			this->button29->TabIndex = 22;
			this->button29->Text = L"Add User";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(122, 38);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(100, 22);
			this->textBox28->TabIndex = 10;
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(122, 10);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(100, 22);
			this->textBox29->TabIndex = 9;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(13, 44);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(39, 16);
			this->label47->TabIndex = 1;
			this->label47->Text = L"CRN:";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(13, 16);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(23, 16);
			this->label48->TabIndex = 0;
			this->label48->Text = L"ID:";
			// 
			// panel9
			// 
			this->panel9->AutoScroll = true;
			this->panel9->Controls->Add(this->textBox18);
			this->panel9->Controls->Add(this->label27);
			this->panel9->Controls->Add(this->textBox20);
			this->panel9->Controls->Add(this->label28);
			this->panel9->Controls->Add(this->label35);
			this->panel9->Controls->Add(this->button28);
			this->panel9->Controls->Add(this->textBox21);
			this->panel9->Controls->Add(this->textBox22);
			this->panel9->Controls->Add(this->textBox23);
			this->panel9->Controls->Add(this->textBox24);
			this->panel9->Controls->Add(this->label37);
			this->panel9->Controls->Add(this->label38);
			this->panel9->Controls->Add(this->label39);
			this->panel9->Controls->Add(this->label40);
			this->panel9->Controls->Add(this->label41);
			this->panel9->Location = System::Drawing::Point(444, 62);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(444, 386);
			this->panel9->TabIndex = 29;
			this->panel9->Visible = false;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(122, 152);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(100, 22);
			this->textBox18->TabIndex = 28;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(13, 158);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(70, 16);
			this->label27->TabIndex = 27;
			this->label27->Text = L"Password:";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(122, 122);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(100, 22);
			this->textBox20->TabIndex = 25;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(13, 218);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(51, 16);
			this->label28->TabIndex = 24;
			this->label28->Text = L"label28";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(13, 301);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(0, 16);
			this->label35->TabIndex = 23;
			this->label35->Visible = false;
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(9, 180);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(213, 32);
			this->button28->TabIndex = 22;
			this->button28->Text = L"Add Instructor";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(122, 94);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(100, 22);
			this->textBox21->TabIndex = 12;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(122, 66);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(100, 22);
			this->textBox22->TabIndex = 11;
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(122, 38);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(100, 22);
			this->textBox23->TabIndex = 10;
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(122, 10);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(100, 22);
			this->textBox24->TabIndex = 9;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(13, 128);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(44, 16);
			this->label37->TabIndex = 4;
			this->label37->Text = L"Email:";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(13, 100);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(88, 16);
			this->label38->TabIndex = 3;
			this->label38->Text = L"Dedpartment:";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(13, 72);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(75, 16);
			this->label39->TabIndex = 2;
			this->label39->Text = L"Last Name:";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(13, 44);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(75, 16);
			this->label40->TabIndex = 1;
			this->label40->Text = L"First Name:";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(13, 16);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(23, 16);
			this->label41->TabIndex = 0;
			this->label41->Text = L"ID:";
			// 
			// panel8
			// 
			this->panel8->AutoScroll = true;
			this->panel8->Controls->Add(this->textBox17);
			this->panel8->Controls->Add(this->label26);
			this->panel8->Controls->Add(this->textBox16);
			this->panel8->Controls->Add(this->textBox11);
			this->panel8->Controls->Add(this->label24);
			this->panel8->Controls->Add(this->label25);
			this->panel8->Controls->Add(this->button27);
			this->panel8->Controls->Add(this->textBox12);
			this->panel8->Controls->Add(this->textBox13);
			this->panel8->Controls->Add(this->textBox14);
			this->panel8->Controls->Add(this->textBox15);
			this->panel8->Controls->Add(this->label29);
			this->panel8->Controls->Add(this->label30);
			this->panel8->Controls->Add(this->label31);
			this->panel8->Controls->Add(this->label32);
			this->panel8->Controls->Add(this->label33);
			this->panel8->Controls->Add(this->label34);
			this->panel8->Location = System::Drawing::Point(444, 62);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(444, 386);
			this->panel8->TabIndex = 25;
			this->panel8->Visible = false;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(122, 180);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(100, 22);
			this->textBox17->TabIndex = 28;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(13, 186);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(70, 16);
			this->label26->TabIndex = 27;
			this->label26->Text = L"Password:";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(122, 152);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(100, 22);
			this->textBox16->TabIndex = 26;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(122, 122);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 22);
			this->textBox11->TabIndex = 25;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(13, 244);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(51, 16);
			this->label24->TabIndex = 24;
			this->label24->Text = L"label24";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(13, 301);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(0, 16);
			this->label25->TabIndex = 23;
			this->label25->Visible = false;
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(9, 206);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(213, 32);
			this->button27->TabIndex = 22;
			this->button27->Text = L"Add Student";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(122, 94);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(100, 22);
			this->textBox12->TabIndex = 12;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(122, 66);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 22);
			this->textBox13->TabIndex = 11;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(122, 38);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 22);
			this->textBox14->TabIndex = 10;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(122, 10);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(100, 22);
			this->textBox15->TabIndex = 9;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(13, 158);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(44, 16);
			this->label29->TabIndex = 5;
			this->label29->Text = L"Email:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(13, 128);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(44, 16);
			this->label30->TabIndex = 4;
			this->label30->Text = L"Major:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(13, 100);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(108, 16);
			this->label31->TabIndex = 3;
			this->label31->Text = L"Graduation Year:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(13, 72);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(75, 16);
			this->label32->TabIndex = 2;
			this->label32->Text = L"Last Name:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(13, 44);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(75, 16);
			this->label33->TabIndex = 1;
			this->label33->Text = L"First Name:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(13, 16);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(23, 16);
			this->label34->TabIndex = 0;
			this->label34->Text = L"ID:";
			// 
			// panel7
			// 
			this->panel7->AutoScroll = true;
			this->panel7->Controls->Add(this->label23);
			this->panel7->Controls->Add(this->label22);
			this->panel7->Controls->Add(this->button26);
			this->panel7->Controls->Add(this->textBox10);
			this->panel7->Controls->Add(this->comboBox3);
			this->panel7->Controls->Add(this->comboBox2);
			this->panel7->Controls->Add(this->checkBox5);
			this->panel7->Controls->Add(this->checkBox4);
			this->panel7->Controls->Add(this->checkBox3);
			this->panel7->Controls->Add(this->checkBox2);
			this->panel7->Controls->Add(this->checkBox1);
			this->panel7->Controls->Add(this->comboBox1);
			this->panel7->Controls->Add(this->textBox9);
			this->panel7->Controls->Add(this->textBox8);
			this->panel7->Controls->Add(this->textBox7);
			this->panel7->Controls->Add(this->textBox6);
			this->panel7->Controls->Add(this->label21);
			this->panel7->Controls->Add(this->label20);
			this->panel7->Controls->Add(this->label19);
			this->panel7->Controls->Add(this->label18);
			this->panel7->Controls->Add(this->label17);
			this->panel7->Controls->Add(this->label16);
			this->panel7->Controls->Add(this->label15);
			this->panel7->Controls->Add(this->label13);
			this->panel7->Controls->Add(this->label14);
			this->panel7->Location = System::Drawing::Point(444, 62);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(444, 386);
			this->panel7->TabIndex = 10;
			this->panel7->Visible = false;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(13, 301);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(51, 16);
			this->label23->TabIndex = 24;
			this->label23->Text = L"label23";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(13, 301);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(0, 16);
			this->label22->TabIndex = 23;
			this->label22->Visible = false;
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(9, 264);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(213, 32);
			this->button26->TabIndex = 22;
			this->button26->Text = L"Create Course";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(122, 236);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 22);
			this->textBox10->TabIndex = 21;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(45) {
				L"8:00", L"8:15", L"8:30", L"8:45", L"9:00", L"9:15",
					L"9:30", L"9:45", L"10:00", L"10:15", L"10:30", L"10:45", L"11:00", L"11:15", L"11:30", L"11:45", L"12:00", L"12:15", L"12:30",
					L"12:45", L"13:00", L"13:15", L"13:30", L"13:45", L"14:00", L"14:15", L"14:30", L"14:45", L"15:00", L"15:15", L"15:30", L"15:45",
					L"16:00", L"16:15", L"16:30", L"16:45", L"17:00", L"17:15", L"17:30", L"17:45", L"18:00", L"18:15", L"18:30", L"18:45", L"19:00"
			});
			this->comboBox3->Location = System::Drawing::Point(122, 206);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(100, 24);
			this->comboBox3->TabIndex = 20;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(45) {
				L"8:00", L"8:15", L"8:30", L"8:45", L"9:00", L"9:15",
					L"9:30", L"9:45", L"10:00", L"10:15", L"10:30", L"10:45", L"11:00", L"11:15", L"11:30", L"11:45", L"12:00", L"12:15", L"12:30",
					L"12:45", L"13:00", L"13:15", L"13:30", L"13:45", L"14:00", L"14:15", L"14:30", L"14:45", L"15:00", L"15:15", L"15:30", L"15:45",
					L"16:00", L"16:15", L"16:30", L"16:45", L"17:00", L"17:15", L"17:30", L"17:45", L"18:00", L"18:15", L"18:30", L"18:45", L"19:00"
			});
			this->comboBox2->Location = System::Drawing::Point(122, 176);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 24);
			this->comboBox2->TabIndex = 19;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(278, 151);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(37, 20);
			this->checkBox5->TabIndex = 18;
			this->checkBox5->Text = L"F";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(237, 150);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(45, 20);
			this->checkBox4->TabIndex = 17;
			this->checkBox4->Text = L"Th";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(198, 150);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(42, 20);
			this->checkBox3->TabIndex = 16;
			this->checkBox3->Text = L"W";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(157, 150);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(45, 20);
			this->checkBox2->TabIndex = 15;
			this->checkBox2->Text = L"Tu";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(122, 150);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(40, 20);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"M";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0", L"1", L"2", L"3", L"4" });
			this->comboBox1->Location = System::Drawing::Point(122, 122);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 24);
			this->comboBox1->TabIndex = 13;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(122, 94);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 22);
			this->textBox9->TabIndex = 12;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(122, 66);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 11;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(122, 38);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(122, 10);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 9;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(13, 242);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(84, 16);
			this->label21->TabIndex = 8;
			this->label21->Text = L"Professor ID:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(13, 214);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(68, 16);
			this->label20->TabIndex = 7;
			this->label20->Text = L"End Time:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(13, 184);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(71, 16);
			this->label19->TabIndex = 6;
			this->label19->Text = L"Start Time:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(13, 152);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(42, 16);
			this->label18->TabIndex = 5;
			this->label18->Text = L"Days:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(13, 130);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(84, 16);
			this->label17->TabIndex = 4;
			this->label17->Text = L"Credit Hours:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(13, 100);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(55, 16);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Subject:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(13, 72);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(36, 16);
			this->label15->TabIndex = 2;
			this->label15->Text = L"Title:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(13, 44);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(42, 16);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Type:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(13, 16);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(39, 16);
			this->label14->TabIndex = 0;
			this->label14->Text = L"CRN:";
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(20, 350);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(257, 42);
			this->button25->TabIndex = 9;
			this->button25->Text = L"Logout";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(20, 302);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(257, 42);
			this->button24->TabIndex = 8;
			this->button24->Text = L"Remove User From Class";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label10->Location = System::Drawing::Point(17, 13);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(264, 39);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Welcome USER";
			// 
			// panel6
			// 
			this->panel6->AutoScroll = true;
			this->panel6->Controls->Add(this->button12);
			this->panel6->Controls->Add(this->button18);
			this->panel6->Controls->Add(this->label11);
			this->panel6->Controls->Add(this->textBox5);
			this->panel6->Controls->Add(this->label12);
			this->panel6->Location = System::Drawing::Point(444, 62);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(444, 386);
			this->panel6->TabIndex = 7;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(122, 51);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 2;
			this->button12->Text = L"Enter";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(122, 51);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(75, 23);
			this->button18->TabIndex = 4;
			this->button18->Text = L"Enter";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(13, 79);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 16);
			this->label11->TabIndex = 3;
			this->label11->Text = L"label11";
			this->label11->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(16, 52);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 1;
			this->textBox5->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(13, 16);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 16);
			this->label12->TabIndex = 0;
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(20, 254);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(257, 42);
			this->button19->TabIndex = 5;
			this->button19->Text = L"Add User to Class";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(20, 206);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(257, 42);
			this->button20->TabIndex = 4;
			this->button20->Text = L"Add Instructor";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(20, 158);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(257, 42);
			this->button21->TabIndex = 3;
			this->button21->Text = L"Add Student";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(20, 110);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(257, 42);
			this->button22->TabIndex = 2;
			this->button22->Text = L"Add Courses";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(20, 62);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(257, 42);
			this->button23->TabIndex = 1;
			this->button23->Text = L"List Courses";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(795, 45);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(62, 31);
			this->button31->TabIndex = 10;
			this->button31->Text = L"About";
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->label49->Location = System::Drawing::Point(714, 77);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(143, 100);
			this->label49->TabIndex = 11;
			this->label49->Text = L"Created By:\r\nRyan D\'Elena\r\nAiden Pelletier\r\nMatt Lombardo\r\n";
			this->label49->Visible = false;
			// 
			// button32
			// 
			this->button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->button32->Location = System::Drawing::Point(25, 183);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(418, 42);
			this->button32->TabIndex = 12;
			this->button32->Text = L"Reset Password";
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->label53);
			this->panel12->Controls->Add(this->label52);
			this->panel12->Controls->Add(this->button33);
			this->panel12->Controls->Add(this->textBox27);
			this->panel12->Controls->Add(this->textBox26);
			this->panel12->Controls->Add(this->label51);
			this->panel12->Controls->Add(this->label50);
			this->panel12->Location = System::Drawing::Point(484, 77);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(373, 220);
			this->panel12->TabIndex = 13;
			this->panel12->Visible = false;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(6, 13);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(109, 16);
			this->label53->TabIndex = 6;
			this->label53->Text = L"Reset Password:";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(9, 119);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(51, 16);
			this->label52->TabIndex = 5;
			this->label52->Text = L"label52";
			this->label52->Visible = false;
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(9, 89);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(173, 23);
			this->button33->TabIndex = 4;
			this->button33->Text = L"Reset";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(82, 35);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(100, 22);
			this->textBox27->TabIndex = 3;
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(82, 63);
			this->textBox26->Name = L"textBox26";
			this->textBox26->PasswordChar = '*';
			this->textBox26->Size = System::Drawing::Size(100, 22);
			this->textBox26->TabIndex = 2;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(6, 69);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(70, 16);
			this->label51->TabIndex = 1;
			this->label51->Text = L"Password:";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(6, 41);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(44, 16);
			this->label50->TabIndex = 0;
			this->label50->Text = L"Email:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(905, 464);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->label49);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"LeopardWeb";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	string in_email;
	string in_password;
	string temp;
	MarshalString(textBox1->Text, in_email);
	MarshalString(textBox2->Text, in_password);
	user_login(db, stmt, sql, rc, logged_in, in_email, in_password, login);

	if (login.role == "Student") {
		// SET SQL FUNCTION
		sql = "SELECT ID, First_Name, Last_Name, Expected_Graduation_Year, Major, Email FROM Student WHERE Email = ?";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
		// BIND TEXT
		rc = sqlite3_bind_text(stmt, 1, login.email.c_str(), login.email.length(), SQLITE_TRANSIENT);
		// RUN SQL FUNCTION
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			student.ID = sqlite3_column_int(stmt, 0);
			student.first_name = (char*)sqlite3_column_text(stmt, 1);
			student.last_name = (char*)sqlite3_column_text(stmt, 2);
			student.expected_graduation_year = (char*)sqlite3_column_text(stmt, 3);
			student.major = (char*)sqlite3_column_text(stmt, 4);
			student.email = (char*)sqlite3_column_text(stmt, 5);
		}
		label3->Visible = false;
		textBox1->Text = "";
		textBox2->Text = "";
		label4->Text = "Welcome " + gcnew System::String(student.first_name.c_str()) + " " + gcnew System::String(student.last_name.c_str());
		panel1->Visible = true;
	}
	else if (login.role == "Instructor") {
		// SET SQL FUNCTION
		sql = "SELECT ID, First_Name, Last_Name, School_or_Department, Email FROM Instructor WHERE Email = ?";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
		// BIND TEXT
		rc = sqlite3_bind_text(stmt, 1, login.email.c_str(), login.email.length(), SQLITE_TRANSIENT);
		// RUN SQL FUNCTION
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			instructor.ID = sqlite3_column_int(stmt, 0);
			instructor.first_name = (char*)sqlite3_column_text(stmt, 1);
			instructor.last_name = (char*)sqlite3_column_text(stmt, 2);
			instructor.school_or_department = (char*)sqlite3_column_text(stmt, 3);
			instructor.email = (char*)sqlite3_column_text(stmt, 4);
		}
		label3->Visible = false;
		textBox1->Text = "";
		textBox2->Text = "";
		label9->Text = "Welcome " + gcnew System::String(instructor.first_name.c_str()) + " " + gcnew System::String(instructor.last_name.c_str());
		panel3->Visible = true;
	}
	else if (login.role == "Admin") {
		// SET SQL FUNCTION
		sql = "SELECT ID, First_Name, Last_Name, Email FROM Admin WHERE Email = ?";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
		// BIND TEXT
		rc = sqlite3_bind_text(stmt, 1, login.email.c_str(), login.email.length(), SQLITE_TRANSIENT);
		// RUN SQL FUNCTION
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			admin.ID = sqlite3_column_int(stmt, 0);
			admin.first_name = (char*)sqlite3_column_text(stmt, 1);
			admin.last_name = (char*)sqlite3_column_text(stmt, 2);
			admin.email = (char*)sqlite3_column_text(stmt, 3);
		}
		label3->Visible = false;
		textBox1->Text = "";
		textBox2->Text = "";
		label10->Text = "Welcome " + gcnew System::String(admin.first_name.c_str()) + " " + gcnew System::String(admin.last_name.c_str());
		panel5->Visible = true;
	}
	else {
		label3->Visible = true;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "";
	textBox3->Visible = false;
	button8->Visible = false;
	button9->Visible = false;
	label6->Visible = false;
	list_courses(db, stmt, sql, rc, course, instructor, stmt_nest, sql_nest, rc_nest, label5);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "Enter the CRN of the course you would like to add.";
	textBox3->Text = "";
	textBox3->Visible = true;
	button8->Visible = true;
	button9->Visible = false;
	label6->Visible = false;
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	string misc_input;
	MarshalString(textBox3->Text, misc_input);
	add_courses(db, stmt, sql, rc, course, student, login, misc_input, stmt_nest, sql_nest, rc_nest, label6);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "Enter the CRN of the course you would like to drop.";
	textBox3->Text = "";
	textBox3->Visible = true;
	button8->Visible = false;
	button9->Visible = true;
	label6->Visible = false;
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	string misc_input;
	MarshalString(textBox3->Text, misc_input);
	drop_courses(db, stmt, sql, rc, course, student, login, misc_input, stmt_nest, sql_nest, rc_nest, label6);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "";
	textBox3->Visible = false;
	button8->Visible = false;
	button9->Visible = false;
	label6->Visible = false;
	check_conflicts(db, stmt, sql, rc, course, course2, student, misc_input, time_start, time_start2, time_end, time_end2, same_day, time_conflict, stmt_nest, sql_nest, rc_nest, stmt_nest2, sql_nest2, rc_nest2, stmt_nest3, sql_nest3, rc_nest3, label5);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "";
	textBox3->Visible = false;
	button8->Visible = false;
	button9->Visible = false;
	label6->Visible = false;
	show_schedule(db, stmt, sql, rc, course, student, instructor, misc_input, stmt_nest, sql_nest, rc_nest, stmt_nest2, sql_nest2, rc_nest2, label5);
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "";
	textBox3->Visible = false;
	button8->Visible = false;
	button9->Visible = false;
	label6->Visible = false;
	panel1->Visible = false;
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	label8->Text = "";
	textBox4->Visible = false;
	button10->Visible = false;
	button11->Visible = false;
	label7->Visible = false;
	list_courses(db, stmt, sql, rc, course, instructor, stmt_nest, sql_nest, rc_nest, label8);
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	label8->Text = "";
	textBox4->Visible = false;
	button10->Visible = false;
	button11->Visible = false;
	label7->Visible = false;
	show_teaching_schedule(db, stmt, sql, rc, course, login, instructor, misc_input, stmt_nest, sql_nest, rc_nest, stmt_nest2, sql_nest2, rc_nest2, label8);
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	label8->Text = "Enter Student ID";
	textBox4->Text = "";
	textBox4->Visible = true;
	button10->Visible = true;
	button11->Visible = false;
	label7->Visible = false;
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	string misc_input;
	MarshalString(textBox4->Text, misc_input);
	show_student_schedule(db, stmt, sql, rc, course, student, instructor, misc_input, stmt_nest, sql_nest, rc_nest, stmt_nest2, sql_nest2, rc_nest2, label7);
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	label8->Text = "Enter a course CRN";
	textBox4->Text = "";
	textBox4->Visible = true;
	button10->Visible = false;
	button11->Visible = true;
	label7->Visible = false;
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	string misc_input;
	MarshalString(textBox4->Text, misc_input);
	show_class_roster(db, stmt, sql, rc, course, roster, misc_input, stmt_nest, sql_nest, rc_nest, label7);
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	label8->Text = "";
	textBox4->Visible = false;
	button10->Visible = false;
	button11->Visible = false;
	label7->Visible = false;
	panel3->Visible = false;
}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	label12->Text = "";
	textBox5->Visible = false;
	button12->Visible = false;
	button18->Visible = false;
	label11->Visible = false;
	panel7->Visible = false;
	panel8->Visible = false;
	panel9->Visible = false;
	panel10->Visible = false;
	panel11->Visible = false;
	list_courses(db, stmt, sql, rc, course, instructor, stmt_nest, sql_nest, rc_nest, label12);
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	panel7->Visible = true;
	panel8->Visible = false;
	panel9->Visible = false;
	panel10->Visible = false;
	panel11->Visible = false;
	textBox6->Text = "";
	textBox7->Text = "";
	textBox8->Text = "";
	textBox9->Text = "";
	textBox10->Text = "";
	comboBox1->SelectedIndex = -1;
	comboBox2->SelectedIndex = -1;
	comboBox3->SelectedIndex = -1;
	checkBox1->Checked = false;
	checkBox2->Checked = false;
	checkBox3->Checked = false;
	checkBox4->Checked = false;
	checkBox5->Checked = false;
	label22->Visible = false;
	label23->Visible = false;
	label23->Text = "";
}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	if (
		textBox6->Text != "" &&
		textBox7->Text != "" &&
		textBox8->Text != "" &&
		textBox9->Text != "" &&
		textBox10->Text != "" &&
		comboBox1->SelectedIndex != -1 &&
		comboBox2->SelectedIndex != -1 &&
		comboBox3->SelectedIndex != -1) 
	{
		int in_CRN;
		string text6;
		MarshalString(textBox6->Text, text6);
		string in_type;
		MarshalString(textBox7->Text, in_type);
		string in_title;
		MarshalString(textBox8->Text, in_title);
		string in_subject;
		MarshalString(textBox9->Text, in_subject);
		int in_credits;
		in_credits = comboBox1->SelectedIndex + 1;
		string in_days = "00000";
		if (checkBox1->Checked == true) { in_days[0] = '1'; }
		if (checkBox2->Checked == true) { in_days[1] = '1'; }
		if (checkBox3->Checked == true) { in_days[2] = '1'; }
		if (checkBox4->Checked == true) { in_days[3] = '1'; }
		if (checkBox5->Checked == true) { in_days[4] = '1'; }
		int in_start_time_hour;
		if (comboBox2->SelectedIndex >= 0 && comboBox2->SelectedIndex <= 3) { in_start_time_hour = 8; }
		else if (comboBox2->SelectedIndex >= 4 && comboBox2->SelectedIndex <= 7) { in_start_time_hour = 9; }
		else if (comboBox2->SelectedIndex >= 8 && comboBox2->SelectedIndex <= 11) { in_start_time_hour = 10; }
		else if (comboBox2->SelectedIndex >= 12 && comboBox2->SelectedIndex <= 15) { in_start_time_hour = 11; }
		else if (comboBox2->SelectedIndex >= 16 && comboBox2->SelectedIndex <= 19) { in_start_time_hour = 12; }
		else if (comboBox2->SelectedIndex >= 20 && comboBox2->SelectedIndex <= 23) { in_start_time_hour = 13; }
		else if (comboBox2->SelectedIndex >= 24 && comboBox2->SelectedIndex <= 27) { in_start_time_hour = 14; }
		else if (comboBox2->SelectedIndex >= 28 && comboBox2->SelectedIndex <= 31) { in_start_time_hour = 15; }
		else if (comboBox2->SelectedIndex >= 32 && comboBox2->SelectedIndex <= 35) { in_start_time_hour = 16; }
		else if (comboBox2->SelectedIndex >= 36 && comboBox2->SelectedIndex <= 39) { in_start_time_hour = 17; }
		else if (comboBox2->SelectedIndex >= 40 && comboBox2->SelectedIndex <= 43) { in_start_time_hour = 18; }
		else if (comboBox2->SelectedIndex == 44) { in_start_time_hour = 19; }
		int in_start_time_min;
		if (comboBox2->SelectedIndex % 4 == 0) { in_start_time_min == 0; }
		if (comboBox2->SelectedIndex % 4 == 1) { in_start_time_min == 15; }
		if (comboBox2->SelectedIndex % 4 == 2) { in_start_time_min == 30; }
		if (comboBox2->SelectedIndex % 4 == 3) { in_start_time_min == 45; }
		int in_end_time_hour;
		if (comboBox3->SelectedIndex >= 0 && comboBox3->SelectedIndex <= 3) { in_end_time_hour = 8; }
		else if (comboBox3->SelectedIndex >= 4 && comboBox3->SelectedIndex <= 7) { in_end_time_hour = 9; }
		else if (comboBox3->SelectedIndex >= 8 && comboBox3->SelectedIndex <= 11) { in_end_time_hour = 10; }
		else if (comboBox3->SelectedIndex >= 12 && comboBox3->SelectedIndex <= 15) { in_end_time_hour = 11; }
		else if (comboBox3->SelectedIndex >= 16 && comboBox3->SelectedIndex <= 19) { in_end_time_hour = 12; }
		else if (comboBox3->SelectedIndex >= 20 && comboBox3->SelectedIndex <= 23) { in_end_time_hour = 13; }
		else if (comboBox3->SelectedIndex >= 24 && comboBox3->SelectedIndex <= 27) { in_end_time_hour = 14; }
		else if (comboBox3->SelectedIndex >= 28 && comboBox3->SelectedIndex <= 31) { in_end_time_hour = 15; }
		else if (comboBox3->SelectedIndex >= 32 && comboBox3->SelectedIndex <= 35) { in_end_time_hour = 16; }
		else if (comboBox3->SelectedIndex >= 36 && comboBox3->SelectedIndex <= 39) { in_end_time_hour = 17; }
		else if (comboBox3->SelectedIndex >= 40 && comboBox3->SelectedIndex <= 43) { in_end_time_hour = 18; }
		else if (comboBox3->SelectedIndex == 44) { in_end_time_hour = 19; }
		int in_end_time_min;
		if (comboBox3->SelectedIndex % 4 == 0) { in_end_time_min == 0; }
		if (comboBox3->SelectedIndex % 4 == 1) { in_end_time_min == 15; }
		if (comboBox3->SelectedIndex % 4 == 2) { in_end_time_min == 30; }
		if (comboBox3->SelectedIndex % 4 == 3) { in_end_time_min == 45; }
		int in_professor_ID;
		string text10;
		MarshalString(textBox10->Text, text10);
		

		try {
			std::stoi(text10);
			try {
				std::stoi(text6);
				in_professor_ID = std::stoi(text10);
				in_CRN = std::stoi(text6);
				if (comboBox2->SelectedIndex < comboBox3->SelectedIndex) {
					Course inCourse;
					inCourse.CRN = in_CRN;
					inCourse.type = in_type;
					inCourse.title = in_title;
					inCourse.subject = in_subject;
					inCourse.credit_hours = in_credits;
					inCourse.days_of_the_week = in_days;
					inCourse.start_time_hour = in_start_time_hour;
					inCourse.start_time_min = in_start_time_min;
					inCourse.end_time_hour = in_end_time_hour;
					inCourse.end_time_min = in_end_time_min;
					inCourse.professor_ID = in_professor_ID;
					admin_add_course(db, stmt, sql, rc, misc_input, inCourse, sql_nest, rc_nest, stmt_nest, label23);
				}
				else {
					label23->Visible = true;
					label23->Text = "Start time must be before end time.";
				}
			}
			catch (const std::invalid_argument& e) {
				label23->Visible = true;
				label23->Text = "Invalid inputs";
			}
		}
		catch (const std::invalid_argument& e) {
			label23->Visible = true;
			label23->Text = "Invalid inputs";
		}
	}
	else {
		label22->Text = "Insufficient Information Provided!";
		label22->Visible = true;
	}
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	panel7->Visible = false;
	panel8->Visible = true;
	panel9->Visible = false;
	panel10->Visible = false;
	panel11->Visible = false;
	textBox11->Text = "";
	textBox12->Text = "";
	textBox13->Text = "";
	textBox14->Text = "";
	textBox15->Text = "";
	textBox16->Text = "";
	textBox17->Text = "";
	label24->Text = "";
	label24->Visible = false;
}
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	if (
		textBox11->Text != "" &&
		textBox12->Text != "" &&
		textBox13->Text != "" &&
		textBox14->Text != "" &&
		textBox15->Text != "" &&
		textBox16->Text != "" &&
		textBox17->Text != "")
	{
		Student inStudent;
		Login inLogin;
		int in_ID;
		string text15;
		MarshalString(textBox15->Text, text15);
		string in_first_name;
		MarshalString(textBox14->Text, in_first_name);
		string in_last_name;
		MarshalString(textBox13->Text, in_last_name);
		int in_graduation_year;
		string text12;
		MarshalString(textBox12->Text, text12);
		string in_major;
		MarshalString(textBox11->Text, in_major);
		string in_email;
		MarshalString(textBox16->Text, in_email);
		string in_password;
		MarshalString(textBox17->Text, in_password);

		try {
			std::stoi(text15);
			try {
				std::stoi(text12);
				in_ID = std::stoi(text15);
				in_graduation_year = std::stoi(text12);
				inStudent.ID = in_ID;
				inStudent.first_name = in_first_name;
				inStudent.last_name = in_last_name;
				inStudent.expected_graduation_year = in_graduation_year;
				inStudent.major = in_major;
				inStudent.email = in_email;
				inLogin.password = in_password;
				admin_add_student(inStudent, inLogin, misc_input, sql_nest, rc_nest, db, stmt, sql, rc, stmt_nest, label24);
			}
			catch (const std::invalid_argument& e) {
				label24->Text = "Invalid Inputs";
				label24->Visible = true;
			}
		}
		catch (const std::invalid_argument& e) {
			label24->Text = "Invalid Inputs";
			label24->Visible = true;
		}
	}
	else {
		label24->Text = "Insufficient Information Provided!";
		label24->Visible = true;
	}
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	panel7->Visible = false;
	panel8->Visible = false;
	panel9->Visible = true;
	panel10->Visible = false;
	panel11->Visible = false;
	textBox18->Text = "";
	textBox20->Text = "";
	textBox21->Text = "";
	textBox22->Text = "";
	textBox23->Text = "";
	textBox24->Text = "";
	label28->Text = "";
	label28->Visible = false;
}
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	if (
		textBox18->Text != "" &&
		textBox20->Text != "" &&
		textBox21->Text != "" &&
		textBox22->Text != "" &&
		textBox23->Text != "" &&
		textBox24->Text != "")
	{
		Instructor inInstructor;
		Login inLogin;
		int in_ID;
		string text24;
		MarshalString(textBox24->Text, text24);
		string in_first_name;
		MarshalString(textBox23->Text, in_first_name);
		string in_last_name;
		MarshalString(textBox22->Text, in_last_name);
		string in_department;
		MarshalString(textBox21->Text, in_department);
		string in_email;
		MarshalString(textBox20->Text, in_email);
		string in_password;
		MarshalString(textBox18->Text, in_password);

		try {
			std::stoi(text24);
			in_ID = std::stoi(text24);
			inInstructor.ID = in_ID;
			inInstructor.first_name = in_first_name;
			inInstructor.last_name = in_last_name;
			inInstructor.school_or_department = in_department;
			inInstructor.email = in_email;
			inLogin.password = in_password;
			admin_add_instructor(inInstructor, inLogin, misc_input, sql_nest, rc_nest, db, stmt, sql, rc, stmt_nest, label28);
		}
		catch (const std::invalid_argument& e) {
			label28->Text = "Invalid Inputs";
			label28->Visible = true;
		}
	}
	else {
		label28->Text = "Insufficient Information Provided!";
		label28->Visible = true;
	}
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	panel7->Visible = false;
	panel8->Visible = false;
	panel9->Visible = false;
	panel10->Visible = true;
	panel11->Visible = false;
	textBox29->Text = "";
	textBox28->Text = "";
	label42->Text = "";
	label42->Visible = false;
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	if (
		textBox29->Text != "" &&
		textBox28->Text != "")
	{
		Login inLogin;
		Student inStudent;
		Instructor inInstructor;
		Course inCourse;
		int in_ID;
		string text29;
		MarshalString(textBox29->Text, text29);
		int in_CRN;
		string text28;
		MarshalString(textBox28->Text, text28);
		try {
			std::stoi(text29);
			try {
				std::stoi(text28);
				in_ID = std::stoi(text29);
				in_CRN = std::stoi(text28);
				admin_assign_user_class(inLogin, text29, text28, db, stmt, sql, rc, inStudent, inInstructor, inCourse, sql_nest, rc_nest, stmt_nest, label42);
			}
			catch (const std::invalid_argument& e) {
				label42->Text = "Invalid Inputs";
				label42->Visible = true;
			}
		}
		catch (const std::invalid_argument& e) {
			label42->Text = "Invalid Inputs";
			label42->Visible = true;
		}
	}
	else {
		label42->Text = "Insufficient Information Provided!";
		label42->Visible = true;
	}
}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	panel7->Visible = false;
	panel8->Visible = false;
	panel9->Visible = false;
	panel10->Visible = false;
	panel11->Visible = true;
	textBox25->Text = "";
	textBox19->Text = "";
	label36->Text = "";
	label36->Visible = false;
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	if (
		textBox25->Text != "" &&
		textBox19->Text != "")
	{
		Student inStudent;
		Instructor inInstructor;
		Login inLogin;
		Course inCourse;
		int in_ID;
		string text25;
		MarshalString(textBox25->Text, text25);
		int in_CRN;
		string text19;
		MarshalString(textBox19->Text, text19);
		try {
			std::stoi(text25);
			try {
				std::stoi(text19);
				in_ID = std::stoi(text25);
				in_CRN = std::stoi(text19);
				admin_unassign_user_class(inLogin, text25, text19, db, stmt, sql, rc, inStudent, inInstructor, inCourse, sql_nest, rc_nest, stmt_nest, label36);
			}
			catch (const std::invalid_argument& e) {
				label36->Text = "Invalid Inputs";
				label36->Visible = true;
			}
		}
		catch (const std::invalid_argument& e) {
			label36->Text = "Invalid Inputs";
			label36->Visible = true;
		}
	}
	else {
		label36->Text = "Insufficient Information Provided!";
		label36->Visible = true;
	}
}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	panel7->Visible = false;
	panel8->Visible = false;
	panel9->Visible = false;
	panel10->Visible = false;
	panel11->Visible = false;
	label12->Text = "";
	panel5->Visible = false;
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	panel12->Visible = false;
	if (label49->Visible == false) {
		label49->Visible = true;
	}
	else {
		label49->Visible = false;
	}
}
private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox27->Text != "" &&
		textBox26->Text != "") {
		string in_email;
		MarshalString(textBox27->Text, in_email);
		string in_password;
		MarshalString(textBox26->Text, in_password);
		update_password(in_email, in_password, db, stmt, sql, rc, sql_nest, rc_nest, stmt_nest, label52);
	}
	else {
		label52->Visible = true;
		label52->Text = "Insufficient Information Provided!";
	}
}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	if (panel12->Visible == false) {
		label52->Visible = false;
		panel12->Visible = true;
		textBox26->Text = "";
		textBox27->Text = "";
	}
	else {
		panel12->Visible = false;
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
};
}
