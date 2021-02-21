/*
This problem was asked by Amazon.

Given a string, find the longest palindromic contiguous substring. 
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". 
The longest palindromic substring of "bananas" is "anana".
*/

#include <iostream>
#include <vector>
using namespace std;

string longest_palindromic_substring(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    for (int i=0; i<dp.size(); i++) {
        dp[i][i] = true;
    }

    int max_i = 0;
    int max_j = 0;
    for (int c1=2; c1<=s.size(); c1++) {
        for (int i=0; i<s.size()-c1+1; i++) {
            int j = i + c1 - 1;
            dp[i][j] = s[i] == s[j] && (c1 == 2 || dp[i + 1][j - 1]);
            if (dp[i][j] && (j - i) > (max_j - max_i)) {
                max_i = i;
                max_j = j;
            }
        }
    }
    return s.substr(max_i, max_j - max_i + 1);
}

int main() {
    cout << longest_palindromic_substring("aabcdcb") << endl;
    cout << longest_palindromic_substring("bananas") << endl;
}