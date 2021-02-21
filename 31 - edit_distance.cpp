/*
This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and 
substitutions required to change one string to the other. 
For example, the edit distance between “kitten” and “sitting” is three: 
substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/
#include <iostream>
#include <vector>
using namespace std;

int edit_distance(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int c=0; c<dp[0].size(); c++) {
        dp[0][c] = c;
    }
    for (int r=0; r<dp.size(); r++) {
        dp[r][0] = r;
    }
    for (int r=1; r<dp.size(); r++) {
        for (int c=1; c<dp[0].size(); c++) {
            if (s1[r - 1] == s2[c - 1]) {
                dp[r][c] = dp[r - 1][c - 1];
            } else {
                dp[r][c] = 1 + min(dp[r - 1][c - 1], min(dp[r - 1][c], dp[r][c - 1]));
            }
        }
    }
    return dp.back().back();
}

int main() {
    cout << edit_distance("kitten", "sitting") << endl;
    cout << edit_distance("beer", "bears") << endl;
}