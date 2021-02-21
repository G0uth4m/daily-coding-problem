/*
This problem was asked by Apple.

Given the root of a binary tree, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node, including the node itself.

For example, given the following tree:

  5
 / \
2  -5

Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.
*/

#include <iostream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

int postorder(TreeNode* root, unordered_map<int, int>& map) {
    if (root == nullptr) {
        return 0;
    }
    int l = postorder(root->left, map);
    int r = postorder(root->left, map);
    int sum = root->data + l + r;
    map[sum]++;
    return sum;
}

int mostFreqSubtreeSum(TreeNode* root) {
    unordered_map<int, int> map;
    postorder(root, map);
    int sum = 0;
    int freqSum = 0;
    for (auto i : map) {
        if (i.second > freqSum) {
            freqSum = i.second;
            sum = i.first;
        }
    }
    return sum;
}

int main() {
    TreeNode* node1 = new TreeNode(-5);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(-5);

    node1->left = node2;
    node1->right = node3;

    cout << mostFreqSubtreeSum(node1) << endl;
}