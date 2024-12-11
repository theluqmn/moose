#include <iostream>
#include <string>

#include "prompts/prompts.h"

int main() {
    std::cout << "Hello! says the machine" << std::endl;

    promptCreateAccount();
    promptTransfer();

    return 0;
}