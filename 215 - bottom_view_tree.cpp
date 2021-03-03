/*
This problem was asked by Yelp.

The horizontal distance of a binary tree node describes how far left or right the node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.

For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8

The bottom view of a tree, then, consists of the lowest node at each horizontal distance. 
If there are two nodes at the same depth and horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "TreeNode.h"
using namespace std;

vector<int> bottomView(TreeNode* root) {
    vector<int> res;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    map<int, int> map;

    while (!q.empty()) {
        pair<TreeNode*, int> p = q.front();
        q.pop();
        map[p.second] = p.first->data;
        if (p.first->left) {
            q.push({p.first->left, p.second - 1});
        }
        if (p.first->right) {
            q.push({p.first->right, p.second + 1});
        }
    }
    for (auto i : map) {
        res.push_back(i.second);
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
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(9);
    TreeNode* node8 = new TreeNode(0);
    TreeNode* node9 = new TreeNode(8);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    node4->left = node8;

    node7->left = node9;

    vector<int> res = bottomView(node1);
    print(res);
}
