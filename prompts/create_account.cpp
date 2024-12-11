#include <iostream>
#include <string>
#include "../functions/accounts/accounts.h"

void promptCreateAccount() {
    std::string accountName;
    std::string accountPassword;
    int accountID;

    // Account owner's name
    std::cout << "(1/3) Account owner's name: ";
    std::getline(std::cin, accountName);

    // Password
    std::cout << "(2/3) Password: ";
    std::getline(std::cin, accountPassword);

    // Verify account information
    std::cout << "(3/3) Verify account information:" << std::endl;
    std::cout << "- Account owner's name: " << accountName << std::endl;
    std::cout << "- Password: " << accountPassword << std::endl;
    std::cout << std::endl;

    std::cout << "Is this information correct? (y/n): ";
    std::string confirmation;
    std::getline(std::cin, confirmation);
    std::cout << std::endl;

    if (confirmation == "y") {
        createAccount(accountName, accountPassword);
        std::cout << "Account created successfully!" << std::endl;
    } else {
        std::cout << "Account creation process aborted" << std::endl;
    }
}