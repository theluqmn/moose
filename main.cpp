#include <iostream>
#include <string>

#include "prompts/prompts.h"
#include "functions/functions.h"

using namespace std;

int main() {
    cout << "Hello! says the machine" << endl;
    cout << "MOOSE - simple bank management system" << endl;
    cout << "https://github.com/theluqmn/moose" << endl;
    cout << endl;
    cout << "'quit' to exit | 'help' to open help" << endl;

    string input;
    
    while (true) {
        cout << "> ";
        getline(cin, input);
        
        clearScreen();
        if (input == "quit") {
            cout << "till we meet again." << endl;
            break;
        } else if (input == "help") {
            promptHelp();
        } else if (input == "account open") {
            promptOpenAccount();
        } else if (input == "account close") {
            promptCloseAccount();
        } else if (input == "funds deposit") {
            promptFundDeposit();
        } else if (input == "funds transfer") {
            promptTransfer();
        } else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}