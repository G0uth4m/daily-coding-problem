/*
This problem was asked by Twitter.

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. 
Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined 
between two nodes v and w as the lowest node in T that has both v and w as descendants 
(where we allow a node to be a descendant of itself)."
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

void path_len_util(Node* root, Node* node, int temp, int& res) {
    if (root == nullptr) {
        return;
    }
    if (root == node) {
        res = temp;
        return;
    }
    path_len_util(root->left, node, temp + 1, res);
    path_len_util(root->right, node, temp + 1, res);
}

// O(n)
int path_len(Node* root, Node* node) {
    int res = 0;
    path_len_util(root, node, 0, res);
    return res;
}

// O(n)
Node* lca(Node* root, Node* node1, Node* node2) {
    int l1 = path_len(root, node1);
    int l2 = path_len(root, node2);

    Node* longer = node1;
    Node* shorter = node2;

    if (l1 < l2) {
        swap(longer, shorter);
    }

    for (int i=0; i<abs(l1 - l2); i++) {
        longer = longer->parent;
    }

    while (shorter != longer) {
        shorter = shorter->parent;
        longer = longer->parent;
    }
    return shorter;
}

pair<Node*, int> lca2(Node* root, Node* node1, Node* node2) {
    if (root == nullptr) {
        return {nullptr, 0};
    }
    pair<Node*, bool> l = lca2(root->left, node1, node2);
    if (l.second == 2) {
        return l;
    }
    pair<Node*, bool> r = lca2(root->left, node1, node2);
    if (r.second == 2) {
        return r;
    }
    int num = l.second + r.second + node1->data == root->data + node2->data == root->data;
    Node* node = num == 2 ? root : nullptr;
    return {node, num};
}