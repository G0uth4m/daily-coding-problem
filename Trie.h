#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <stack>
#include "TrieNode.h"
using namespace std;

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* iter = root;
        for (int i=0; i<s.size(); i++) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                iter->children[s[i] - 'a'] = new TrieNode();
            }
            iter = iter->children[s[i] - 'a'];
        }
        iter->end = true;
    }

    bool find(string s) {
        TrieNode* iter = root;
        for (int i=0; i<s.size(); i++) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                return false;
            }
            iter = iter->children[s[i] - 'a'];
        }
        return iter->end;
    }

    vector<string> prefixSearch(string s) {
        TrieNode* iter = root;
        for (int i=0; i<s.size(); i++) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                return {};
            }
            iter = iter->children[s[i] - 'a'];
        }

        stack<pair<TrieNode*, string>> stk;
        stk.push({iter, s});

        vector<string> res;

        while(!stk.empty()) {
            pair<TrieNode*, string> top = stk.top();
            stk.pop();

            if (top.first->end) {
                res.push_back(top.second);
            }

            for (int i=0; i<26; i++) {
                if (top.first->children[i]) {
                    stk.push({top.first->children[i], top.second + (char)((int)'a' + i)});
                }
            }
        }

        return res;
    }
};

#endif