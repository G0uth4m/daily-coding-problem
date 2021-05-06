/*
This problem was asked by Twitter.

A classroom consists of N students, whose friendships can be represented in an adjacency list. 
For example, the following descibes a situation where 0 is friends with 1 and 2, 3 is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]} 

Each student can be placed in a friend group, which can be defined as the transitive closure of 
that student's friendship relations. In other words, this is the smallest set such that 
no student in the group has any friends outside this group. 
For the example above, the friend groups would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above, 
the number of friend groups in the class.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int numGroups(vector<vector<int>>& graph) {
    vector<bool> visited(graph.size());

    int res = 0;
    for (int i=0; i<visited.size(); i++) {
        if (!visited[i]) {
            bfs(graph, visited, i);
            res++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 5},
        {0},
        {6},
        {},
        {1},
        {3}
    };
    cout << numGroups(graph) << endl;
}
