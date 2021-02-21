/*
This problem was asked by Uber.

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. 
Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3
*/

#include <iostream>
#include <vector>
using namespace std;

int min(vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left)/2;
        if (A[mid] > A.back()) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return A[left];
}

int main() {
    vector<int> A = {5, 7, 10, 3, 4};
    cout << min(A) << endl;
}