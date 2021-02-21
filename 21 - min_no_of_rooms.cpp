/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping),
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
};

int min_no_of_rooms(vector<Interval> intervals) {
    auto comp = [](Interval a, Interval b) {
        return a.end < b.end;
    };
    sort(intervals.begin(), intervals.end(), comp);

    vector<Interval> temp;
    int j = 0;
    for (int i=1; i<intervals.size(); i++) {
        if (intervals[i].start > intervals[j].end) {
            j = i;
        } else {
            temp.push_back(intervals[i]);
        }
    }

    int res = 1;
    while (temp.size() != 0) {
        int j = 0;
        vector<Interval> temp2;
        for (int i=1; i<temp.size(); i++) {
            if (temp[i].start >  temp[j].end) {
                j = i;
            } else {
                temp2.push_back(temp[i]);
            }
        }
        res++;
        temp = temp2;
    }
    return res;
}

int min_no_of_rooms2(vector<int> start, vector<int> end) {
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int rooms_needed = 1;
    int min_rooms_needed = 1;
    int i = 1;
    int j = 0;

    while (i < start.size() && j < end.size()) {
        if (start[i] <= end[j]) {
            rooms_needed++;
            i++;
        } else if (start[i] > end[j]) {
            rooms_needed--;
            j++;
        }
        min_rooms_needed = max(min_rooms_needed, rooms_needed);
    }
    return min_rooms_needed;
}

int main() {
    vector<Interval> intervals = {
        {30, 75},
        {0, 50},
        {60, 150}
    };
    cout << min_no_of_rooms(intervals) << endl;

    vector<int> start = {30, 0, 60};
    vector<int> end = {75, 50, 150};
    cout << min_no_of_rooms2(start, end) << endl;
}