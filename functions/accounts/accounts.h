#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

int closeAccount(std::string accountType, int accountID, std::string accountPassword);
int openAccount(std::string accountType, std::string accountName, std::string accountPassword);

int accountExists(std::string accountType, int accountID);

#endif