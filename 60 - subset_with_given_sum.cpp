/*
This problem was asked by Facebook.

Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, 
since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, 
since we can't split it up into two subsets that add up to the same sum.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// O(N*M); O(N*M)
bool has_subset(vector<int> A, int sum) {
    vector<vector<bool>> dp(A.size() + 1, vector<bool>(sum + 1, false));
    for (int i=0; i<dp.size(); i++) {
        dp[i][0] = true;
    }
    for (int i=1; i<dp.size(); i++) {
        for (int j=1; j<dp[0].size(); j++) {
            if (j >= A[i - 1]) {
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            }
        }
    }
    return dp.back().back();
}

bool can_partition(vector<int> A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 2 == 1) {
        return false;
    }
    return has_subset(A, sum/2);
}

int main() {
    cout << can_partition({15, 5, 20, 10, 35, 15, 10}) << endl;
}