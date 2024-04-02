/*
Author: Michele Roosje
fileName: LinkedListBankingV6.cpp
Created: February 22, 2024
Last Modified: February 29, 2024
Purpose: Assignment: Write a C++ program that has a linked list class that processes bank accounts.
        It should store a name (as an array of characters), an account number (as an interger), and a balance (as a  float).
        It should allow deposits, withdrawals, and balance inquiries as well as the ability to add and remove accounts.
*/

#include "Data.hpp"
#include "AccountNode.hpp"
#include "SaveBalance.hpp"
#include <iostream>
#include <string>

int mainMenu();

int main() {
    int choice;
    int accountNumb;
    float deposit;
    float withdraw;
    float balance;
    float newBalance;

    Data data1(123456, "Zhao Wen", 1000.0);
    Data data2(654321, "JC Wildone", 2000.0);
    Data data3(789456, "Wolf Dragon", 5000.0);
    

    AccountNode* head = new AccountNode(data1);
    AccountNode* account2 = new AccountNode(data2);
    AccountNode* account3 = new AccountNode(data3);
    
    
    head->setNext(account2);
    account2->setNext(account3);
    account3->setNext(NULL);
     

    std::cout << " Welcome to Banking Friends\n";
    std::cout << " Enter your account number\n";
    std::cin >> accountNumb;
    
     // Find the account with the entered account number
    AccountNode* current = head;
    while (current != nullptr && current->getData()->getAccountNumber() != accountNumb) {
        current = current->getNext();
    }

    // If the account is not found, inform the user and exit
    if (current == nullptr) {
        std::cout << "Account not found. Exiting program.\n";
        return 0;
    }
    
    //load updated balance from file
    newBalance = SaveBalance::retrieveBalanceFromFile(accountNumb);
    current->getData()->updateBalance(newBalance); // must be called that way as apposed to Data::updateBalance(newBalance); to update the node data

    do {
        choice = mainMenu();
    
        switch (choice) {
            case 1:
                // Get balance
                current->getData()->getBalance(accountNumb);
                std::cout << "\n";
                break;
                
            case 2:
                //deposit
                std::cout << " Enter the amount you would like to deposit. \n";
                std::cin >> deposit;
                std::cout << "\n";
                balance = current->getData()->setDeposit(accountNumb, deposit); // add deposit amount and update balance variable
                current->getData()->getBalance(accountNumb);  //print the balance
                std::cout << "\n";
                SaveBalance::writeBalanceToFile(accountNumb, balance); //update balance in the file
                break;
                
            case 3:
                //withdrawl
                std::cout << " Enter the amount you would like to withdraw. \n";
                std::cin >> withdraw;
                std::cout << "\n";
                balance = current->getData()->setWithdrawal(accountNumb, withdraw); //subtract the withdrawl amount and update balance variable
                current->getData()->getBalance(accountNumb);  //print the balance
                std::cout << "\n";
                SaveBalance::writeBalanceToFile(accountNumb, balance);  // Update balance in the file
                break;
                
            case 4:
                //Exit
                std::cout << " Thank you for choosing Banking Friends \n";
                break;
                
            default:
                std::cout << "You must enter a number from 1 to 5. \n";
                break;
        }
    }while (choice != 4); // Continue until the user chooses to exit
    return 0;
}

int mainMenu() {
    int choice;
    std::cout << " Please choose one of the following options\n";
    std::cout << " 1. Balance Inquiry \n";
    std::cout << " 2. Deposit \n";
    std::cout << " 3. Withdrawal \n";
    std::cout << " 4. Exit  \n";
    std::cin >> choice;
    return choice;
}
