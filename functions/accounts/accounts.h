#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

int closeAccount(int accountID, std::string accountPassword);
int openAccount(std::string accountType, std::string accountName, std::string accountPassword);

bool accountExists(int accountID, std::string accountType);
std::string accountPassword(std::string accountType, int accountID);

#endif