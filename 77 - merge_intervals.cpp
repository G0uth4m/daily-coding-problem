/*
This problem was asked by Snapchat.

Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n log n)
vector<pair<int, int>> merge_intervals(vector<pair<int, int>> intervals) {
    auto comp = [](pair<int, int>& A, pair<int, int>& B) {
        return A.first == B.first ? A.second < B.second : A.first < B.first;
    };

    sort(intervals.begin(), intervals.end(), comp);

    vector<pair<int, int>> res = {intervals[0]};

    for (int i=1; i<intervals.size(); i++) {
        if (intervals[i].first <= res.back().second) {
            res.back().second = max(res.back().second, intervals[i].second);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

void print(vector<pair<int, int>> A) {
    for (auto i : A) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    vector<pair<int, int>> A = {{1, 3}, {5, 8}, {4, 10}, {20, 25}};
    vector<pair<int, int>> res = merge_intervals(A);
    print(res);
}