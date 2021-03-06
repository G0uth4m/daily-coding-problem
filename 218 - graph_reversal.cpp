/*
This problem was asked by Yahoo.

Write an algorithm that computes the reversal of a directed graph. 
For example, if a graph consists of A -> B -> C, it should become A <- B <- C.
*/

#include <iostream>
#include <vector>
using namespace std;

void reverseGraph(vector<vector<int>>& adjMatrix) {
    for (int i=0; i<adjMatrix.size(); i++) {
        for (int j=0; j<adjMatrix.size(); j++) {
            if (adjMatrix[i][j] == 1) {
                adjMatrix[j][i] = 2;
            }
        }
    }
    for (int i=0; i<adjMatrix.size(); i++) {
        for(int j=0; j<adjMatrix.size(); j++) {
            if (adjMatrix[i][j] == 1) {
                adjMatrix[i][j] = 0;
            } else if (adjMatrix[i][j] == 2) {
                adjMatrix[i][j] = 1;
            }
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
    vector<vector<int>> adjMatrix = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}
    };
    reverseGraph(adjMatrix);
    print(adjMatrix);
}
