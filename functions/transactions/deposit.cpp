#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../functions.h"

using namespace std;

int fundsDeposit(string accountType, int accountID, float amount) {
    // Opens the database
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        return -1;
    }

    // 
}