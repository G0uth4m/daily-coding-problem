/*
This problem was asked by Microsoft.

Suppose an arithmetic expression is given as a binary tree. 
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int evaluate(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->data == "+") {
        return evaluate(root->left) + evaluate(root->right);
    } else if (root->data == "-") {
        return evaluate(root->left) - evaluate(root->right);
    } else if (root->data == "*") {
        return evaluate(root->left) * evaluate(root->right);
    } else if (root->data == "/") {
        int r = evaluate(root->right);
        if (r == 0) {
            throw "Division by zero";
        }
        return evaluate(root->left) / r;
    }
    return stoi(root->data);
}

int main() {
    TreeNode* node1 = new TreeNode("*");
    TreeNode* node2 = new TreeNode("+");
    TreeNode* node3 = new TreeNode("+");
    TreeNode* node4 = new TreeNode("3");
    TreeNode* node5 = new TreeNode("2");
    TreeNode* node6 = new TreeNode("4");
    TreeNode* node7 = new TreeNode("5");

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    cout << evaluate(node1) << endl;
}