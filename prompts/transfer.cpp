#include <iostream>
#include <string>

void promptTransfer() {
    std::string senderID;
    std::string receiverID;
    std::string description;
    float amount;

    std::cout << "[ Transfer ]" << std::endl;

    // Receiver's ID
    std::cout << "(1/4) Receiver's ID: ";
    std::getline(std::cin, receiverID);

    // Amount to transfer
    std::cout << "(2/4) Amount to transfer: ";
    std::cin >> amount;
    std::cin.ignore();

    // Transfer description
    std::cout << "(3/4) Transfer description: ";
    std::getline(std::cin, description);

    // Verify transfer information
    std::cout << "(4/4) Verify transfer information:" << std::endl;
    std::cout << "- Receiver's ID: " << receiverID << std::endl;
    std::cout << "- Amount: " << amount << std::endl;
    std::cout << "- Description: " << std::endl;
    std::cout << description << std::endl;
    std::cout << std::endl;

    std::cout << "Is this information correct? (y/n): ";
    std::string confirmation;
    std::getline(std::cin, confirmation);

    // Execute transfer
    if (confirmation == "y") {
        std::cout << "Transfer successful!" << std::endl;
    } else {
        std::cout << "Transfer aborted" << std::endl;
    }
}