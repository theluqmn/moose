#include <iostream>
#include <sqlite3.h>
#include <string>
#include "../functions.h"

using namespace std;

int fundsWithdraw(string accountType, int accountID, float amount) {
    float balance;

    // Check if account type is valid
    if (accountType != "checking" && accountType != "savings") {
        cerr << "Invalid account type" << endl;
        return -1;
    }

    // Opens the database
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        return -1;
    }

    // Check if account has sufficient balance
    string sql = "SELECT balance FROM " + accountType + " WHERE account_id = " + to_string(accountID) + ";";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    // Error checking
    if (rc != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return -1;
    }

    // Check if account has sufficient balance
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        balance = sqlite3_column_double(stmt, 0);
        if (balance < amount) {
            cerr << "Insufficient balance" << endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return -1;
        }
        sqlite3_finalize(stmt);
    }

    // Add amount to account
    string sql = "UPDATE " + accountType + " SET balance = balance - " + to_string(amount) + " WHERE account_id = " + to_string(accountID) + ";";
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    
    if (rc != SQLITE_OK) {
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return -1;
    }
    
    sqlite3_close(db);

    return 1;
}