/*
This problem was asked by Google.

Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
and

{
    "top_left": (0, 5),
    "dimensions" (4, 3) # width, height
}
return 6.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

int areaOfIntersection(Point l1, Point r1, Point l2, Point r2) {
    int x_dist = min(r1.x, r2.x) - max(l1.x, l2.x);
    int y_dist = min(r1.y, r2.y) - max(l1.y, l2.y);

    return x_dist * y_dist;
}

int main() {
    cout << areaOfIntersection({1, 1}, {4, 4}, {0, 2}, {4, 5}) << endl;
}