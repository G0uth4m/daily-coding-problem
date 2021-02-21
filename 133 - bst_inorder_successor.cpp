/*
This problem was asked by Amazon.

Given a node in a binary tree, return the next bigger element, also known as the inorder successor. (NOTE: I'm assuming this is a binary search tree, because otherwise, the problem makes no sense at all)

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35
You can assume each node has a parent pointer.

*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

// O(h); O(1)
TreeNode* inorder_successor(TreeNode* node) {
    if (node->right) {
        TreeNode* iter = node->right;
        while (iter->left) {
            iter = iter->left;
        }
        return iter;
    }
    TreeNode* parent = node->parent;
    while (parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

// O(h); O(1)
TreeNode* inorder_successor2(TreeNode* root, TreeNode* node) {
    if (node->right) {
        TreeNode* iter = node->right;
        while(iter->left) {
            iter = iter->left;
        }
        return iter;
    }

    TreeNode* succ = nullptr;
    while (root) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            return succ;
        }
    }
    return nullptr;
}