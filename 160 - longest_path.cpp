/*
This problem was asked by Uber.

Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h

and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1, the longest path would be c -> a -> d -> f, 
with a length of 17.

The path does not have to pass through the root, and each node can have any amount of children.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    char data;
    vector<pair<Node*, int>> children;

    Node(char data) {
        this->data = data;
    }

    void addChild(Node* node, int weight) {
        children.push_back({node, weight});
    }
};

int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int res = 0;
    for (auto& i : node->children) {
        res = max(res, i.second + height(i.first));
    }
    return res;
}

int longestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int resRootExcluded = 0;
    for (auto& i : root->children) {
        resRootExcluded = max(resRootExcluded, longestPath(i.first));
    }

    int resRootIncluded = 0;
    for (int i=0; i<root->children.size(); i++) {
        for (int j=i+1; j<root->children.size(); j++) {
            resRootIncluded = max(
                resRootIncluded, 
                root->children[i].second 
                + root->children[j].second 
                + height(root->children[i].first) 
                + height(root->children[j].first)
            );
        }
    }
    return max(resRootIncluded, resRootExcluded);
}

int main() {
    // and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1
    Node* node1 = new Node('a');
    Node* node2 = new Node('b');
    Node* node3 = new Node('c');
    Node* node4 = new Node('d');
    Node* node5 = new Node('e');
    Node* node6 = new Node('f');
    Node* node7 = new Node('g');
    Node* node8 = new Node('h');

    node1->addChild(node2, 3);
    node1->addChild(node3, 5);
    node1->addChild(node4, 8);

    node4->addChild(node5, 2);
    node4->addChild(node6, 4);

    node5->addChild(node7, 1);
    node5->addChild(node8, 1);

    cout << longestPath(node1) << endl;
}