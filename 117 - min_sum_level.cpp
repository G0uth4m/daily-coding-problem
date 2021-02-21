/*
This problem was asked by Facebook.

Given a binary tree, return the level of the tree with minimum sum.
*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

int min_sum_level(TreeNode* root) {
    if (!root) return -1;

    queue<TreeNode*> q;
    q.push(root);

    int min_sum = INT32_MAX;
    int level = 0;
    int res = 0;

    while (!q.empty()) {
        int x = q.size();
        int curr_level_sum = 0;
        while (x--) {
            TreeNode* front = q.front();
            q.pop();
            curr_level_sum += front->data;
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        level++;
        if (curr_level_sum < min_sum) {
            min_sum = curr_level_sum;
            res = level;
        }
    }
    return res;
}