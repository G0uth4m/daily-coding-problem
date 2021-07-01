/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Netflix.

A Cartesian tree with sequence S is a binary tree defined by the following two properties:

It is heap-ordered, so that each parent value is strictly less than that of its children.
An in-order traversal of the tree produces nodes with values that correspond exactly to S.
For example, given the sequence [3, 2, 6, 1, 9], the resulting Cartesian tree would be:

      1
    /   \   
  2       9
 / \
3   6

Given a sequence S, construct the corresponding Cartesian tree.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "TreeNode.h"
using namespace std;

TreeNode* constructCartesianTree(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end) {
        return nullptr;
    }
    vector<int>::iterator min = min_element(begin, end);
    TreeNode* node = new TreeNode(*min);
    node->left = constructCartesianTree(begin, min);
    node->right = constructCartesianTree(min + 1, end);
    return node;
}

TreeNode* constructCartesianTree(vector<int>& A) {
    return constructCartesianTree(A.begin(), A.end());
}

void inorder(TreeNode* node, vector<int>& res) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left, res);
    res.push_back(node->data);
    inorder(node->right, res);
}

vector<int> inorder(TreeNode* node) {
    vector<int> res;
    inorder(node, res);
    return res;
}

int main() {
    vector<int> A = {3, 2, 6, 1, 9};
    TreeNode* res = constructCartesianTree(A);
    vector<int> actual = inorder(res);
    assert(A == actual);
}
