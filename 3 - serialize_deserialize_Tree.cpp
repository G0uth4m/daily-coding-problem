/*
This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string,
and deserialize(s), which deserializes the string back into the tree.
*/

#include <iostream>
#include <queue>
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

string serialize_tree_to_string(Node* root) {
    if (root == nullptr) {
        return "x,";
    }
    return to_string(root->data) + "," + serialize_tree_to_string(root->left) + serialize_tree_to_string(root->right);
}

Node* helper(string& serialized, int& i) {
    string temp = "";
    while (serialized[i] != ',') {
        temp.push_back(serialized[i]);
        i++;
    }
    i++;
    if (temp == "x") {
        return nullptr;
    }
    Node* newNode = new Node(stoi(temp));
    newNode->left = helper(serialized, i);
    newNode->right = helper(serialized, i);
    return newNode;
}

Node* deserialize_string_to_tree(string s) {
    int i = 0;
    return helper(s, i);
}

void print_preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->left = node2;
    node1->right = node3;

    node3->left = node4;
    node3->right = node5;

    string res = serialize_tree_to_string(node1);
    cout << res << endl;

    Node* root = deserialize_string_to_tree(res);
    print_preorder(root);
    cout << endl;

    cout << serialize_tree_to_string(root) << endl;
}