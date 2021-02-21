/*
This problem was asked by Google.

Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. 
If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], 
one set of numbers that covers all these intervals is {3, 6}.
- - - -
    - - - - -
      - -
            - - - -
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void backtrack(vector<pair<int, int>>& intervals, int start, unordered_set<int>& res, unordered_set<int> temp) {
    if (start == intervals.size()) {
        if (res.empty() || temp.size() < res.size()) {
            res = temp;
        }
    }
    for (int i=intervals[start].first; i<=intervals[start].second; i++) {
        temp.insert(i);
        backtrack(intervals, start + 1, res, temp);
        temp.erase(i);
    }
}

// O(m^n); m = length of interval; n = no. of intervals
unordered_set<int> cover_intervals(vector<pair<int, int>>& intervals) {
    unordered_set<int> res;
    backtrack(intervals, 0, res, {});
    return res;
}

void print(unordered_set<int>& A) {
    for (auto i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<pair<int, int>> intervals = {{0, 3}, {2, 6}, {3, 4}, {6, 9}};
    unordered_set<int> res = cover_intervals(intervals);
    print(res);
}