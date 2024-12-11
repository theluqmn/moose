#include <iostream>
#include <sqlite3.h>
#include <string>

int createAccount(std::string accountName, std::string accountPassword) {
    int accountID = rand() % 90000000 + 10000000;
    
    // Open the database
    sqlite3 *db = initialiseDatabase();
    if (db == nullptr) {
        return 1;
    }

    // Insert the account into the database
    std::string sql = "INSERT INTO accounts (account_name, account_password, account_id) VALUES ('" + accountName + "', '" + accountPassword + "', " + std::to_string(accountID) + ");";
    int res = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        std::cerr << "Error creating account: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}
sqlite3* initialiseDatabase() {
    // Open the database
    sqlite3 *db;
    int res = sqlite3_open("accounts.db", &db);
    if (res != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return nullptr;
    }

    // Create the accounts table
    std::string accounts_sql = "CREATE TABLE IF NOT EXISTS accounts (account_id INTEGER PRIMARY KEY, account_name TEXT, account_password TEXT);";
    res = sqlite3_exec(db, accounts_sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return nullptr;
    }

    return db;
}