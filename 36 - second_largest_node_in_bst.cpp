/*
This problem was asked by Dropbox.

Given the root to a binary search tree, find the second largest node in the tree.
*/
#include <iostream>
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

Node* second_largest_node(Node* root) {
    Node* iter = root;
    Node* parent = root;
    while (iter->right) {
        parent = iter;
        iter = iter->right;
    }
    if (iter->left == nullptr) {
        return parent;
    }
    Node* iter2 = iter->left;
    while (iter2->right) {
        iter2 = iter2->right;
    }
    return iter2;
}

int main() {
    Node* node1 = new Node(8);
    Node* node2 = new Node(3);
    Node* node3 = new Node(10);
    Node* node4 = new Node(1);
    Node* node5 = new Node(6);
    Node* node6 = new Node(14);
    Node* node7 = new Node(4);
    Node* node8 = new Node(7);
    Node* node9 = new Node(12);
    Node* node10 = new Node(13);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->right = node6;

    node5->left = node7;
    node5->right = node8;

    node6->left = node9;

    node9->right = node10;

    cout << second_largest_node(node1)->data << endl;
}

