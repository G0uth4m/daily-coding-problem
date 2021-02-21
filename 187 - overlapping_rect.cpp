/*
This problem was asked by Google.

You are given given a list of rectangles represented by min and max x- and y-coordinates. Compute whether or not a pair of rectangles overlap each other. If one rectangle completely covers another, it is considered overlapping.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point topRight;
    Point bottomLeft;
};

bool isOverlapping(Rectangle r1, Rectangle r2) {
    int x_dist = min(r1.topRight.x, r2.topRight.x) - max(r1.bottomLeft.x, r2.bottomLeft.x);
    int y_dist = min(r1.topRight.y, r2.topRight.y) - max(r1.bottomLeft.y, r2.bottomLeft.y);

    return x_dist > 0 && y_dist > 0;
}

bool isAnyOverlapping(vector<Rectangle>& rectangles) {
    for (int i=0; i<rectangles.size(); i++) {
        for (int j=i+1; j<rectangles.size(); j++) {
            if (isOverlapping(rectangles[i], rectangles[j])) {
                return true;
            }
        }
    }
    return false;
}