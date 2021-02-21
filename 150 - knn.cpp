/*
This problem was asked by LinkedIn.

Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// O(n + (k log n))
vector<pair<int, int>> knn(vector<pair<int, int>>& points, pair<int, int> centre, int k) {
    auto comp = [](pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
    for (int i=0; i<points.size(); i++) {
        int dist = pow(centre.second - points[i].second, 2) + pow(centre.first - points[i].first, 2);
        min_heap.push({i, dist});
    }
    vector<pair<int, int>> res(k);
    for (int i=0; i<k; i++) {
        res[i] = points[min_heap.top().first];
        min_heap.pop();
    }
    return res;
}

void print(vector<pair<int, int>>& A) {
    for (pair<int, int>& p : A) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    vector<pair<int, int>> points = {{0, 0}, {5, 4}, {3, 1}};
    vector<pair<int, int>> res = knn(points, {1, 2}, 2);
    print(res);
}