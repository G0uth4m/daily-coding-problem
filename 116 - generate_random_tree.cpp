/*
This problem was asked by Jane Street.

Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode* generate() {
    size_t tree_size = (size_t)rand();
    TreeNode* root = new TreeNode((int)rand());
    TreeNode* iter = root;
    for (size_t i=0; i<tree_size; i++) {
        int r = rand() % 100;
        if (r < 50) {
            if (!iter->left) {
                iter->left = new TreeNode((int)rand());
            }
            iter = iter->left;
        } else {
            if (!iter->right) {
                iter->right = new TreeNode((int)rand());
            }
            iter = iter->right;
        }
    }
    return root;
}