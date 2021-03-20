/*
This problem was asked by Google.

Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.

For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool end;
    int count;

    TrieNode() {
        children.assign(26, nullptr);
        end = false;
        count = 0;
    }
};

class PrefixMapSum {
private:
    TrieNode* root;
    unordered_map<string, int> map;
public:
    PrefixMapSum() {
        root = new TrieNode();
    }

    void insert(string key, int value) {
        TrieNode* iter = root;
        int delta = value;
        if (map.find(key) != map.end()) {
            delta -= map[key];
        }
        map[key] = value;
        for (char c : key) {
            int idx = c - 'a';
            if (iter->children[idx] == nullptr) {
                iter->children[idx] = new TrieNode();
            }
            iter = iter->children[idx];
            iter->count += delta;
        }
        iter->end = true;
    }

    int sum(string prefix) {
        TrieNode* iter = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (iter->children[idx] == nullptr) {
                return 0;
            }
            iter = iter->children[idx];
        }
        return iter->count;
    }
};

int main() {
    PrefixMapSum prefixMapSum;
    prefixMapSum.insert("columnar", 3);
    cout << prefixMapSum.sum("col") << endl;
    prefixMapSum.insert("column", 2);
    cout << prefixMapSum.sum("column") << endl;

    prefixMapSum.insert("columnar", 4);
    cout << prefixMapSum.sum("col") << endl;
    prefixMapSum.insert("column", 10);
    cout << prefixMapSum.sum("column") << endl;
}
