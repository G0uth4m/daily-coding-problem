/*
This problem was asked by Google.

Given a binary tree of integers, find the maximum path sum between two nodes. 
The path must go through at least one node, and does not need to go through the root.
*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void max_root_path_sum(TreeNode* root, int temp, int* res) {
    if (root == nullptr) {
        return;
    }
    temp += root->data;
    *res = max(*res, temp);
    max_root_path_sum(root->left, temp, res);
    max_root_path_sum(root->right, temp, res);
}

int max_root_path_sum(TreeNode* root) {
    int res = 0;
    max_root_path_sum(root, 0, &res);
    return res;
}

int max_path_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int l = max_root_path_sum(root->left);
    int r = max_root_path_sum(root->right);

    int lp = max_path_sum(root->left);
    int rp = max_path_sum(root->right);

    int res = 0;
    res = max(res, l + r + root->data);
    res = max(res, l);
    res = max(res, r);
    res = max(res, lp);
    res = max(res, rp);
    return res;
}