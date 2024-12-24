#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>

int fundsDeposit(std::string accountType, int accountID, float amount);
int fundsWithdraw(std::string accountType, int accountID, float amount);

#endif