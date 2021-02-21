/*
This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:
   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool is_unival(Node* root) {
    if (root == nullptr) {
        return true;
    }
    if (root->left && root->left->data != root->data) {
        return false;
    }
    if (root->right && root->right->data != root->data) {
        return false;
    }
    return is_unival(root->left) && is_unival(root->right);   
}

int num_univals(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int to_return = num_univals(root->left) + num_univals(root->right);
    if (is_unival(root)) {
        return 1 + to_return;
    }
    return to_return;
}

// ================================== Optimized solution ==================================== //

bool is_unival2(Node* root, unordered_map<Node*, bool>* cache) {
    if (cache->find(root) != cache->end()) {
        return cache->at(root);
    }
    if (root == nullptr) {
        return true;
    }
    if (root->left && root->left->data != root->data) {
        return false;
    }
    if (root->right && root->right->data != root->data) {
        return false;
    }
    bool to_return = is_unival2(root->left, cache) && is_unival2(root->right, cache);
    cache->insert({root, to_return});
    return to_return;
}

int helper(Node* root, unordered_map<Node*, bool>* cache) {
    if (root == nullptr) {
        return 0;
    }
    int to_return = helper(root->left, cache) + helper(root->right, cache);
    if (is_unival2(root, cache)) {
        return 1 + to_return;
    }
    return to_return;
}

// O(n)
int num_univals2(Node* root) {
    unordered_map<Node*, bool> cache;
    return helper(root, &cache);
}

int main() {
    Node* node1 = new Node(0);
    Node* node2 = new Node(1);
    Node* node3 = new Node(0);
    Node* node4 = new Node(1);
    Node* node5 = new Node(0);
    Node* node6 = new Node(1);
    Node* node7 = new Node(1);

    node1->left = node2;
    node1->right = node3;

    node3->left = node4;
    node3->right = node5;

    node4->left = node6;
    node4->right = node7;

    cout << num_univals2(node1) << endl;
}