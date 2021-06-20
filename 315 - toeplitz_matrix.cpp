/*
This problem was asked by Google.

In linear algebra, a Toeplitz matrix is one in which the elements 
on any given diagonal from top left to bottom right are identical.

Here is an example:

1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2

Write a program to determine whether a given input is a Toeplitz matrix.
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

bool isUnivalDiagnol(vector<vector<int>>& matrix, int row, int col) {
    int i = row;
    int j = col;

    while (i + 1 < matrix.size() && j + 1 < matrix[0].size()) {
        if (matrix[i][j] != matrix[i + 1][j + 1]) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for (int i=0; i<matrix.size(); i++) {
        if (!isUnivalDiagnol(matrix, i, 0)) {
            return false;
        }
    }

    for (int j=0; j<matrix[0].size(); j++) {
        if (!isUnivalDiagnol(matrix, 0, j)) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 8},
        {5, 1, 2, 3, 4},
        {4, 5, 1, 2, 3},
        {7, 4, 5, 1, 2}
    };

    assert(isToeplitzMatrix(matrix) == true);
    matrix[1][2] = 10;
    assert(isToeplitzMatrix(matrix) == false);
}
