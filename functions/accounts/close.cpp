#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"
#include "accounts.h"

using namespace std;

int closeAccount(int accountID, string accountPassword) {
    int exists = accountExists(accountID);

    if (exists == 1) {
        // Open the database
        sqlite3 *db = initAccountsDB();
        if (db == nullptr) {
            return -1;
        }

        // Close the account
        string sql = "DELETE FROM current WHERE account_id = " + to_string(accountID) + ";";
        int res = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
        if (res != SQLITE_OK) {
            cerr << "Error closing account: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            return -1;
        }

        sqlite3_close(db);
        return 1;
    }
    
    return 0;
}