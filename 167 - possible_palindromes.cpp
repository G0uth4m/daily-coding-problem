/*
This problem was asked by Airbnb.

Given a list of words, find all pairs of unique indices such that the concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        if (s[left++] != s[right--]) {
            return false;
        }
    }
    return true;
}

// O(n^2 k);
vector<pair<int, int>> possiblePalindromes(vector<string>& words) {
    vector<pair<int, int>> res;
    for (int i=0; i<words.size(); i++) {
        for (int j=0; j<words.size(); j++) {
            if (i != j && isPalindrome(words[i] + words[j])) {
                res.push_back({i, j});
            }
        }
    }
    return res;
}

void print(vector<pair<int, int>>& A) {
    for (pair<int, int>& i : A) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    vector<string> words = {"code", "edoc", "da", "d"};
    vector<pair<int, int>> res = possiblePalindromes(words);
    print(res);
}