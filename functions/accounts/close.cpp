#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

using namespace std;

int closeAccount(string accountType, int accountID, string accountPassword) {
    cout << "DEBUG: Attempting to close account type: " << accountType << endl;
    
    if (accountType != "checking" && accountType != "savings") {
        cerr << "Invalid account type" << endl;
        return -1;
    }
    
    // int exists = accountExists(accountType, accountID);
    int exists = 1;
    cout << "DEBUG: Account exists check returned: " << exists << endl;

    if (exists == 1) {
        sqlite3* db = initAccountsDB();
        char* errMsg = 0;
        
        string sql = "DELETE FROM " + accountType +" WHERE account_id = " + to_string(accountID) + ";";
        cout << "DEBUG: Executing SQL: " << sql << endl;
        
        int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
        cout << "DEBUG: SQLite return code: " << rc << endl;
        
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
    return 0;
}
