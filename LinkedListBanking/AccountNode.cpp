#include "AccountNode.hpp"

// Constructor implementation
AccountNode::AccountNode(const Data& data) : data(new Data(data)), next(nullptr) {}

// Getter for data
Data* AccountNode::getData() const {
    return data;
}

// Setter for data
void AccountNode::setData(Data* newData) {
    data = newData;
}

// Setter for next
void AccountNode::setNext(AccountNode* newNext) {
    next = newNext;
}

AccountNode* AccountNode::getNext() const {
    return next;
}