/*
This problem was asked by Dropbox.

Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. 
The objective is to fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) 
must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>>& grid) {
    for (auto i : grid) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }
    cout << endl;
}

bool isBlockValid(vector<vector<int>>& grid, int blockR, int blockC, int num) {
    for (int i=blockR; i<blockR+3; i++) {
        for (int j=blockC; j<blockC+3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(vector<vector<int>>& grid, int num, int r, int c) {
    for (int i=0; i<grid.size(); i++) {
        if (grid[i][c] == num) {
            return false;
        }
    }
    for (int j=0; j<grid.size(); j++) {
        if (grid[r][j] == num) {
            return false;
        }
    }
    return isBlockValid(grid, r - r%3, c - c%3, num);
}

bool findEmptyPlace(vector<vector<int>>& grid, int &row, int &col) {
    for (row=0; row<9; row++) {
        for (col=0; col<9; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve(vector<vector<int>>& grid) {
    int row, col;
    if (!findEmptyPlace(grid, row, col)) {
        return true;
    }
    for (int num=1; num <= 9; num++) {
        if (isValid(grid, num, row, col)) {
            grid[row][col] = num;
            if (solve(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solve(grid);
    print(grid);
}