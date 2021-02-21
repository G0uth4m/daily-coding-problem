/*
This problem was asked by Microsoft.

Given a 2D matrix of characters and a target word, write a function that returns whether 
the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true, since it's the leftmost column. 
Similarly, given the target word 'MASS', you should return true, since it's the last row.
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<vector<T>>& A) {
    for (vector<T> i : A) {
        for (T j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool search(vector<vector<char>> matrix, string word) {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    int k = 0;
    for (int i=0; i<dp.size(); i++) {
        for (int j=0; j<dp[0].size(); j++) {
            if (matrix[i][j] == word[k]) {
                if (k == 0) {
                    dp[i][j] = 1;
                    k++;
                } else {
                    if (dp[i - 1][j] == k || dp[i][j - 1] == k) {
                        dp[i][j] = k + 1;
                        k++;
                    }
                }
                if (k == word.size() - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> matrix = {
        {'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'M', 'O', 'B'},
        {'N', 'A', 'S', 'S'}
    };

    cout << search(matrix, "MASS") << endl;
}