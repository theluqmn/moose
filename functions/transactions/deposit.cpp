#include <iostream>
#include <sqlite3.h>
#include <string>
#include "../functions.h"

using namespace std;

int fundsDeposit(string accountType, int accountID, float amount) {
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

    // Add amount to account
    string sql = "UPDATE " + accountType + " SET balance = balance + " + to_string(amount) + " WHERE account_id = " + to_string(accountID) + ";";
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