/*
This problem was asked by Google.

You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}. 
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
*/

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// O(n); O(1)
int findDuplicate(vector<int>& A) {
    int N = A.size() - 1;
    int sumN = (N*(N + 1))/2;
    int sumA = accumulate(A.begin(), A.end(), 0);
    return sumA - sumN;
}

// O(n); O(1); // no integer overflow
int findDuplicate2(vector<int>& A) {
    int N = A.size() - 1;
    int xorN = 0;
    for (int i=1; i<=N; i++) {
        xorN ^= i;
    }
    int xorA = 0;
    for (int i : A) {
        xorA ^= i;
    }
    return xorN ^ xorA;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 5, 6};
    cout << findDuplicate2(A) << endl;
}