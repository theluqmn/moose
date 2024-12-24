#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

int getAccount(std::string accountType, int accountID) {
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        std::cerr << "Failed to open database" << std::endl;
        return -1;
    }
}