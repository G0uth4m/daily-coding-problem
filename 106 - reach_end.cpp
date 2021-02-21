/*
Given an integer list where each number represents the number of hops you can make, 
determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns true while [1, 1, 0, 1] returns false.
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<bool>& A) {
    for (bool i : A) {
        cout << i << " ";
    }
    cout << endl;
}

// O(n ^ 2)
bool can_reach_end(vector<int>& A) {
    vector<bool> dp(A.size(), false);
    dp[0] = true;
    for (int i=1; i<dp.size(); i++) {
        for (int j=i-1; j>=0; j--) {
            if (dp[j] && A[j] >= i - j) {
                dp[i] = true;
                break;
            }
        }
    }
    print(dp);
    return dp.back();
}

// O(n)
bool can_reach_end2(vector<int>& A) {
    int curr_reachable_idx = 0;
    for (int i=0; i<A.size(); i++) {
        if (i > curr_reachable_idx) {
            return false;
        }
        curr_reachable_idx = max(curr_reachable_idx, i + A[i]);
    }
    return true;
}

int main() {
    vector<int> A = {2, 0, 1, 0};
    cout << can_reach_end2(A) << endl;
}