/*
This problem was asked by Google.

Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15

Return the nodes 5 and 15.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include "TreeNode.h"
using namespace std;

void inorder(TreeNode* root, vector<TreeNode*>& res) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root);
    inorder(root->right, res);
}

// O(n); O(n)
pair<TreeNode*, TreeNode*> two_sum(TreeNode* root, int sum) {
    vector<TreeNode*> res;
    inorder(root, res);
    int left = 0;
    int right = res.size() - 1;
    while (left < right) {
        int curr_sum = res[left]->data + res[right]->data;
        if (curr_sum == sum) {
            return {res[left], res[right]};
        } else if (curr_sum > sum) {
            right--;
        } else {
            left++;
        }
    }
    return {nullptr, nullptr};
}

void inorder2(TreeNode* root, unordered_set<int>& set, int sum, pair<int, int>& res) {
    if (root == nullptr) {
        return;
    }
    inorder2(root->left, set, sum, res);
    if (set.find(sum - root->data) != set.end()) {
        res = {root->data, sum - root->data};
        return;
    }
    set.insert(root->data);
    inorder2(root->right, set, sum, res);
}

// O(n); O(n)
pair<int, int> two_sum2(TreeNode* root, int sum) {
    unordered_set<int> set;
    pair<int, int> res;
    inorder2(root, set, sum, res);
    return res;
}

int main() {
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(17);

    node1->left = node2;
    node1->right = node3;

    node3->left = node4;
    node3->right = node5;

    pair<int, int> res = two_sum2(node1, 20);
    cout << res.first << " " << res.second << endl;
}