/*
This question was asked by Google.

Given an integer n and a list of integers l, write a function 
that randomly generates a number from 0 to n-1 that isn't in l (uniform).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(vector<int>& l, int n) {
    int r = rand() % n;
    if (lower_bound(l.begin(), l.end(), r) != l.end()) {
        return helper(l, n);
    }
    return r;
}

int random_num(vector<int>& l, int n) {
    sort(l.begin(), l.end());
    return helper(l, n);
}
