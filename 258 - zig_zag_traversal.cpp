/*
This problem was asked by Morgan Stanley.

In Ancient Greece, it was common to write text with the first line going left to right, 
the second line going right to left, and continuing to go back and forth. 
This style was called "boustrophedon".

Given a binary tree, write an algorithm to print the nodes in boustrophedon order.

For example, given the following tree:

       1
    /     \
  2         3
 / \       / \
4   5     6   7

You should return [1, 3, 2, 4, 5, 6, 7].
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

vector<int> zigZagTraversal(TreeNode* node) {
    queue<TreeNode*> q;
    q.push(node);

    vector<int> res;
    bool flag = true;
    while (!q.empty()) {
        flag = !flag;
        int x = q.size();
        vector<int> level;
        while (x--) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->data);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        if (flag) {
            reverse(level.begin(), level.end());
        }
        for (int i : level) {
            res.push_back(i);
        }
    }
    return res;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    vector<int> res = zigZagTraversal(node1);
    print(res);
}
