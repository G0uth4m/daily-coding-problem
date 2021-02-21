/*
This problem was asked by Google.

Given a word W and a string S, find all starting indices in S which are anagrams of W.

For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.
*/

#include <iostream>
#include <vector>
using namespace std;

bool is_anagram(string w, string s, int j) {
    vector<int> char_set(26, 0);
    for (int i=0; i<w.size(); i++, j++) {
        char_set[w[i] - 'a']++;
        char_set[s[j] - 'a']--;
    }
    for (int i : char_set) {
        if (i != 0) {
            return false;
        }
    }
    return true;
}

// O(sw); O(1)
vector<int> all_anagrams(string w, string s) {
    vector<int> res;
    for (int i=0; i<=s.size()-w.size(); i++) {
        if (is_anagram(w, s, i)) {
            res.push_back(i);
        }
    }
    return res;
}

// O(s); O(1)
vector<int> all_anagrams2(string w, string s) {
    if (s.size() < w.size()) {
        return {};
    }

    vector<int> w_hash(26, 0);
    vector<int> s_hash(26, 0);
    vector<int> res;

    for (int i=0; i<w.size(); i++) {
        w_hash[w[i] - 'a']++;
        s_hash[s[i] - 'a']++;
    }

    if (w_hash == s_hash) {
        res.push_back(0);
    }

    for (int i=w.size(); i<s.size(); i++) {
        s_hash[s[i - w.size()] - 'a']--;
        s_hash[s[i] - 'a']++;
        if (s_hash == w_hash) {
            res.push_back(i - w.size() + 1);
        }
    }
    
    return res;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> res = all_anagrams2("ab", "abxaba");
    print(res);
}