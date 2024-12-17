#include <iostream>
#include <string>
#include "../functions/accounts/accounts.h"

using namespace std;

void promptOpenAccount() {
    string accountName;
    string accountPassword;
    string accountType;
    int accountID;

    cout << "[ Create Account ]" << endl;
    cout << "Available account types:" << endl;
    cout << "- checking      - For everyday use" << endl;
    cout << "- savings       - For saving money" << endl;
    cout << endl;

    // Account type
    cout << "(1/4) Account type: ";
    getline(cin, accountType);

    // Account owner name
    cout << "(2/4) Owner's name: ";
    getline(cin, accountName);

    // Password
    cout << "(3/4) Password: ";
    getline(cin, accountPassword);

    // Verify account info
    cout << "(4/4) Verify account information:" << endl;
    cout << "- Account type: " << accountType << endl;
    cout << "- Account owner's name: " << accountName << endl;
    cout << "- Password: " << accountPassword << endl;
    cout << endl;

    string confirmation;
    cout << "Is this information correct? (y/n): ";
    getline(cin, confirmation);

    // Execute account creation
    if (confirmation == "y") {
        accountID = openAccount(accountType, accountName, accountPassword);
        cout << "Account created successfully!" << endl;
        cout << "ID: " << accountID << endl;
    } else {
        cout << "Aborted process" << endl;
    }
}

void promptCloseAccount() {
    string accountPassword;
    int accountID;

    cout << "[ Close Account ]" << endl;
    cout << "(1/3) Enter the account ID: ";
    string accountIDInput;
    getline(cin, accountIDInput);
    accountID = stoi(accountIDInput);

    cout << "(2/3) Enter the account password: ";
    getline(cin, accountPassword);

    // Verify account info
    cout << "(3/3) Verify account information:" << endl;
    cout << "- Account ID: " << accountID << endl;
    cout << "- Password: " << accountPassword << endl;
    cout << "WARNING: This action is irreversible" << endl;
    cout << endl;

    string confirmation;
    cout << "Proceed with closing? (y/n): ";
    getline(cin, confirmation);

    // Execute account deletion
    if (confirmation == "y") {
        int result = closeAccount(accountID, accountPassword);
        if (result == 1) {
            cout << "Account closed successfully!" << endl;
        } else {
            cout << "Account not found" << endl;
        }
    } else {
        cout << "Aborted process" << endl;
    }
}