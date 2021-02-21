/*
This problem was asked by Microsoft.

Given an array of numbers, find the length of the longest increasing subsequence in the array. 
The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], 
the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(vector<int> A) {
    vector<int> dp(A.size(), 1);
    for (int i=1; i<A.size(); i++) {
        for (int j=0; j<i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    cout << lis({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}) << endl;
}