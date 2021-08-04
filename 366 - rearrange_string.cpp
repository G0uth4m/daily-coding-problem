/*
This problem was asked by Flexport.

Given a string s, rearrange the characters so that any two adjacent characters are not the same. 
If this is not possible, return null.
Note : It may be assumed that the string has only lowercase English alphabets.

For example, if s = yyz then return yzy. If s = yyy then return null.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct CharFreq {
    char c;
    int freq;

    bool operator<(CharFreq const& charFreq) const {
        return freq < charFreq.freq;
    }
};

string rearrange(string s) {
    priority_queue<CharFreq, vector<CharFreq>, less<CharFreq>> maxHeap;
    vector<int> charSet(26);
    for (char c : s) {
        charSet[c - 'a']++;
    }

    for (int i=0; i<26; i++) {
        int freq = charSet[i];
        if (freq > 0) {
            CharFreq charFreq = {'a' + i, freq};
            maxHeap.push(charFreq);
        }
    }

    string res = "";
    CharFreq prev = {'a', -1};
    while (!maxHeap.empty()) {
        CharFreq curr = maxHeap.top();
        maxHeap.pop();
        res.push_back(curr.c);
        curr.freq--;
        if (prev.freq != -1 && prev.freq > 0) {
            maxHeap.push(prev);
        }
        prev = curr;
    }

    return res.size() == s.size() ? res : "";
}

int main() {
    cout << rearrange("aaabc") << endl;
    cout << rearrange("aaaabc") << endl;
    cout << rearrange("yyz") << endl;
}
