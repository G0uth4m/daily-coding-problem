/*
This problem was asked by Google.

Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.
*/

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// O(n); O(h)
TreeNode* deepest_node(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* deepest_node = nullptr;
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        deepest_node = temp;
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    return deepest_node;
}

int main() {
    TreeNode* node1 = new TreeNode('a');
    TreeNode* node2 = new TreeNode('b');
    TreeNode* node3 = new TreeNode('c');
    TreeNode* node4 = new TreeNode('d');

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;

    cout << deepest_node(node1)->data << endl;
}