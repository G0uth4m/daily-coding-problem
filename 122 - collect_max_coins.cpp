/*
This question was asked by Zillow.

You are given a 2-d matrix where each cell represents number of coins in that cell. 
Assuming we start at matrix[0][0], and can only move right or down, 
find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

    0 3 1 1
    2 0 0 4
    1 5 3 1

The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*/

#include <iostream>
#include <vector>
using namespace std;

int max_coins(vector<vector<int>>& matrix) {
    for (int i=1; i<matrix.size(); i++) {
        matrix[i][0] += matrix[i - 1][0];
    }
    for (int j=1; j<matrix[0].size(); j++) {
        matrix[0][j] += matrix[0][j - 1];
    }
    for (int i=1; i<matrix.size(); i++) {
        for (int j=1; j<matrix[0].size(); j++) {
            matrix[i][j] += max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    return matrix.back().back();
}

int main() {
    vector<vector<int>> matrix = {
        {0, 3, 1, 1},
        {2, 0, 0, 4},
        {1, 5, 3, 1}
    };
    cout << max_coins(matrix) << endl;
}