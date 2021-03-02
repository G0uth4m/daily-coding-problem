/*
This problem was asked by Stripe.

Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveSetBits(int n) {
    int maxConsecutive = INT32_MIN;
    int currConsecutive = 0;
    while (n) {
        if (n & 1) {
            currConsecutive++;
        } else {
            maxConsecutive = max(maxConsecutive, currConsecutive);
            currConsecutive = 0;
        }
        n >>= 1;
    }
    return max(maxConsecutive, currConsecutive);
}

int main() {
    cout << maxConsecutiveSetBits(156) << endl;
    cout << maxConsecutiveSetBits(30) << endl;
    cout << maxConsecutiveSetBits(31) << endl;
}