#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <sqlite3.h>

void clearScreen();
sqlite3* initAccountsDB();
sqlite3* initTransactionsDB();

#endif