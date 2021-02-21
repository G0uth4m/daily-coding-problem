/*
This problem was asked by Stripe.

Given a collection of intervals, find the minimum number of intervals you need 
to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as 
the last interval can be removed and the first two won't overlap.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numOverlapping(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    auto comp = [](pair<int, int>& interval1, pair<int, int>& interval2) {
        return interval1.second < interval2.second;
    };
    sort(intervals.begin(), intervals.end(), comp);
    int res = 0;
    int nonOverlappingSoFar = intervals[0].second;
    for (int i=1; i<intervals.size(); i++) {
        if (intervals[i].first < nonOverlappingSoFar) {
            res++;
        } else {
            nonOverlappingSoFar = intervals[i].second;
        }
    }
    return res;
}

int main() {
    vector<pair<int, int>> intervals = {{7, 9}, {2, 4}, {5, 8}};
    cout << numOverlapping(intervals) << endl;
}