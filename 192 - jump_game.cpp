/*
This problem was asked by Google.

You are given an array of nonnegative integers. Let's say you start at the beginning of the array 
and are trying to advance to the end. You can advance at most, the number of steps that you're currently on. 
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(nk); O(k)
bool canReachArrEndUtil(vector<int>& arr, int pos) {
    if (pos == arr.size() - 1) {
        return true;
    }
    if (arr[pos] == 0) {
        return false;
    }
    for (int i=1; i<=arr[pos]; i++) {
        if (canReachArrEndUtil(arr, pos + i)) {
            return true;
        }
    }
    return false;
}

bool canReachArrEnd(vector<int>& arr) {
    return canReachArrEndUtil(arr, 0);
}

// O(n); O(1)
bool canReachArrEnd2(vector<int>& arr) {
    int dest = 0;
    for (int i=0; i<arr.size(); i++) {
        if (i > dest) {
            return false;
        }
        dest = max(dest, i + arr[i]);
    }
    return true;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 1};
    cout << canReachArrEnd2(arr) << endl;

    vector<int> arr2 = {1, 2, 1, 0, 0};
    cout << canReachArrEnd2(arr2) << endl;
}