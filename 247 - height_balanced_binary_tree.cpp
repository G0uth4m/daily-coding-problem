/*
This problem was asked by PayPal.

Given a binary tree, determine whether or not it is height-balanced. 
A height-balanced binary tree can be defined as one in which the 
heights of the two subtrees of any node never differ by more than one.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

pair<int, bool> isHeightBalancedUtil(TreeNode* node) {
    if (node == nullptr) {
        return {0, true};
    }
    pair<int, bool> l = isHeightBalancedUtil(node->left);
    if (!l.second) {
        return l;
    }
    pair<int, bool> r = isHeightBalancedUtil(node->right);
    if (!r.second) {
        return r;
    }

    return {1 + max(l.first, r.first), l.second && r.second && abs(l.first - r.first) <= 1};
}

bool isHeightBalanced(TreeNode* node) {
    return isHeightBalancedUtil(node).second;
}
