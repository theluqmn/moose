#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

sqlite3* initAccountsDB() {
    // Open the database
    sqlite3 *db;
    int res = sqlite3_open("database/accounts.db", &db);
    if (res != SQLITE_OK) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr;
    }

    // Create the accounts table
    string accounts_sql = "CREATE TABLE IF NOT EXISTS accounts (account_id INTEGER PRIMARY KEY, account_name TEXT, account_password TEXT, balance FLOAT);";
    res = sqlite3_exec(db, accounts_sql.c_str(), NULL, NULL, NULL);
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