/*
This problem was asked by Microsoft.

Given a number in the form of a list of digits, return all possible permutations.

For example, given [1,2,3], return [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
*/

#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int>& A, int l, vector<vector<int>>& res) {
    if (l >= A.size()) {
        res.push_back(A);
        return;
    }
    for (int i=l; i<A.size(); i++) {
        swap(A[i], A[l]);
        permutations(A, l + 1, res);
        swap(A[i], A[l]);
    }
}

vector<vector<int>> permutations(vector<int>& A) {
    vector<vector<int>> res;
    permutations(A, 0, res);
    return res;
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
    vector<int> A = {1, 2, 3};
    vector<vector<int>> res = permutations(A);
    print(res);
}