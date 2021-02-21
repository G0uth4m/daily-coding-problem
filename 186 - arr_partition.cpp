/*
This problem was asked by Microsoft.

Given an array of positive integers, divide the array into two subsets such that 
the difference between the sum of the subsets is as small as possible.

For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20}, 
which has a difference of 5, which is the smallest possible difference.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

void helper(vector<int>& arr, pair<unordered_set<int>, unordered_set<int>>& res, int& diffRes, unordered_set<int> A, unordered_set<int> B, int sum1, int sum2, int start) {
    if (start == arr.size()) {
        return;
    }
    int diff = abs(sum1 - sum2);
    if (diff < diffRes) {
        diffRes = diff;
        res = {A, B};
    }
    helper(arr, res, diffRes, A, B, sum1, sum2, start + 1);
    B.erase(arr[start]);
    A.insert(arr[start]);
    helper(arr, res, diffRes, A, B, sum1 + arr[start], sum2 - arr[start], start + 1);
}

pair<unordered_set<int>, unordered_set<int>> partition(vector<int>& A) {
    pair<unordered_set<int>, unordered_set<int>> res;
    int diffRes = INT32_MAX;
    unordered_set<int> B(A.begin(), A.end());
    helper(A, res, diffRes, {}, B, 0, accumulate(A.begin(), A.end(), 0), 0);
    return res;
}

void print(unordered_set<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {5, 10, 15, 20, 25};
    pair<unordered_set<int>, unordered_set<int>> res = partition(A);
    print(res.first);
    print(res.second);
}