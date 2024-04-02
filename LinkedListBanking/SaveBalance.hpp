#ifndef SAVEBALANCE_HPP
#define SAVEBALANCE_HPP

#include <string> // Include the string header


class SaveBalance {
public:

    //Function to write initial balance to file if the balance does not already exist in the file
    static void writeInitialBalanceToFile(int accountNumber, float balance);
    
    //Check to see if account number already exists in the file
    static bool doesAccountNumberExists(int accountNumber);

    // Function to write balance to file
    static void writeBalanceToFile(int accountNumber, float balance);

    // Function to retrieve balance from file
    static float retrieveBalanceFromFile(int accountNumber);
};

#endif // SAVEBALANCE_HPP
