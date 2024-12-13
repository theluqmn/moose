#include <iostream>
#include <string>
#include "../functions/accounts/accounts.h"

using namespace std;

void promptCreateAccount() {
    string accountName;
    string accountPassword;
    int accountID;

    cout << "[ Create account ]" << endl;

    // Account owner's name
    cout << "(1/3) Account owner's name: ";
    getline(cin, accountName);

    // Password
    cout << "(2/3) Password: ";
    getline(cin, accountPassword);

    // Verify account information
    cout << "(3/3) Verify account information:" << endl;
    cout << "- Account owner's name: " << accountName << endl;
    cout << "- Password: " << accountPassword << endl;
    cout << endl;

    cout << "Is this information correct? (y/n): ";
    string confirmation;
    getline(cin, confirmation);

    // Execute account creation
    if (confirmation == "y") {
        accountID = createAccount(accountName, accountPassword);

        cout << "Account created successfully!" << endl;
        cout << "ID: " << accountID << endl;
    } else {
        cout << "Account creation process aborted" << endl;
    }
}