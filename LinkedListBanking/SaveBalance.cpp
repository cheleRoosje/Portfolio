#include "SaveBalance.hpp"
#include "AccountNode.hpp"
#include <fstream>
#include <iostream>
#include <string> // Include the string header


void SaveBalance::writeInitialBalanceToFile(int accountNumber, float balance) {
    // Check if the account number already exists in the file
    if (!doesAccountNumberExists(accountNumber)) {
        // If the account number doesn't exist, write the initial balance to the file
        std::ofstream outFile("balances.txt", std::ios::app); // Open file in append mode
        if (outFile.is_open()) {
            outFile << accountNumber << " " << balance << std::endl;
            outFile.close();
            std::cout << "Balance written to file successfully." << std::endl;
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    } else {
        std::cout << "Account number already exists. Skipping write operation." << std::endl;
    }
}

bool SaveBalance::doesAccountNumberExists(int accountNumber) {
    std::ifstream inFile("balances.txt");
    int num;
    float balance;
    while (inFile >> num >> balance) {
        if (num == accountNumber) {
            inFile.close();
            return true; // Account number exists
        }
    }
    inFile.close();
    return false; // Account number does not exist
}

void SaveBalance::writeBalanceToFile(int accountNumber, float balance) {
    std::ofstream outFile("balances.txt", std::ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << accountNumber << " " << balance << std::endl;
        outFile.close();
        std::cout << "Balance written to file successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

float SaveBalance::retrieveBalanceFromFile(int accountNumber) {
    std::ifstream inFile("balances.txt");
    int num;
    float balance;
    float lastBalance = -1; // Initialize to a default value
    while (inFile >> num >> balance) {
        if (num == accountNumber) {
            lastBalance = balance; // Update last balance if a match is found
        }
    }
    inFile.close();
    return lastBalance; // Return the last found balance (or -1 if not found)
}






