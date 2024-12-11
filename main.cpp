#include <iostream>
#include <string>

#include "functions/payment.h"
#include "functions/accounts/accounts.h"

int main() {
    std::cout << "Hello! says the machine" << std::endl;

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Hello " << name << "!" << std::endl;

    printPayment();
    promptCreateAccount();
    createAccount("John Doe", "password123"); // Using a smaller account ID

    return 0;
}