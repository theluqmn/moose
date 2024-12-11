#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

int createAccount(std::string accountName, std::string accountPassword) {
    // Open the database
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        return 1;
    }

    // Generate a random account ID
    int accountID = rand() % 90000000 + 10000000;
    // Check if account ID already exists
    bool idExists = true;
    while (idExists) {
        std::string checkSql = "SELECT COUNT(*) FROM accounts WHERE account_id = " + std::to_string(accountID) + ";";
        sqlite3_stmt *stmt;
        int rc = sqlite3_prepare_v2(db, checkSql.c_str(), -1, &stmt, nullptr);
        
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return 1;
        }

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            int count = sqlite3_column_int(stmt, 0);
            if (count == 0) {
                idExists = false;
            } else {
                accountID = rand() % 90000000 + 10000000;
            }
        }
        
        sqlite3_finalize(stmt);
    }

    // Insert the account into the database
    std::string sql = "INSERT INTO accounts (account_name, account_password, account_id, balance) VALUES ('" + accountName + "', '" + accountPassword + "', " + std::to_string(accountID) + ", 0);";
    int res = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        std::cerr << "Error creating account: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}