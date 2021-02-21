/*
This problem was asked by Google.

Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
*/

#include <iostream>
#include <vector>
using namespace std;

int min_coins(vector<int>& coins, int n) {
    vector<int> dp(n + 1, 0);
    for (int i=1; i<dp.size(); i++) {
        int mini = INT32_MAX;
        for (int j=0; j<coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                mini = min(mini, 1 + dp[i - coins[j]]);
            }
        }
        if (mini == INT32_MAX) {
            dp[i] = -1;
        } else {
            dp[i] = mini;
        }
    }
    return dp.back();
}

int main() {
    vector<int> coins = {1, 5, 10, 25};
    cout << min_coins(coins, 16) << endl;
}