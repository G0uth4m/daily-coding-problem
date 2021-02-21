/*
This problem was asked by Google.

Given an array of numbers and an index i, return the index of the nearest larger number of the number at index i, 
where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are equal, then return any one of them. 
If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n)
int nearest_larger(vector<int>& A, int i) {
    int left = i - 1;
    int right = i + 1;
    while (left >= 0 && right < A.size()) {
        if (A[left] > A[i]) {
            return left;
        }
        if (A[right] > A[i]) {
            return right;
        }
        left--;
        right++;
    }
    while (left >= 0) {
        if (A[left] > A[i]) {
            return left;
        }
        left--;
    }
    while (right < A.size()) {
        if (A[right] > A[i]) {
            return right;
        }
        right++;
    }
    return -1;
}

class Solution {
private:
    vector<int> processed;

    int __nearest_larger(vector<int>& A, int i) {
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < A.size()) {
            if (A[left] > A[i]) {
                return left;
            }
            if (A[right] > A[i]) {
                return right;
            }
            left--;
            right++;
        }
        while (left >= 0) {
            if (A[left] > A[i]) {
                return left;
            }
            left--;
        }
        while (right < A.size()) {
            if (A[right] > A[i]) {
                return right;
            }
            right++;
        }
        return -1;
    }

public:
    void preprocess(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            processed[i] = __nearest_larger(nums, i);
        }
    }

    int nearest_larger(int i) {
        return processed[i];
    }
};

int main() {
    vector<int> A = {4, 1, 3, 5, 6};
    cout << nearest_larger(A, 0) << endl;
}