/*
This problem was asked by Mozilla.

A bridge in a connected (undirected) graph is an edge that, 
if removed, causes the graph to become disconnected. 
Find all the bridges in a graph
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isConnected(vector<vector<bool>>& graph) {
    queue<int> q;
    vector<bool> visited(graph.size());
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v=0; v<graph.size(); v++) {
            if (!visited[v] && graph[u][v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (bool i : visited) {
        if (!i) {
            return false;
        }
    }
    return true;
}

vector<pair<int, int>> bridges(vector<vector<bool>>& graph) {
    vector<pair<int, int>> res;
    for (int i=0; i<graph.size(); i++) {
        for (int j=i; j<graph.size(); j++) {
            if (graph[i][j]) {
                graph[i][j] = false;
                graph[j][i] = false;
                if (!isConnected(graph)) {
                    res.push_back({i, j});
                }
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }
    return res;
}

void print(vector<pair<int, int>>& A) {
    for (pair<int, int> p : A) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    vector<vector<bool>> graph = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
    };
    vector<pair<int, int>> res = bridges(graph);
    print(res);
}
