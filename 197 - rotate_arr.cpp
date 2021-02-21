/*
This problem was asked by Amazon.

Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// O(n); O(1)
void right_rotate(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

void print(vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    right_rotate(arr, 2);
    print(arr);
}