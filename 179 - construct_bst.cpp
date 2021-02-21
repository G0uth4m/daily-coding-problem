/*
This problem was asked by Google.

Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode* constructBSTUtil(vector<int>& post, int& postIdx, int min, int max) {
    if (postIdx < 0 || post[postIdx] < min || post[postIdx] > max) {
        return nullptr;
    }
    TreeNode* node = new TreeNode(post[postIdx--]);
    node->right = constructBSTUtil(post, postIdx, node->data, max);
    node->left = constructBSTUtil(post, postIdx, min, node->data);
    return node;
}

TreeNode* constructBST(vector<int>& postorder) {
    int postIdx = postorder.size() - 1;
    return constructBSTUtil(postorder, postIdx, INT32_MIN, INT32_MAX);
}

void levelOrder(TreeNode* node) {
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        int x = q.size();
        while (x--) {
            TreeNode* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        cout << endl;
    }
}

int main() {
    vector<int> postorder = {2, 4, 3, 8, 7, 5};
    TreeNode* res = constructBST(postorder);
    levelOrder(res);
}
