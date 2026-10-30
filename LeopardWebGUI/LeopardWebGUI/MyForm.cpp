#include "MyForm.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)

{

    // OPEN DATABASE
    rc = sqlite3_open("leopardweb.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    }

    // Declaring sql and rc allows them to be used in functions
    sql = "";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sql_nest = "";
    rc_nest = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    sql_nest2 = "";
    rc_nest2 = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    stmt_nest2 = nullptr;
    sql_nest3 = "";
    rc_nest3 = sqlite3_prepare_v2(db, sql_nest, -1, &stmt_nest, 0);
    stmt_nest3 = nullptr;

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    LeopardWebGUI::MyForm form;

    Application::Run(% form);

}