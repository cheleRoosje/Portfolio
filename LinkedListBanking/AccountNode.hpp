#ifndef ACCOUNTNODE_HPP
#define ACCOUNTNODE_HPP

#include "Data.hpp"

class AccountNode {
public:
    // Constructor
    AccountNode(const Data& data);

    // Public member functions
    Data* getData() const; // Getter for data
    void setData(Data* newData); // Setter for data
    void setNext(AccountNode* newNext); // Setter for next
    AccountNode* getNext() const; // Declaration for getNext() without extra qualification

private:
    Data* data; // Pointer to Data object
    AccountNode* next; // Pointer to the next node
};

#endif // ACCOUNTNODE_HPP
