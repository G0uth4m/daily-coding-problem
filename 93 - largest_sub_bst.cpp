/*
This problem was asked by Apple.

Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool is_bst_util(TreeNode* node, int mini, int maxi) {
    if (node == nullptr) {
        return true;
    }
    if ((mini != -1 && node->data < mini) || (maxi != -1 && node->data > maxi)) {
        return false;
    }
    return is_bst_util(node->left, mini, node->data) && is_bst_util(node->right, node->data, maxi);
}

bool is_bst(TreeNode* root) {
    return is_bst_util(root, -1, -1);
}

int size(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

// O(n^2)
int largest_sub_bst(TreeNode* root) {
    if (is_bst(root)) {
        return size(root);
    }
    return max(largest_sub_bst(root->left), largest_sub_bst(root->right));
}

struct EnhancedTreeNode {
    bool bst;
    int size;
    int mini;
    int maxi;
};

EnhancedTreeNode largest_sub_bst2_util(TreeNode* root) {
    if (root == nullptr) {
        return {true, 0, INT32_MAX, INT32_MIN};
    }
    EnhancedTreeNode l = largest_sub_bst2_util(root->left);
    EnhancedTreeNode r = largest_sub_bst2_util(root->right);
    if (l.bst && r.bst && l.maxi < root->data && r.mini > root->data) {
        return {true, 1 + l.size + r.size, min(l.mini, root->data), max(r.maxi, root->data)};
    }
    return {false, max(l.size, r.size), 0, 0};
}

// O(n)
int largest_sub_bst2(TreeNode* root) {
    return largest_sub_bst2_util(root).size;
}
