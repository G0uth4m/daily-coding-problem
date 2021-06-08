/*
This problem was asked by Sumo Logic.

Given a array that's sorted but rotated at some unknown pivot, 
in which all elements are distinct, find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both its left and right neighbors. 
It is guaranteed that the first and last elements are lower than all others.
*/

#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > A.back()) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return A[left - 1];
}

int main() {
    vector<int> A = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    cout << peak(A) << endl;
}
