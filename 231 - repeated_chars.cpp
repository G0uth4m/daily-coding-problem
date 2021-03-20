/*
This problem was asked by IBM.

Given a string with repeated characters, 
rearrange the string so that no two adjacent characters are the same. 
If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". 
Given "aaab", return None.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n); O(1)
string rearrange(string s) {
    vector<int> set(26);
    for (char c : s) {
        set[c - 'a']++;
    }
    string res = "";
    for (int i=0; i<s.size(); i++) {
        int maxFreq = 0;
        int maxChar = -1;
        for (int j=0; j<26; j++) {
            if (set[j] > maxFreq && (res.empty() || res.back() != 'a' + j)) {
                maxFreq = set[j];
                maxChar = j;
            }
        }
        if (maxChar == -1) {
            return "";
        }
        set[maxChar]--;
        res.push_back(maxChar + 'a');
    }
    return res;
}

int main() {
    cout << rearrange("aaabbc") << endl;
    cout << rearrange("aaab") << endl;
    cout << rearrange("vvvlo") << endl;
}
