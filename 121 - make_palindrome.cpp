/*
This problem was asked by Google.

Given a string which we can delete at most k, return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
*/

#include <iostream>
#include <vector>
using namespace std;

int longest_palindromic_subsequence(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i=0; i<dp.size(); i++) {
        dp[i][i] = 1;
    }
    for (int c1=2; c1<=s.size(); c1++) {
        for (int i=0; i<s.size()-c1+1; i++) {
            int j = i + c1 - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0].back();
}

bool canMakePalindrome(string s, int k) {
    int lps = longest_palindromic_subsequence(s);
    return s.size() - lps <= k;
}

int main() {
    cout << canMakePalindrome("waterrfetawx", 2) << endl;
}