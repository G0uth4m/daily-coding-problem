/*
This problem was asked by Apple.

A fixed point in an array is an element whose value is equal to its index. 
Given a sorted array of distinct elements, return a fixed point, if one exists. Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2. Given [1, 5, 7, 8], you should return False.
*/

#include <iostream>
#include <vector>
using namespace std;

int fixedPoint(vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == mid) {
            return mid;
        } else if (A[mid] > mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> A = {-6, 0, 2, 40};
    cout << fixedPoint(A) << endl;
    A = {1, 5, 6, 8};
    cout << fixedPoint(A) << endl;
}
