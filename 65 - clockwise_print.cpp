/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]

You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
*/

#include <iostream>
#include <vector>
using namespace std;

void print_layer(vector<vector<int>>& matrix, int layer) {
    for (int j=layer; j<matrix[0].size()-layer-1; j++) {
        cout << matrix[layer][j] << endl;
    }
    for (int i=layer; i<matrix.size()-layer-1; i++) {
        cout << matrix[i][matrix[0].size() - layer - 1] << endl;
    }
    for (int j=matrix[0].size()-layer-1; j >= layer + 1; j--) {
        cout << matrix[matrix.size() - layer - 1][j] << endl;
    }
    for (int i=matrix.size()-layer-1; i>=layer+1; i--) {
        cout << matrix[i][layer] << endl;
    }
}

void print_clockwise(vector<vector<int>>& matrix) {
    for (int layer=0; layer<matrix.size()/2; layer++) {
        print_layer(matrix, layer);
    }
    if (matrix.size() % 2 == 1) {
        for (int j=matrix.size()/2; j<matrix[0].size()-matrix.size()/2; j++) {
            cout << matrix[matrix.size()/2][j] << endl;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
    };
    print_clockwise(matrix);
}