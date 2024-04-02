
//#include <iostream>
#include "TreeNode.hpp"
#include "ListNode.hpp"
#include <queue>

TreeNode::TreeNode() : data(0), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}

//create a new binary tree node
TreeNode* newTreeNode(int data){
    //create new TreeNode and assign to pointer temp
    TreeNode *temp = new TreeNode;
    temp->data = data;
    temp->left = temp->right = nullptr; //initializing left and right to NULL
    //can also be written in two lines temp->left = nullptr; temp->right = nullptr;
    //return the pointer to the newly created node
    return temp;
}

//convert linked list representing a complete binary tree into the linked representation of binary tree
void TreeNode::convertList2Tree(ListNode *head, TreeNode* &root){
    //queue to store the parent nodes
    queue<TreeNode*> q;

    //Base Case
    if (head == nullptr){
        root = nullptr;
        return;
    }

    //first node (head) addedd to the queue
    root = newTreeNode(head->data);
    q.push(root);

    //advance the pointer to the next node
    head = head->next;

    //until the end of the linked list is reached do the following
    while(head){
        //remove parent node from q
        TreeNode* parent = q.front();
        q.pop();

        //take next two nodes from the linked list and add them as children. Push them in the queue so they will be parrents of future nodes
        TreeNode *left = nullptr, *right = nullptr;
        left = newTreeNode(head->data);
        q.push(left);
        head = head->next;
        if(head){
            right = newTreeNode(head->data);
            q.push(right);
            head = head->next;
        }

        //assign the left and right children of parent
        parent->left = left;
        parent->right = right;

    }
}

//traverse the tree InOrder
void TreeNode::inorderTraversal(TreeNode* root){
    if(root == nullptr)
    return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

//traverse the tree PreOrder
void TreeNode::preorderTraversal(TreeNode* root){
    if(root == nullptr)
    return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//traverse the tree PostOrder
void TreeNode::postorderTraversal(TreeNode* root){
    if(root == nullptr)
    return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}



