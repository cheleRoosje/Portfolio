#include "ListNode.hpp"
#include <iostream>
using namespace std;

// insert node at the beginnig of linked list
void ListNode::insertNode(ListNode** head_ref, int new_data){
    //allocate node and assign data
    ListNode* new_node = new ListNode;
    new_node->data = new_data;

    //link the old list of the new node
    new_node->next = (*head_ref);

    //move the head to point to the new node
    (*head_ref) = new_node;
}
    
