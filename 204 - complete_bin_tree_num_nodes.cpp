/*
This problem was asked by Amazon.

Given a complete binary tree, count the number of nodes in faster than O(n) time. 
Recall that a complete binary tree has every level filled except the last, 
and the nodes in the last level are filled starting from the left.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

int numNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}