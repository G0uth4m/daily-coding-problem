/*
This problem was asked by Microsoft.

Given an array of numbers and a number k, determine if there are 
three entries in the array which add up to the specified number k. 
For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n^2)
bool threeSum(vector<int>& A, int target) {
    sort(A.begin(), A.end());
    for (int i=0; i<A.size(); i++) {
        int left = i + 1;
        int right = A.size() - 1;

        while (left < right) {
            int sum = A[i] + A[left] + A[right];
            if (sum == target) {
                return true;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return false;
}

int main() {
    vector<int> A = {20, 303, 3, 4, 25};
    cout << threeSum(A, 49) << endl;
}
