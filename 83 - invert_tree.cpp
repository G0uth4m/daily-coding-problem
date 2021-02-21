/*
This problem was asked by Google.

Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f

should become:

  a
 / \
 c  b
 \  / \
  f e  d

*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode* invert(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* temp = root->left;
    root->left = invert(root->right);
    root->right = invert(temp);
    return root;
}

void preorder(TreeNode* root) {
    if (root == nullptr) {
        cout << "x ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    TreeNode* node1 = new TreeNode('a');
    TreeNode* node2 = new TreeNode('b');
    TreeNode* node3 = new TreeNode('c');
    TreeNode* node4 = new TreeNode('d');
    TreeNode* node5 = new TreeNode('e');
    TreeNode* node6 = new TreeNode('f');

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;

    preorder(node1);
    cout << endl;

    preorder(invert(node1));
    cout << endl;
}
