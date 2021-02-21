/*
This problem was asked by Stripe.

Write a map implementation with a get function that lets you retrieve the value of a key at a particular time.

It should contain the following methods:

    set(key, value, time): # sets key to value for t = time.
    get(key, time): # gets the key at t = time.

The map should work like this. If we set a key at a particular time, 
it will maintain that value forever or until it gets set at a later time. 
In other words, when we get a key at a time, it should return the value 
that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2

d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class MapWithTime {
private:
    unordered_map<int, vector<pair<int, int>>> map;

    void _insert_to_sorted(vector<pair<int, int>>& A, pair<int, int> p) {
        int i = 0;
        while (i < A.size() && A[i].second < p.second) {
            i++;
        }
        if (!A.empty() && A[i].second == p.second) {
            A[i] = p;
        } else {
            A.insert(A.begin() + i, p);
        }
    }

public:
    void set(int key, int val, int time) {
        _insert_to_sorted(map[key], {val, time});
    }

    int get(int key, int time) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        auto comp = [](pair<int, int> A, pair<int, int> B) {
            return A.second < B.second;
        };
        pair<int, int> p = {0, time};
        int idx = lower_bound(map[key].begin(), map[key].end(), p, comp) - map[key].begin();
        if (idx >= map[key].size()) {
            return map[key][idx - 1].first;
        }
        if (map[key][idx].second == time) {
            return map[key][idx].first;
        }
        if (idx == 0) {
            return -1;
        }
        return map[key][idx - 1].first;
    }
};

int main() {
    MapWithTime map;
    // map.set(1, 1, 0);
    // map.set(1, 2, 2);
    // cout << map.get(1, 1) << endl;
    // cout << map.get(1, 3) << endl;

    // map.set(1, 1, 5);
    // cout << map.get(1, 0) << endl;
    // cout << map.get(1, 10) << endl;

    map.set(1, 1, 0);
    map.set(1, 2, 0);
    cout << map.get(1, 0) << endl;
}