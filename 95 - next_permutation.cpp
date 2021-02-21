/*
This problem was asked by Palantir.

Given a number represented by a list of digits, find the next greater permutation of a number, 
in terms of lexicographic ordering. If there is not greater permutation possible, 
return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. 
The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the input memory)?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> next_permute(vector<int> A) {
    int j = -1;
    for (int i=A.size() - 1; i>=1; i--) {
        if (A[i] > A[i - 1]) {
            j = i - 1;
            break;
        }
    }
    if (j != -1) {
        for (int i=A.size()-1; i>=0; i--) {
            if (A[i] > A[j]) {
                swap(A[i], A[j]);
                break;
            }
        }
    }

    reverse(A.begin() + j + 1, A.end());
    return A;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // vector<int> A = {1, 2, 3};
    // next_permutation(A.begin(), A.end());
    // print(A);
    vector<int> res = next_permute({2, 1, 3});
    print(res);
}