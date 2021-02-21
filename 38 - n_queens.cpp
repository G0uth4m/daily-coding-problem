/*
This problem was asked by Microsoft.

You have an N by N board. 
Write a function that, given N, returns the number of possible arrangements of the board 
where N queens can be placed on the board without threatening each other, 
i.e. no two queens share the same row, column, or diagonal.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<bool>> board, int x, int y) {
    for (int j=0; j<board.size(); j++) {
        if (board[x][j]) {
            return false;
        }
    }
    for (int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (int i=x+1, j=y-1; i<board.size() && j>=0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

void backtrack(vector<vector<bool>> board, int start, int* count) {
    if (start == board.size()) {
        (*count)++;
        return;
    }
    for (int i=0; i<board.size(); i++) {
        if (!board[i][start] && isSafe(board, i, start)) {
            board[i][start] = true;
            backtrack(board, start + 1, count);
            board[i][start] = false;
        }
    }
}

int total_nqueens_solutions(int n) {
    int count = 0;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    backtrack(board, 0, &count);
    return count;
}

int main() {
    cout << total_nqueens_solutions(4) << endl;
}