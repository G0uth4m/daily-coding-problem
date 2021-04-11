/*
This problem was asked by Microsoft.

The transitive closure of a graph is a measure of which vertices are reachable from other vertices. 
It can be represented as a matrix M, where M[i][j] == 1 if there is a path between vertices i and j, 
and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]

The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]

Given a graph, find its transitive closure.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> graph, int node, vector<vector<bool>>& res) {
    vector<bool> visited(graph.size());
    stack<int> s;
    s.push(node);
    visited[node] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int v : graph[u]) {
            if (node == v) {
                res[node][v] = true;
            }
            if (!visited[v]) {
                s.push(v);
                res[node][v] = true;
                visited[v] = true;
            }
        }
    }
}

vector<vector<bool>> transitiveClosure(vector<vector<int>>& graph) {
    vector<vector<bool>> res(graph.size(), vector<bool>(graph.size()));
    for (int node=0; node<graph.size(); node++) {
        dfs(graph, node, res);
    }
    return res;
}

void print(vector<vector<bool>>& A) {
    for (vector<bool>& i : A) {
        for (bool j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 3},
        {1, 2},
        {2},
        {3}
    };
    vector<vector<bool>> res = transitiveClosure(graph);
    print(res);
}
