#include <iostream>
#include <string>

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