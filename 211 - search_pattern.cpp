/*
This problem was asked by Microsoft.

Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string. 
For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n*(m - n + 1 )); O(1)
vector<int> search(string txt, string pattern) {
    vector<int> res;
    for (int i=0; i<txt.size()-pattern.size()+1; i++) {
        if (txt.compare(i, pattern.size(), pattern) == 0) {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> preprocess(string& pattern) {
    vector<int> lps(pattern.size());
    int len = 0;
    int i = 1;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// O(m); O(n)
vector<int> search2(string txt, string pattern) {
    int i = 0;
    int j = 0;
    vector<int> res;
    vector<int> lps = preprocess(pattern);
    while (i < txt.size()) {
        if (txt[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == pattern.size()) {
            res.push_back(i - j);
            j = lps[j - 1];
        } else if (i < txt.size() && txt[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
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
    vector<int> res = search2("abracadabra", "abr");
    print(res);
}
