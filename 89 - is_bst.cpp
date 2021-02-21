/*
This problem was asked by LinkedIn.

Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right, a
nd satisfies the constraint that the key in the left child must be less than or equal to the root 
and the key in the right child must be greater than or equal to the root.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

bool is_bst_util(TreeNode* node, int mini, int maxi) {
    if (node == nullptr) {
        return true;
    }
    if ((mini != -1 && node->data < mini) || (maxi != -1 && node->data > maxi)) {
        return false;
    }
    return is_bst_util(node->left, mini, node->data) && is_bst_util(node->right, node->data, maxi);
}

bool is_bst(TreeNode* root) {
    return is_bst_util(root, -1, -1);
}
