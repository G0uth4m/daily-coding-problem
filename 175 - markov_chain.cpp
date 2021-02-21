/*
This problem was asked by Google.

You are given a starting state start, a list of transition probabilities for a Markov chain, and a number of steps num_steps. 
Run the Markov chain starting from start for num_steps and compute the number of times we visited each state.

For example, given the starting state a, number of steps 5000, and the following transition probabilities:

[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]

One instance of running this Markov chain might produce {'a': 3012, 'b': 1656, 'c': 332 }.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Transition {
    int start;
    int end;
    double probability;
};

int transit(vector<vector<double>>& adj_matrix, int node) {
    vector<double> prefix_sum(adj_matrix.size() + 1);
    for (int end=0; end<adj_matrix[0].size(); end++) {
        prefix_sum[end + 1] = prefix_sum[end] + adj_matrix[node][end];
    }
    double r = (double)rand()/(double)RAND_MAX;
    int idx = lower_bound(prefix_sum.begin(), prefix_sum.end(), r) - prefix_sum.begin();
    return idx - 1;
}

vector<int> numVisits(vector<Transition>& transitions, int start, int numSteps, int numStates) {
    vector<vector<double>> adj_matrix(numStates, vector<double>(numStates));
    for (Transition& transition : transitions) {
        adj_matrix[transition.start][transition.end] = transition.probability;
    }
    
    vector<int> res(numStates);
    for (int i=0; i<numSteps; i++) {
        start = transit(adj_matrix, start);
        res[start]++;
    }
    return res;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<Transition> transitions = {
        {0, 0, 0.9},
        {0, 1, 0.075},
        {0, 2, 0.025},
        {1, 0, 0.15},
        {1, 1, 0.8},
        {1, 2, 0.05},
        {2, 0, 0.25},
        {2, 1, 0.25},
        {2, 2, 0.5}
    };

    vector<int> res = numVisits(transitions, 0, 5000, 3);
    print(res);
}