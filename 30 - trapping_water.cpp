/*
This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional elevation map 
where each element is unit-width wall and the integer is the height. 
Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, 
and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
*/
#include <iostream>
#include <vector>
using namespace std;

// O(N); O(N)
int trapped_water(vector<int> A) {
    vector<int> left_max(A.size());
    left_max[0] = A[0];
    for (int i=1; i<A.size(); i++) {
        if (A[i] > left_max[i - 1]) {
            left_max[i] = A[i];
        } else {
            left_max[i] = left_max[i - 1];
        }
    }

    vector<int> right_max(A.size());
    right_max[A.size() - 1] = A.back();
    for (int i=A.size()-2; i>=0; i--) {
        if (A[i] > right_max[i + 1]) {
            right_max[i] = A[i];
        } else {
            right_max[i] = right_max[i + 1];
        }
    }

    int trapped = 0;
    for (int i=0; i<A.size(); i++) {
        int temp = min(left_max[i], right_max[i]) - A[i];
        if (temp > 0) {
            trapped += temp;
        }
    }
    return trapped;
}

// O(n); O(1)
int trapped_water2(vector<int> height) {
    int left = 0;
    int right = height.size() - 1;
    int left_max = 0;
    int right_max = 0;
    int trapped = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                trapped += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                trapped += right_max - height[right];
            }
            right--;
        }
    }
    return trapped;
}

int main() {
    cout << trapped_water({3, 0, 1, 3, 0, 5}) << endl;
}