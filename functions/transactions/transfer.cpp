#include <iostream>

#include "../functions.h"

int transfer(int fromAccountID, int toAccountID, float amount) {
    // Open the database
    sqlite3 *db = initAccountsDB();
    if (db == nullptr) {
        return 1;
    }
}