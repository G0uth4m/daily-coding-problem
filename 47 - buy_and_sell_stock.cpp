/*
This problem was asked by Facebook.

Given a array of numbers representing the stock prices of a company in chronological order, 
write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, 
since you could buy the stock at 5 dollars and sell it at 10 dollars.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(N^2)
int max_profit(vector<int> stocks) {
    int res = 0;
    for (int i=0; i<stocks.size(); i++) {
        for (int j=i+1; j<stocks.size(); j++) {
            res = max(res, stocks[j] - stocks[i]);
        }
    }
    return res;
}

// O(N)
int max_profit2(vector<int> stocks) {
    int mini = INT32_MAX;
    int res = 0;
    for (int i=0; i<stocks.size(); i++) {
        if (stocks[i] < mini) {
            mini = stocks[i];
        } else {
            res = max(res, stocks[i] - mini);
        }
    }
    return res;
}

int main() {
    cout << max_profit2({9, 11, 8, 5, 7, 10}) << endl;
}