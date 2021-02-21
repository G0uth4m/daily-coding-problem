/*
This problem was asked by Facebook.

Given a circular array, compute its maximum subarray sum in O(n) time. 
A subarray can be empty, and in this case the sum is 0.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers 
3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int kandanesAlgo(vector<int>& A) {
    int curr = A[0];
    int res = curr;
    for (int i=1; i<A.size(); i++) {
        curr = max(curr + A[i], A[i]);
        res = max(res, curr);
    }
    return res;
}

void invertSign(vector<int>& A) {
    for (int& i : A) {
        i = -i;
    }
}

int maxSubArrSumCircular(vector<int>& A) {
    int res1 = kandanesAlgo(A);
    if (res1 < 0) {
        return res1;
    }
    int sum = accumulate(A.begin(), A.end(), 0);
    invertSign(A);
    int res2 = sum - kandanesAlgo(A);
    return max(res1, res2);
}