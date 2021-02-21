#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool end;

    TrieNode() {
        children.assign(26, nullptr);
        end = false;
    }
};

#endif