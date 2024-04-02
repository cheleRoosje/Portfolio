#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

class ListNode; //forward decleration to resolve circular inclusion

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode();
    TreeNode(int data);

   

    void convertList2Tree(ListNode *head, TreeNode* &root);
    void inorderTraversal(TreeNode* root);
    void preorderTraversal(TreeNode* root);
    void postorderTraversal(TreeNode* root);

};

#endif