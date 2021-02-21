/*
This problem was asked by Amazon.

You are given a list of data entries that represent entries and exits of groups of people into a building. 

An entry looks like this:
{"timestamp": 1526579928, "count": 3, "type": "enter"}

This means 3 people entered the building. 

An exit looks like this:
{"timestamp": 1526580382, "count": 2, "type": "exit"}

This means that 2 people exited the building. timestamp is in Unix time.

Find the busiest period in the building, that is, the time with the most people in the building. 
Return it as a pair of (start, end) timestamps. 
You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DataEntry {
    int timestamp;
    int count;
    bool type;

    bool operator<(DataEntry& d1) const {
        return timestamp < d1.timestamp;
    }
};

// O(n); O(n)
pair<int, int> busiestPeriod(vector<DataEntry>& dataEntries) {
    sort(dataEntries.begin(), dataEntries.end());

    vector<int> prefixSum(dataEntries.size() + 1);
    for (int i=0; i<dataEntries.size(); i++) {
        prefixSum[i + 1] = prefixSum[i] + (dataEntries[i].type ? dataEntries[i].count : -dataEntries[i].count);
    }

    int maxIdx = max_element(prefixSum.begin(), prefixSum.end()) - prefixSum.begin();
    int endTime = dataEntries[maxIdx].timestamp;

    while (prefixSum[maxIdx] != 0) {
        maxIdx--;
    }
    int startTime = dataEntries[maxIdx].timestamp;
    
    return {startTime, endTime};
}

int main() {
    vector<DataEntry> dataEntries = {
        {1, 10, true},
        {3, 2, false},
        {5, 1, true},
        {6, 1, true},
        {7, 1, true},
        {9, 3, false},
        {10, 8, false}
    };

    pair<int, int> res = busiestPeriod(dataEntries);
    cout << "(" << res.first << ", " << res.second << ")" << endl;
}