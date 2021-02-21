/*
This problem was asked by Twitter.

Implement an autocomplete system. 
That is, given a query string s and a set of all possible query strings,
return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool end;

    TrieNode() {
        children.assign(26, nullptr);
    }
};

struct Helper {
    TrieNode* current;
    string prefix;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* iter = root;
        int i = 0;
        while (i < s.size()) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                iter->children[s[i] - 'a'] = newNode;
            }
            iter = iter->children[s[i] - 'a'];
            i++;
        }
        iter->end = true;
    }

    bool search(string s) {
        TrieNode* iter = root;
        int i = 0;
        while (i < s.size()) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                return false;
            }
            iter = iter->children[s[i] - 'a'];
            i++;
        }
        return iter->end;
    }

    bool startswith(string s) {
        TrieNode* iter = root;
        int i = 0;
        while (i < s.size()) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                return false;
            }
            iter = iter->children[s[i] - 'a'];
            i++;
        }
        return true;
    }
    
    vector<string> autocomplete(string s) {
        TrieNode* iter = root;
        int i = 0;
        while (i < s.size()) {
            if (iter->children[s[i] - 'a'] == nullptr) {
                return {};
            }
            iter = iter->children[s[i] - 'a'];
            i++;
        }
        stack<Helper> stk;
        stk.push({iter, s});
        
        vector<string> res;

        while (!stk.empty()) {
            Helper h = stk.top();
            stk.pop();

            if (h.current->end) {
                res.push_back(h.prefix);
            }

            for (int i=0; i<26; i++) {
                if (h.current->children[i] != nullptr) {
                    stk.push({h.current->children[i], h.prefix + (char)((int)'a' + i)});
                }
            }
        }
        return res;
    }
};

int main() {
    Trie trie;
    trie.insert("dog");
    trie.insert("deer");
    trie.insert("deal");
    trie.insert("degree");
    trie.insert("dementia");

    vector<string> res = trie.autocomplete("do");
    for (auto i : res) {
        cout << i << endl;
    }
}