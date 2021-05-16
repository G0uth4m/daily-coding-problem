/*
This problem was asked by Yext.

Two nodes in a binary tree can be called cousins if they are on the same level of the tree 
but have different parents. For example, in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6

Given a binary tree and a particular node, find all cousins of that node.
*/

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

void print(vector<TreeNode*>& A) {
    for (TreeNode* node : A) {
        cout << node->data << " ";
    }
    cout << endl;
}

vector<TreeNode*> cousins(TreeNode* root, TreeNode* node) {
    queue<TreeNode*> q;
    q.push(root);
    
    TreeNode* parent = nullptr;
    while (!q.empty() && !parent) {
        int x = q.size();
        while (x--) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left) {
                if (front->left == node) {
                    parent = front;
                }
                q.push(front->left);
            }
            if (front->right) {
                if (front->right == node) {
                    parent = front;
                }
                q.push(front->right);
            }
        }
    }

    vector<TreeNode*> res;
    while (!q.empty()) {
        TreeNode* treeNode = q.front();
        q.pop();
        if (treeNode != parent->left && treeNode != parent->right) {
            res.push_back(treeNode);
        }
    }
    return res;
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->right = node6;

    vector<TreeNode*> res = cousins(node1, node4);
    print(res);
}
