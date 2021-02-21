/*
This problem was asked by Facebook.

Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]

you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]

Follow-up: What if you couldn't use any extra space?
*/

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for (int layer=0; layer<matrix.size()/2; layer++) {
        int first = layer;
        int last = matrix.size() - layer - 1;
        for (int j=0; j<last; j++) {
            int offset = j - first;
            int temp = matrix[first][j];
            matrix[first][j] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[j][last];
            matrix[j][last] = temp;
        }
    }
}

void print(vector<vector<int>>& A) {
    for (vector<int>& i : A) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(matrix);
    print(matrix);
}