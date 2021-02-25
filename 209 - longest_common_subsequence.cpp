/*
This problem was asked by YouTube.

Write a program that computes the length of the longest common subsequence of three given strings. 
For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious", it should return 5, 
since the longest common subsequence is "eieio".
*/

#include <iostream>
#include <vector>
using namespace std;

// O(a*b*c); O(a*b*c)
int lcs(string s1, string s2, string s3) {
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1)));
    
    for (int i=1; i<dp.size(); i++) {
        for (int j=1; j<dp[0].size(); j++) {
            for (int k=1; k<dp[0][0].size(); k++) {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                } else {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return dp.back().back().back();
}

int main() {
    cout << lcs("epidemiologist", "refrigeration", "supercalifragilisticexpialodocious") << endl;
}
