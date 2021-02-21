/*
This problem was asked by Facebook.

Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0 
and the other list q1, q2, ..., qn on the line y = 1. 
Imagine a set of n line segments connecting each point pi to qi. 
Write an algorithm to determine how many pairs of the line segments intersect.
&/
*/

#include <iostream>
#include <vector>
using namespace std;

bool isIntersecting(pair<int, int>& line1, pair<int, int>& line2) {
    return !((line1.first > line2.first && line1.second > line2.second)
        || (line1.first < line2.first && line1.second < line2.second));
}

int numIntersectingPairs(vector<int>& p, vector<int>& q) {
    int res = 0;
    for (int i=0; i<p.size(); i++) {
        for (int j=i+1; j<p.size(); j++) {
            pair<int, int> line1 = {p[i], q[i]};
            pair<int, int> line2 = {p[j], q[j]};
            if (isIntersecting(line1, line2)) {
                res++;
            }
        }
    }
    return res;
}