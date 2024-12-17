#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"
#include "accounts.h"

using namespace std;

int closeAccount(int accountID, string accountPassword) {
    int exists = accountExists(accountID);

    if (exists == 1) {} // To be implemented

    sqlite3* db = initAccountsDB();
    char* errMsg = 0;
    
    string sql = "DELETE FROM current WHERE account_id = " + to_string(accountID) + ";";
    
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    cout << "Account " << accountID << " has been successfully closed." << endl;
    sqlite3_close(db);
    return 1;
}
