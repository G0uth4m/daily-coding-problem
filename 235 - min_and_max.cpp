/*
This problem was asked by Facebook.

Given an array of numbers of length N, find both the minimum and maximum using less than 2 * (N - 2) comparisons.
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> minAndMax(vector<int>& A) {
    pair<int, int> res;
    int i = 0;
    int n = A.size();
    if (n % 2 == 0) {
        if (A[0] > A[1]) {
            res = {A[0], A[1]};
        } else {
            res = {A[1], A[0]};
        }
        i = 2;
    } else {
        res = {A[0], A[0]};
        i = 1;
    }

    while (i < n - 1) {
        if (A[i] > A[i + 1]) {
            if (A[i] > res.first) {
                res.first = A[i];
            }
            if (A[i + 1] < res.second) {
                res.second = A[i + 1];
            }
        } else {
            if (A[i + 1] > res.first) {
                res.first = A[i + 1];
            }
            if (A[i] < res.second) {
                res.second = A[i];
            }
        }
        i += 2;
    }
    return res;
}

int main() {
    vector<int> A = {1000, 11, 445, 1, 330, 3000};
    pair<int, int> res = minAndMax(A);
    cout << res.first << " " << res.second << endl;
}