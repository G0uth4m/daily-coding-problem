/*
This problem was asked by Square.

In front of you is a row of N coins, with values v1, v1, ..., vn.

You are asked to play the following game. 
You and an opponent take turns choosing either the first or last coin from the row, 
removing it from the row, and receiving the value of the coin.

Write a program that returns the maximum amount of money you can win with certainty, 
if you move first, assuming your opponent plays optimally.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n^2); O(n^2)
int maxWinAmount(vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(coins.size()));

    for (int gap=0; gap<coins.size(); gap++) {
        for (int i=0, j=gap; j<coins.size(); i++, j++) {
            int x = i + 2 <= j ? dp[i + 2][j] : 0;
            int y = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0;
            int z = i <= j - 2 ? dp[i][j - 2] : 0;
            dp[i][j] = max(coins[i] + min(x, y), coins[j] + min(y, z));
        }
    }
    return dp[0].back();
}

int main() {
    vector<int> coins = {1, 5, 233, 7};
    cout << maxWinAmount(coins) << endl;
}