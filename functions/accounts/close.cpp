#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"
#include "accounts.h"

using namespace std;

int closeAccount(string accountType, int accountID, string accountPassword) {
    // Check if account type is valid
    if (accountType != "checking" && accountType != "savings") {
        cerr << "Invalid account type" << endl;
        return -1;
    }
    
    // Check if account exists
    int exists = accountExists(accountType, accountID);

    if (exists == 1) {
        sqlite3* db = initAccountsDB();
        char* errMsg = 0;
        
        string sql = "DELETE FROM " + accountType +" WHERE account_id = " + to_string(accountID) + ";";
        
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
    } else {
        return 0;
    }
}
