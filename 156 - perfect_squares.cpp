/*
This problem was asked by Facebook.

Given a positive integer n, find the smallest number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 3^2 + 2^2 = 9 + 4.

Given n = 27, return 3 since 27 = 3^2 + 3^2 + 3^2 = 9 + 9 + 9.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n^(3/2))
int num_squares(int N) {
    if (N <= 3) {
        return N;
    }
    vector<int> dp(N + 1, INT32_MAX);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i=4; i<=N; i++) {
        for (int j=1; j*j<=i; j++) {
            dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
    }
    return dp.back();
}

int main() {
    cout << num_squares(13) << endl;
    cout << num_squares(27) << endl;
}