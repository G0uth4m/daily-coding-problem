/*
Given an undirected graph represented as an adjacency matrix and an integer k, 
write a function to determine whether each vertex in the graph can be colored such that 
no two adjacent vertices share the same color using at most k colors.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool can_color(vector<vector<bool>>& graph, int k) {
    int max_dependencies = 0;
    for (auto i : graph) {
        max_dependencies = max(max_dependencies, accumulate(i.begin(), i.end()));
        if (max_dependencies > k) {
            return false;
        }
    }
    return true;
}