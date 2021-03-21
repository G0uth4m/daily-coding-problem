/*
This problem was asked by Airbnb.

You come across a dictionary of sorted words in a language you've never seen before. 
Write a program that returns the correct order of letters in this language.

For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'], 
you should return ['x', 'z', 'w', 'y'].

x, w, y, z

x -> {w, z}
z -> {w}
w -> {y}
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

void topologicalSortUtil(char v, unordered_map<char, vector<char>>& graph, unordered_set<char>& visited, stack<char>& s) {
    visited.insert(v);
    for (int node : graph[v]) {
        if (visited.find(node) == visited.end()) {
            topologicalSortUtil(node, graph, visited, s);
        }
    }
    s.push(v);
}

vector<char> topologicalSort(unordered_map<char, vector<char>>& graph) {
    stack<char> s;
    unordered_set<char> visited;
    for (auto node : graph) {
        if (visited.find(node.first) == visited.end()) {
            topologicalSortUtil(node.first, graph, visited, s);
        }
    }
    vector<char> res(graph.size());
    int i = 0;
    while (!s.empty()) {
        res[i++] = s.top();
        s.pop();
    }
    return res;
}

vector<char> order(vector<string>& words) {
    unordered_map<char, vector<char>> graph;
    for (string& word : words) {
        for (char c : word) {
            graph[c] = {};
        }
    }
    for (int i=0; i<words.size()-1; i++) {
        for (int j=0; j<min(words[i].size(), words[i + 1].size()); j++) {
            if (words[i][j] != words[i + 1][j]) {
                graph[words[i][j]].push_back(words[i + 1][j]);
                break;
            }
        }
    }
    return topologicalSort(graph);
}

void print(vector<char>& A) {
    for (char c : A) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    vector<string> words = {"xww", "wxyz", "wxyw", "ywx", "ywz"};
    vector<char> res = order(words);
    print(res);
}
