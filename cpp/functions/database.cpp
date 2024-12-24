#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

sqlite3* initAccountsDB() {
    // Open the database
    sqlite3 *db;
    int res = sqlite3_open("database/accounts.db", &db);
    char *zErrMsg = 0;
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", 0, 0, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = WAL;", 0, 0, &zErrMsg);
    if (res != SQLITE_OK) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    // Create the checking accounts table
    string checking_accounts_table = "CREATE TABLE IF NOT EXISTS checking (account_id INTEGER PRIMARY KEY, name TEXT, password TEXT, balance FLOAT);";
    res = sqlite3_exec(db, checking_accounts_table.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    // Create the savings accounts table
    string savings_accounts_table = "CREATE TABLE IF NOT EXISTS savings (account_id INTEGER PRIMARY KEY, name TEXT, password TEXT, balance FLOAT);";
    res = sqlite3_exec(db, savings_accounts_table.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    return db;
}

sqlite3* initTransactionsDB() {
    // Open the database
    sqlite3 *db;
    int res = sqlite3_open("database/transactions.db", &db);
    if (res != SQLITE_OK) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    // Create the transactions table
    string transactions_sql = "CREATE TABLE IF NOT EXISTS transactions (sender_id INTEGER, receiver_id INTEGER, amount FLOAT, description TEXT, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
    res = sqlite3_exec(db, transactions_sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        cerr << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    return db;
}