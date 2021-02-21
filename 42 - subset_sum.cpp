/*
This problem was asked by Google.

Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. 
If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void print(vector<vector<bool>> A) {
    for (auto i : A) {
        for (bool j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// O(n*k); O(n*k)
bool subset_sum(vector<int> A, int K) {
    vector<vector<bool>> dp(A.size() + 1, vector<bool>(K + 1, false));
    for (int i=0; i<dp.size(); i++) {
        dp[i][0] = true;
    }
    for (int i=1; i<dp.size(); i++) {
        for (int j=1; j<dp[0].size(); j++) {
            if (A[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            }
        }
    }
    return dp.back().back();
}

int main() {
    cout << subset_sum({12, 1, 61, 5, 9, 2}, 24) << endl;
}