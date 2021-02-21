/*
This problem was asked by Facebook.

Given a binary tree, return all paths from the root to leaves.

For example, given the tree

   1
  / \
 2   3
    / \
   4   5

it should return [[1, 2], [1, 3, 4], [1, 3, 5]].
*/

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

void preorder(TreeNode* node, vector<int> temp, vector<vector<int>>& res) {
    if (node == nullptr) {
        return;
    }
    temp.push_back(node->data);
    if (node->left == nullptr && node->right == nullptr) {
        res.push_back(temp);
        return;
    }
    preorder(node->left, temp, res);
    preorder(node->right, temp, res);
}

vector<vector<int>> all_paths(TreeNode* root) {
    vector<vector<int>> res;
    preorder(root, {}, res);
    return res;
}

void print(vector<vector<int>>& A) {
    for (vector<int>& i : A) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;

    node3->left = node4;
    node3->right = node5;

    vector<vector<int>> res = all_paths(node1);
    print(res);
}