/*
This problem was asked by Slack.

You are given an N * M matrix of 0s and 1s. Starting from the top left corner, 
how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]

Return 2, as there are only two ways to get to the bottom right:

Right, down, down, right
Down, right, down, right

The top left corner and bottom right corner will always be 0.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n); O(1)
int num_ways(vector<vector<int>>& matrix) {
    int i = 0;
    while (i < matrix.size()) {
        if (matrix[i][0] == 1) {
            break;
        }
        matrix[i][0] = 1;
        i++;
    }

    while (i < matrix.size()) {
        matrix[i][0] = 0;
        i++;
    }

    int j = 0;
    while (j < matrix[0].size()) {
        if (matrix[0][j] == 1) {
            break;
        }
        matrix[0][j] = 1;
        j++;
    }

    while (j < matrix[0].size()) {
        matrix[0][j] = 0;
        j++;
    }
    
    for (int i=1; i<matrix.size(); i++) {
        for (int j=1; j<matrix[0].size(); j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
    }
    return matrix.back().back();
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 0, 0}
    };
    cout << num_ways(matrix) << endl;
}