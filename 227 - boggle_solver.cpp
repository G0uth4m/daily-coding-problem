/*
This problem was asked by Facebook.

Boggle is a game played on a 4 x 4 grid of letters. 
The goal is to find as many words as possible that can be formed 
by a sequence of adjacent letters in the grid, using each cell at most once. 
Given a game board and a dictionary of valid words, implement a Boggle solver.
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<string>& words) {
    for (string& word : words) {
        cout << word << " ";
    }
    cout << endl;
}

bool dfs(vector<vector<char>>& grid, string& word, int count, int i, int j) {
    if (count == word.size()) {
        return true;
    }
    if (i < 0 || j < 0 || i>= grid.size() || j >= grid[0].size() || grid[i][j] != word[count]) {
        return false;
    }
    char temp = grid[i][j];
    grid[i][j] = ' ';
    bool found = dfs(grid, word, count + 1, i - 1, j)
        || dfs(grid, word, count + 1, i - 1, j + 1)
        || dfs(grid, word, count + 1, i, j + 1)
        || dfs(grid, word, count + 1, i + 1, j + 1)
        || dfs(grid, word, count + 1, i + 1, j)
        || dfs(grid, word, count + 1, i + 1, j - 1)
        || dfs(grid, word, count + 1, i, j - 1)
        || dfs(grid, word, count + 1, i - 1, j - 1);
    grid[i][j] = temp;
    return found;
}

bool exists(vector<vector<char>>& grid, string& word) {
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (dfs(grid, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}

vector<string> boggleSolver(vector<vector<char>>& grid, vector<string>& dictionary) {
    vector<string> res;
    for (string& word : dictionary) {
        if (exists(grid, word)) {
            res.push_back(word);
        }
    }
    return res;
}

int main() {
    vector<vector<char>> grid = {
        {'E', 'N', 'R', 'N'},
        {'S', 'I', 'A', 'B'},
        {'O', 'A', 'E', 'Y'},
        {'U', 'C', 'X', 'E'}
    };
    vector<string> dictionary = {"SOU", "YAR", "CAR" "RAY", "BAR", "NAB", "YES", "BAN", "ANE", "SEN", "SIN", "QUS", "SAIRA"};
    vector<string> res = boggleSolver(grid, dictionary);
    print(res);
}
