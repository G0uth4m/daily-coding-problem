/*
This problem was asked by Facebook.

There is an N by M matrix of zeroes. Given N and M, write a function to count the 
number of ways of starting at the top-left corner and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:
> Right, then down
> Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

#include <iostream>
#include <vector>
using namespace std;

int num_paths(int N, int M) {
    vector<vector<int>> dp(N, vector<int>(M, 0));
    for (int j=0; j<dp[0].size(); j++) {
        dp[0][j] = 1;
    }
    for (int i=0; i<dp.size(); i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<dp.size(); i++) {
        for (int j=1; j<dp[0].size(); j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp.back().back();
}

int main() {
    cout << num_paths(5, 5) << endl;
}