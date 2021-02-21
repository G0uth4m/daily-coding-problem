/*
This problem was asked by Google.

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. 
A subtree of s is a tree consists of a node in s and all of this node's descendants. 
The tree s could also be considered as a subtree of itself.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

string serialize(TreeNode* root) {
    if (root == nullptr) {
        return ",x";
    }
    return "," + to_string(root->data) + serialize(root->left) + serialize(root->right);
}

// O(m*m + n*n + m*n)
bool is_subtree(TreeNode* s, TreeNode* t) {
    string s_serialized = serialize(s);
    string t_serialized = serialize(t);
    return s_serialized.find(t_serialized) != string::npos;
}

bool equals(TreeNode* s, TreeNode* t) {
    if (!s && !t) {
        return true;
    }
    if (!s || !t) {
        return false;
    }
    return s->data == t->data && equals(s->left, t->left) && equals(s->right, t->right);
}

// O(m*n)
bool is_subtree2(TreeNode* s, TreeNode* t) {
    return s && (equals(s, t) || is_subtree2(s->left, t) || is_subtree2(s->right, t));
}