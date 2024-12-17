#include <iostream>
#include <string>
#include "../functions/accounts/accounts.h"
#include "../functions/transactions/transactions.h"

using namespace std;

void promptTransfer() {
    string senderID;
    string receiverID;
    string description;
    float amount;

    cout << "[ Transfer ]" << endl;

    // Receiver's ID
    cout << "(1/4) Receiver's ID: ";
    getline(cin, receiverID);

    // Amount to transfer
    cout << "(2/4) Amount to transfer: ";
    cin >> amount;
    cin.ignore();

    // Transfer description
    cout << "(3/4) Transfer description: ";
    getline(cin, description);

    // Verify transfer information
    cout << "(4/4) Verify transfer information:" << endl;
    cout << "- Receiver's ID: " << receiverID << endl;
    cout << "- Amount: " << amount << endl;
    cout << "- Description: " << endl;
    cout << description << endl;
    cout << endl;

    cout << "Is this information correct? (y/n): ";
    string confirmation;
    getline(cin, confirmation);

    // Execute transfer
    if (confirmation == "y") {
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Transfer aborted" << endl;
    }
}

void promptFundDeposit() {
    string accountType;
    int accountID;
    float amount;

    cout << "[ Deposit ]" << endl;

    cout << "(1/3) Account type: ";
    getline(cin, accountType);

    cout << "(2/3) Account ID: ";
    string accountIDInput;
    getline(cin, accountIDInput);
    accountID = stoi(accountIDInput);

    cout << "(3/3) Amount: ";
    string amountInput;
    getline(cin, amountInput);
    amount = stof(amountInput);

    cout << "(4/4) Verify deposit details:" << endl;
    cout << "- Account type: " << accountType << endl;
    cout << "- Account ID: " << accountID << endl;
    cout << "- Amount: " << amount << endl;
    cout << endl;

    cout << "Is this information correct? (y/n): ";
    string confirmation;
    getline(cin, confirmation);

    // Execute transfer
    if (confirmation == "y") {
        int result = fundsDeposit(accountType, accountID, amount);
        if (result == 1) {
            cout << "Deposit successful!" << endl;
        } else {
            cout << "An error occured" << endl;
        }
    } else {
        cout << "Deposit aborted" << endl;
    }
}

void promptFundsWithdraw() {
    string accountType;
    int accountID;
    float amount;

    cout << "[ Withdraw ]" << endl;

    cout << "(1/3) Account type: ";
    getline(cin, accountType);

    cout << "(2/3) Account ID: ";
    string accountIDInput;
    getline(cin, accountIDInput);
    accountID = stoi(accountIDInput);

    cout << "(3/3) Amount: ";
    string amountInput;
    getline(cin, amountInput);
    amount = stof(amountInput);

    cout << "(4/4) Verify withdrawal details:" << endl;
    cout << "- Account type: " << accountType << endl;
    cout << "- Account ID: " << accountID << endl;
    cout << "- Amount: " << amount << endl;
    cout << endl;

    cout << "Is this information correct? (y/n): ";
    string confirmation;
    getline(cin, confirmation);
    // Execute transfer
    if (confirmation == "y") {
        int result = 1;
        if (result == 1) {
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "An error occured" << endl;
        }
    } else {
        cout << "Withdrawal aborted" << endl;
    }
}