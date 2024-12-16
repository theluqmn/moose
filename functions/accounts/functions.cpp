#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

using namespace std;

int accountExists(int accountID) {
    bool idExists = true;

    // Open the database
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        return -1;
    }

    while (idExists) {
        string checkSql = "SELECT COUNT(*) FROM current WHERE account_id = " + to_string(accountID) + ";";
        sqlite3_stmt *stmt;
        int rc = sqlite3_prepare_v2(db, checkSql.c_str(), -1, &stmt, nullptr);
        
        // Error checking
        if (rc != SQLITE_OK) {
            cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            return -1;
        }

        // Check if account ID already exists
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            int count = sqlite3_column_int(stmt, 0);
            if (count == 0) {
                idExists = false;
            } else {
                idExists = true;
            }
        }
        
        sqlite3_finalize(stmt);
    }

    return idExists;
}

string accountPassword(string accountType, int accountID) {
    // Open the database
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        cerr << "Failed to open database" << endl;
        return "";
    }

    // Check if account ID already exists
    if (accountExists(accountID)) {
        // Get account password
        if (accountType == "current") {
            string checkSql = "SELECT password FROM current WHERE account_id = " + to_string(accountID) + ";";
            sqlite3_stmt *stmt;
            int rc = sqlite3_prepare_v2(db, checkSql.c_str(), -1, &stmt, nullptr);

            if (rc != SQLITE_OK) {
                cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
                sqlite3_close(db);
                return "";
            }

            rc = sqlite3_step(stmt);
            if (rc == SQLITE_ROW) {
                string password = (const char*)sqlite3_column_text(stmt, 0);
                return password;
            }
            sqlite3_finalize(stmt);
        }
    }
}