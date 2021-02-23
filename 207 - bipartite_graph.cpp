/*
This problem was asked by Dropbox.

Given an undirected graph G, check whether it is bipartite. 
Recall that a graph is bipartite if its vertices can be divided into two independent sets, U and V, 
such that no edge connects vertices of the same set.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum Color {
    red,
    blue,
    none
};

bool isBipartiteUtil(vector<vector<bool>>& adjMatrix, vector<Color>& colors, int src) {
    queue<int> q;
    q.push(src);
    colors[src] = red;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor=0; neighbor<adjMatrix.size(); neighbor++) {
            if (adjMatrix[node][neighbor] && colors[neighbor] == none) {
                if (colors[node] == red) {
                    colors[neighbor] = blue;
                } else {
                    colors[neighbor] = red;
                }
                q.push(neighbor);
            } else if (adjMatrix[node][neighbor] && colors[node] == colors[neighbor]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<bool>>& adjMatrix) {
    vector<Color> colors(adjMatrix.size(), none);
    for (int i=0; i<colors.size(); i++) {
        if (colors[i] == -1 && !isBipartiteUtil(adjMatrix, colors, i)) {
            return false;
        }
    }
    return true;
}
