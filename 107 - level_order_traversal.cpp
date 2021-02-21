/*
Problem 107
This problem was asked by Microsoft.

Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

       1
      / \
     2   3
    / \
   4   5

*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

void bfs(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        cout << front->data << " ";
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
    cout << endl;
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    bfs(node1);
}