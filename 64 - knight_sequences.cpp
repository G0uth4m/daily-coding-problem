/*
This problem was asked by Google.

A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.

Given N, write a function to return the number of knight's tours on an N by N chessboard.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int r, int c) {
    return r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == 0;
}

bool solve_util(vector<vector<int>>& board, int r, int c, int sequence_num, vector<int>& rMove, vector<int>& cMove) {
    if (sequence_num == board.size() * board.size()) {
        return true;
    }
    for (int k=0; k<rMove.size(); k++) {
        int next_r = r + rMove[k];
        int next_c = c + cMove[k];
        if (isSafe(board, next_r, next_c)) {
            board[next_r][next_c] = sequence_num;
            if (solve_util(board, next_r, next_c, sequence_num + 1, rMove, cMove)) {
                return true;
            }
            board[next_r][next_c] = 0;
        }
    }
    return false;
}

void solve(vector<vector<int>>& board) {
    vector<int> rMove = {2, 1, -1, -2, -2, -1, 1, 2}; 
    vector<int> cMove = {1, 2, 2, 1, -1, -2, -2, -1};
    solve_util(board, 0, 0, 1, rMove, cMove);
}

template <typename T>
void print(vector<vector<T>> A) {
    for (vector<T> i : A) {
        for (T j : i) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(8, vector<int>(8, 0));
    solve(board);
    print<int>(board);
}