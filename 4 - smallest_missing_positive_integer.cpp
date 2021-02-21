/*
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in
linear time and constant space. In other words, find the lowest positive
integer that does not exist in the array. The array can contain
duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// O(n); O(n)
int missing_positive_integer(vector<int> nums) {
    unordered_set<int> int_set;
    for (int i : nums) {
        int_set.insert(i);
    }
    for (int i=1; i<=nums.size(); i++) {
        if (int_set.find(i) == int_set.end()) {
            return i;
        }
    }
    return nums.size() + 1;
}

// O(n)
int missing_positive_integer2(vector<int> nums) {
    for (int i=0; i<nums.size(); i++) {
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main() {
    vector<int> A = {3, 4, -1, 1};
    cout << missing_positive_integer2(A) << endl;
}