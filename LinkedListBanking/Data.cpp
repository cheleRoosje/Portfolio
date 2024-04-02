#include "Data.hpp"
#include "SaveBalance.hpp"
#include <iostream>
#include <cstring> // Add this line for strncpy
#include <iomanip> // Add this line to include the necessary header




Data::Data(int accountNumber, const char* nameArray, float balance)
    : accountNumber(accountNumber), balance(balance) {
    strncpy(name, nameArray, 50);
        this->name[49] = '\0'; // Ensure null termination
        
    // Save the initial balance to the file when the object is created
    SaveBalance::writeInitialBalanceToFile(accountNumber, balance);

}

// Data.cpp
int Data::getAccountNumber() const {
    return accountNumber;
}

void Data::getBalance(int acctNum) {
    if (accountNumber == acctNum) {
        std::cout << "Account Number " << accountNumber << " Name " << name << " Current Balance $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
}

float Data::setDeposit(int acctNum, float depositAmt) {
    if (accountNumber == acctNum) {
        balance += depositAmt;
    }
    return balance;
}

float Data::setWithdrawal(int acctNum, float withdrawAmt) {
    if (accountNumber == acctNum) {
        balance -= withdrawAmt; 
    }
    return balance;
}

void Data::updateBalance(float newBalance) {
        balance = newBalance;
    }