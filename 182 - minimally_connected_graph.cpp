/*
This problem was asked by Facebook.

A graph is minimally-connected if it is connected and there is no edge that can be removed while still leaving the graph connected. 
For example, any binary tree is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected. 
You can choose to represent the graph as either an adjacency matrix or adjacency list.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isConnected(vector<vector<bool>>& adj_matrix) {
    vector<bool> visited(adj_matrix.size());
    stack<int> s;
    s.push(0);
    visited[0] = true;

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        for (int neighbor=0; neighbor<adj_matrix.size(); neighbor++) {
            if (adj_matrix[curr][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
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

bool isMinimallyConnected(vector<vector<bool>>& adj_matrix) {
    for (int i=0; i<adj_matrix.size(); i++) {
        for (int j=0; j<adj_matrix.size(); j++) {
            if (adj_matrix[i][j]) {
                adj_matrix[i][j] = false;
                adj_matrix[j][i] = false;
                if (isConnected(adj_matrix)) {
                    return false;
                }
                adj_matrix[i][j] = true;
                adj_matrix[j][i] = false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<bool>> adj_matrix(5, vector<bool>(5));
    adj_matrix[0][1] = true;
    adj_matrix[1][0] = true;

    adj_matrix[1][2] = true;
    adj_matrix[2][1] = true;

    adj_matrix[0][2] = true;
    adj_matrix[2][0] = true;

    adj_matrix[0][3] = true;
    adj_matrix[3][0] = true;

    adj_matrix[3][4] = true;
    adj_matrix[4][3] = true;

    cout << isMinimallyConnected(adj_matrix) << endl;
}