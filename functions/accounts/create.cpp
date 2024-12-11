#include <iostream>
#include <string>

void createAccount() {
    std::string accountName;
    std::string accountPassword;
    int accountID;

    // Account owner's name
    std::cout << "(1/4) Account owner's name: ";
    std::getline(std::cin, accountName);

    // Password
    std::cout << "(2/4) Password: ";
    std::getline(std::cin, accountPassword);

    // Account ID
    srand(time(0));
    std::cout << "(3/4) Account ID: ";
    accountID = rand() % 900000000000 + 100000000000;  // Generates a random 12-digit number
    std::cout << accountID << std::endl;

    // Verify account information
    std::cout << "(4/4) Verify account information:" << std::endl;
    std::cout << "- Account owner's name: " << accountName << std::endl;
    std::cout << "- Password: " << accountPassword << std::endl;
    std::cout << "- Account ID: " << accountID << std::endl;

    std::cout << "Is this information correct? (y/n): ";
    std::string confirmation;
    std::getline(std::cin, confirmation);
    std::cout << std::endl;

    if (confirmation == "y") {
        std::cout << "Account created successfully!" << std::endl;
    } else {
        std::cout << "Account creation process aborted" << std::endl;
    }
}