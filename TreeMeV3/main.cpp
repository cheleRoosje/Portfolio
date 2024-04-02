/*
Author: Michele Roosje
filenames: main.cpp, TreeNode.hpp, TreeNode.cpp, ListNode.hpp, ListNode.cpp
Date: March 10, 2024
Last Modified: March 11, 2024
Purpose: create inorder, preorder, and postorder traversals for given Binary Tree diagrams.
*/


#include <iostream>
#include "TreeNode.hpp"
#include "ListNode.hpp"
//#include <queue>

using namespace std;

int main(){

        //create object
    //ListNode treeList;
    ListNode* head = nullptr;

    //insert nodes with values Practice 1 diagram
    // head->insertNode(&head, 5);
    // head->insertNode(&head, 4);
    // head->insertNode(&head, 3);
    // head->insertNode(&head, 2);
    // head->insertNode(&head, 1);
    
    //insert nodes with values Practice 2 diagram
    // head->insertNode(&head, 'I');
    // head->insertNode(&head, 'H');
    // head->insertNode(&head, 'G');
    // head->insertNode(&head, 'F');
    // head->insertNode(&head, 'E');
    // head->insertNode(&head, 'D');
    // head->insertNode(&head, 'C');
    // head->insertNode(&head, 'B');
    // head->insertNode(&head, 'A');
    
    
    //insert nodes with values Practice 3 diagram
    head->insertNode(&head, 1);
    head->insertNode(&head, 40);
    head->insertNode(&head, 8);
    head->insertNode(&head, 4);
    head->insertNode(&head, 30);
    head->insertNode(&head, 5);
    head->insertNode(&head, 10);
   
   
   
   TreeNode* root = new TreeNode(); //allocate memory for root
    root->convertList2Tree(head, root);

    cout << "Inorder Traversal of the constructed Binary Tree is : \n";
    root->inorderTraversal(root);
    cout << endl;
    cout << "Preorder Traversal of the constructed Binary Tree is : \n";
    root->preorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal of the constructed Binary Tree is : \n";
    root->postorderTraversal(root);
    return 0;

}