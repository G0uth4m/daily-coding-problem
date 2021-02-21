/*
This problem was asked by Amazon.

Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(log(max(a, b)))
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// O(n log m) - m = smallest el in A
int gcdOfArr(vector<int>& A) {
    int res = A[0];
    for (int i=1; i<A.size(); i++) {
        res = gcd(res, A[i]);
        if (res == 1) {
            return 1;
        }
    }
    return res;
}

int main() {
    vector<int> A = {42, 56, 14};
    cout << gcdOfArr(A) << endl;
}