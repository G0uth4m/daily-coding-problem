/*
This problem was asked by Amazon.

An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. 
If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int> A, int num, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (A[mid] == num) {
            return mid;
        } else if (A[mid] > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int search(vector<int> A, int num) {
    int i = 0;
    int j = A.size() - 1;
    while (i < j) {
        int m = i + (j - i)/2;
        if (A[m] > A.back()) {
            i = m + 1;
        } else {
            j = m;
        }
    }
    if (num >= A[j] && num <= A.back()) {
        return bin_search(A, num, j, A.size() - 1);
    }
    return bin_search(A, num, 0, j - 1);
}

int main() {
    cout << search({13, 18, 25, 2, 8, 10}, 8) << endl;
}