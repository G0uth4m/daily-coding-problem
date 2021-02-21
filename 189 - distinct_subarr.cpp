/*
This problem was asked by Google.

Given an array of elements, return the length of the longest subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// O(n); O(n)
int lds(vector<int>& A) {
    int left = 0;
    int right = 0;
    int res = 0;
    unordered_set<int> set;
    while (right < A.size()) {
        if (set.find(A[right]) != set.end()) {
            res = max(right - left, res);
            while (A[left] != A[right]) {
                set.erase(A[left]);
                left++;
            }
            set.erase(A[left]);
            left++;
        } else {
            set.insert(A[right]);
            right++;
        }
    }
    return max(right - left, res);
}

// O(n); O(n)
int lds2(vector<int>& A) {
    int left = 0;
    int right = 0;
    int res = 0;
    unordered_set<int> set;
    while (right < A.size()) {
        if (set.find(A[right]) == set.end()) {
            set.insert(A[right++]);
            res = max(res, right - left);
        } else {
            set.erase(A[left++]);
        }
    }
    return res;
}

int main() {
    vector<int> A = {5, 1, 3, 5, 2, 3, 4, 1};
    cout << lds2(A) << endl;
}