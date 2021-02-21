/*
This problem was asked by Facebook.

Given an array of integers, write a function to determine whether 
the array could become non-decreasing by modifying at most 1 element.

For example, given the array [10, 5, 7], you should return true, 
since we can modify the 10 into a 1 to make the array non-decreasing.

Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.
*/

#include <iostream>
#include <vector>
using namespace std;

bool can_make_non_decreasing(vector<int> A) {
    bool flag = false;
    for (int i=0; i<A.size()-1; i++) {
        if (A[i] > A[i + 1]) {
            if (flag) {
                return false;
            }
            flag = true;
        }
    }
    return true;
}

int main() {
    cout << can_make_non_decreasing({10, 5, 7}) << endl;
}