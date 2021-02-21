/*
This problem was asked by Google.

Let M be an N by N matrix in which every row and every column is sorted. No two elements of M are equal.

Given i1, j1, i2, and j2, compute the number of elements of M smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers in the matrix smaller than 6 or greater than 23.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n log m)
int numWithinRange(vector<vector<int>>& A, int i1, int j1, int i2, int j2) {
    int num1 = A[i1][j1];
    int num2 = A[i2][j2];

    int res = 0;
    for (int i=0; i<A.size(); i++) {
        int idx1 = lower_bound(A[i].begin(), A[i].end(), num1) - A[i].begin();
        int idx2 = lower_bound(A[i].begin(), A[i].end(), num2) - A[i].begin();

        res += (idx1 + A[i].size() - idx2);
    }
    return res;
}

int main() {
    vector<vector<int>> A = {
        {1, 3, 7, 10, 15, 20},
        {2, 6, 9, 14, 22, 25},
        {3, 8, 10, 15, 25, 30},
        {10, 11, 12, 23, 30, 35},
        {20, 25, 30, 35, 40, 45}
    };

    cout << numWithinRange(A, 1, 1, 3, 3) << endl;
}