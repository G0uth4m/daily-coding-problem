/*
This problem was asked by Coursera.

Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.
*/
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int count, int i, int j) {
    if (count == word.size()) {
        return true;
    }
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[count]) {
        return false;
    }
    char temp = board[i][j];
    board[i][j] = ' ';
    bool found = dfs(board, word, count + 1, i + 1, j)
        || dfs(board, word, count + 1, i, j + 1)
        || dfs(board, word, count + 1, i - 1, j)
        || dfs(board, word, count + 1, i, j - 1);
    board[i][j] = temp;
    return found;
}

bool exists(vector<vector<char>>& board, string word) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (dfs(board, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;   
}
