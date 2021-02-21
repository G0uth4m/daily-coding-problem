/*
This problem was asked by Amazon.

Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1

*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& matrix, int i, int j) {
    matrix[i][j] = '2';
    if (i + 1 < matrix.size() && matrix[i + 1][j] == '1') {
        dfs(matrix, i + 1, j);
    }
    if (j + 1 < matrix[0].size() && matrix[i][j + 1] == '1') {
        dfs(matrix, i, j + 1);
    }
    if (i - 1 >= 0 && matrix[i - 1][j] == '1') {
        dfs(matrix, i - 1, j);
    }
    if (j - 1 >= 0 && matrix[i][j - 1] == '1') {
        dfs(matrix, i, j - 1);
    }
}

// O(n*m); O(n*m)
int num_islands(vector<vector<char>>& matrix) {
    int res = 0;
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            if (matrix[i][j] == '1') {
                res++;
                dfs(matrix, i, j);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '0', '0', '0'},
        {'0', '0', '1', '1', '0'},
        {'0', '1', '1', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '1'}
    };
    cout << num_islands(matrix) << endl;
}