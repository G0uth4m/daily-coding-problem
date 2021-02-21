/*
This problem was asked by Google.

You are given an array of arrays of integers, where each array corresponds to a row in a triangle of numbers. 
For example, [[1], [2, 3], [1, 5, 1]] represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down one row at a time to an adjacent value, 
eventually ending with an entry on the bottom row. 
For example, 1 -> 3 -> 5. The weight of the path is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_path_sum(vector<vector<int>>& triangle) {
    for (int i=1; i<triangle.size(); i++) {
        for (int j=0; j<triangle[i].size(); j++) {
            int right_above = 0;
            if (j < triangle[i - 1].size()) {
                right_above = triangle[i - 1][j];
            }
            int left_above = 0;
            if (j - 1 >= 0) {
                left_above = triangle[i - 1][j - 1];
            }
            triangle[i][j] += max(left_above, right_above);
        }
    }
    return *max_element(triangle.back().begin(), triangle.back().end());
}

int main() {
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {1, 5, 1}
    };
    cout << max_path_sum(triangle) << endl;
}