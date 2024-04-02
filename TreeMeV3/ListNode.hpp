#ifndef LISTNODE_H
#define LISTNODE_H


//linked list class to implement a linked list. 
class ListNode{
public:
    int data;
    ListNode* next;
    

    void insertNode(ListNode** head_ref, int new_data);
    
};




#endif