/*
This problem was asked by Square.

Given a list of words, return the shortest unique prefix of each word. For example, given the list:

dog
cat
apple
apricot
fish

Return the list:

d
c
app
apr
f
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    int freq;
    bool end;

    TrieNode() {
        freq = 0;
        children.assign(26, nullptr);
        end = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* iter = root;
        for (char c : word) {
            int idx = c - 'a';
            if (iter->children[idx] == nullptr) {
                iter->children[idx] = new TrieNode();
            }
            iter->children[idx]->freq++;
            iter = iter->children[idx];
        }
        iter->end = true;
    }
    
    vector<string> shortestUniquePrefix() {
        stack<pair<TrieNode*, string>> s;
        s.push({root, ""});

        vector<string> res;
        while (!s.empty()) {
            pair<TrieNode*, string> top = s.top();
            s.pop();

            for (int i=0; i<26; i++) {
                TrieNode* node = top.first->children[i];
                string str = top.second + (char)((int)'a' + i);
                if (node) {
                    if (node->freq == 1) {
                        res.push_back(str);
                    } else {
                        s.push({node, str});
                    }
                }
            }
        }
        return res;
    }
};

vector<string> shortestUniquePrefix(vector<string>& words) {
    Trie trie;
    for (string s : words) {
        trie.insert(s);
    }
    return trie.shortestUniquePrefix();
}

void print(vector<string>& A) {
    for (string& s : A) {
        cout << s << endl;
    }
}

int main() {
    vector<string> words = {"dog", "cat", "apple", "apricot", "fish"};
    vector<string> res = shortestUniquePrefix(words);
    print(res);
}
