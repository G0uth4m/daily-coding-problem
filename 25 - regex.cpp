/*
This problem was asked by Facebook.

Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression 
and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", 
your function should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. 
The same regular expression on the string "chats" should return false.
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<bool>> A) {
    for (auto i : A) {
        for (bool j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool regex_match(string text, string pattern) {
    vector<vector<bool>> dp(text.size() + 1, vector<bool>(pattern.size() + 1, false));
    dp[0][0] = true;

    for (int j=1; j<=pattern.size(); j++) {
        if (pattern[j - 1] != '*') {
            dp[0][j] = false;
        } else {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i=1; i<=text.size(); i++) {
        for(int j=1; j<=pattern.size(); j++) {
            if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (text[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp.back().back();
}

int main() {
    cout << regex_match("xaabyc", "xa*b.c") << endl;
    cout << regex_match("c", "a*b*c") << endl;
}