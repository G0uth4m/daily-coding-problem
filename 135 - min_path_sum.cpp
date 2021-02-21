/*
This question was asked by Apple.

Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1

*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

void helper(TreeNode* root, int partial, int& res) {
    if (root == nullptr) {
        return;
    }
    partial += root->data;
    if (root->left == nullptr && root->right == nullptr) {
        res = min(res, partial);
    }
    helper(root->left, partial, res);
    helper(root->right, partial, res);
}

int min_root_to_leaf_sum(TreeNode* root) {
    int res = INT32_MAX;
    helper(root, 0, res);
    return res;
}

int main() {
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(-1);

    node1->left = node2;
    node1->right = node3;

    node2->right = node4;

    node3->right = node5;

    node5->left = node6;

    cout << min_root_to_leaf_sum(node1) << endl;
}