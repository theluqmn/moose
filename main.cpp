#include <iostream>
#include <string>

#include "prompts/prompts.h"
#include "functions/functions.h"

int main() {
    std::cout << "Hello! says the machine" << std::endl;
    std::cout << "MOOSE - simple bank management system" << std::endl;
    std::cout << "https://github.com/theluqmn/moose" << std::endl;
    std::cout << std::endl;
    std::cout << "'quit' to exit | 'help' to open help" << std::endl;

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        clearScreen();
        if (input == "quit") {
            break;
        } else if (input == "help") {
            promptHelp();
        } else if (input == "create account") {
            promptCreateAccount();
        } else if (input == "transfer") {
            promptTransfer();
        } else {
            std::cout << "Invalid input" << std::endl;
        }
    }

    return 0;
}