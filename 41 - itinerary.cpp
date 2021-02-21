/*
This problem was asked by Facebook.

Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, 
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. 
If there are multiple possible itineraries, return the lexicographically smallest one. 
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] 
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', 
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. 
However, the first one is lexicographically smaller.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(string s, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& map, vector<string>& res) {
    auto &curr = map[s];
    while (!curr.empty()) {
        string neighbour = curr.top();
        curr.pop();
        dfs(neighbour, map, res);
    }
    res.push_back(s);
}

vector<string> itinerary(vector<vector<string>> flights, string starting_point) {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
    for (auto flight : flights) {
        map[flight[0]].push(flight[1]);
    }
    vector<string> res;
    dfs(starting_point, map, res);
    reverse(res.begin(), res.end());
    return res;
}

void print(vector<string> A) {
    for (auto i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<string>> flighs = {
        {"A", "B"},
        {"A", "C"},
        {"B", "C"},
        {"C", "A"}
    };
    vector<string> res = itinerary(flighs, "A");
    print(res);
}