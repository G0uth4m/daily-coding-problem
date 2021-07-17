/*
This problem was asked by Google.

Given a set of points (x, y) on a 2D cartesian plane, find the two closest points. 
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)], 
return [(-1, -1), (1, 1)].
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<pair<int, int>, pair<int, int>> closestPoints(vector<pair<int, int>>& points) {
    int minDist = INT32_MAX;
    pair<pair<int, int>, pair<int, int>> res;

    for (int i=0; i<points.size(); i++) {
        for (int j=i+1; j<points.size(); j++) {
            int d = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
            if (d < minDist) {
                minDist = d;
                res = {points[i], points[j]};
            }
        }
    }
    return res;
}

int main() {
    vector<pair<int, int>> points = {
        {1, 1},
        {-1, -1},
        {3, 4},
        {6, 1},
        {-1, -6},
        {-4, -3}
    };
    pair<pair<int, int>, pair<int, int>> res = closestPoints(points);
    cout << res.first.first << " " << res.first.second << endl;
    cout << res.second.first << " " << res.second.second << endl;
}
