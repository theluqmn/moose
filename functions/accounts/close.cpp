#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

using namespace std;

int closeAccount(string accountType, int accountID, string accountPassword) {
    cerr << "Starting closeAccount with type=" << accountType << ", id=" << accountID << endl;
    
    if (accountType != "checking" && accountType != "savings") {
        cerr << "Invalid account type" << endl;
        return -1;
    }
    
    sqlite3* db = initAccountsDB();
    if (!db) {
        cerr << "Database connection failed" << endl;
        return -1;
    }

    // Enable SQLite debug output
    sqlite3_trace(db, [](void*, const char* sql) -> void {
        cerr << "SQLITE TRACE: " << sql << endl;
        return;
    }, nullptr);

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
