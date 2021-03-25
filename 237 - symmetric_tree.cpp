/*
This problem was asked by Amazon.

A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. 
The following tree is an example:

        4
      / | \
    3   5   3
  /           \
9              9

Given a k-ary tree, determine whether it is symmetric.
*/

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int data, int k) {
        this->data = data;
        children.assign(k, nullptr);
    }

    void addChild(TreeNode* node, int i) {
        children[i] = node;
    }

    void setChildren(vector<TreeNode*> children) {
        this->children = children;
    }
};

bool isMirror(TreeNode* node1, TreeNode* node2, int k) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }
    if (node1 == nullptr || node2 == nullptr || node1->data != node2->data) {
        return false;
    }
    int left = 0;
    int right = k - 1;
    while (left < k) {
        if (!isMirror(node1->children[left], node2->children[right], k)) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isSymmetric(TreeNode* root, int k) {
    if (root == nullptr) {
        return true;
    }

    int left = 0;
    int right = k - 1;
    while (left < right) {
        if (!isMirror(root->children[left], root->children[right], k)) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    TreeNode* node1 = new TreeNode(4, 3);
    TreeNode* node2 = new TreeNode(3, 3);
    TreeNode* node3 = new TreeNode(5, 3);
    TreeNode* node4 = new TreeNode(3, 3);
    TreeNode* node5 = new TreeNode(9, 3);
    TreeNode* node6 = new TreeNode(9, 3);

    node1->setChildren({node2, node3, node4});

    node2->addChild(node5, 0);

    node4->addChild(node6, 2);

    cout << isSymmetric(node1, 3) << endl;
}