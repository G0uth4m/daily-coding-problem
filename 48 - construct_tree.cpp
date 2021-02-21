/*
This problem was asked by Google.

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g
*/

#include <iostream>
#include <vector>
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

int search(vector<char> A, char c, int start, int end) {
    for (int i=start; i<=end; i++) {
        if (A[i] == c) {
            return i;
        }
    }
    return -1;
}

TreeNode* construct(vector<char>& preorder, vector<char>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
    if (pre_left > pre_right || in_left > in_right) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(preorder[pre_left]);
    int idx = search(inorder, preorder[pre_left], in_left, in_right);

    newNode->left = construct(preorder, inorder, pre_left + 1, pre_left + idx - in_left, in_left, idx - 1);
    newNode->right = construct(preorder, inorder, pre_left + 1 + idx - in_left, pre_right, idx + 1, in_right);

    return newNode;
}

void print_preoder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    print_preoder(root->left);
    print_preoder(root->right);
}

void print_inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

int main() {
    vector<char> preorder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    vector<char> inorder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
    TreeNode* root = construct(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    print_inorder(root);
    cout << endl;
    print_preoder(root);
    cout << endl;
}