/*
This problem was asked by Google.

The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> power_set(vector<int> A) {
    vector<vector<int>> res = {{}};
    vector<int> temp;
    for (int i=0; i<A.size(); i++) {
        int x = res.size();
        for (int j=0; j<x; j++) {
            temp = res[j];
            temp.push_back(A[i]);
            res.push_back(temp);
        }
    }
    return res;
}

void print(vector<vector<int>> A) {
    for (auto i : A) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> res = power_set({1, 2, 3});
    print(res);
}