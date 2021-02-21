/*
This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, 
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_subarr_sum(vector<int> A) {
    for (int i=1; i<A.size(); i++) {
        A[i] = max(A[i - 1] + A[i], A[i]);
    }
    int to_return = *max_element(A.begin(), A.end());
    return to_return < 0 ? 0 : to_return;
}

int max_subarr_sum2(vector<int> A) {
    int curr = A[0];
    int res = curr;
    for (int i=1; i<A.size(); i++) {
        curr = max(curr + A[i], A[i]);
        res = max(res, curr);
    }
    return res;
}

int main() {
    cout << max_subarr_sum2({34, -50, 42, 14, -5, 86}) << endl;
    cout << max_subarr_sum2({-5, -1, -8, -9}) << endl;
}