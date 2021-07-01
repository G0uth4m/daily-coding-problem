/*
This problem was asked by Salesforce.

Write a program to merge two binary trees. 
Each node in the new tree should hold a value equal to 
the sum of the values of the corresponding nodes of the input trees.

If only one input tree has a node in a given position, 
the corresponding node in the new tree should match that input node.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) {
        return root2;
    }
    if (root2 == nullptr) {
        return root1;
    }
    root1->data += root2->data;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
