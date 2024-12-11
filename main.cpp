#include <iostream>
#include <string>

#include "functions/payment.h"

int main() {
    std::cout << "Hello! says the machine" << std::endl;

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Hello " << name << "!" << std::endl;

    printPayment();

    return 0;
}