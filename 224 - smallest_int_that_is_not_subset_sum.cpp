/*
This problem was asked by Amazon.

Given a sorted array, find the smallest positive integer that is not the sum of a subset of the array.

For example, for the input [1, 2, 3, 10], you should return 7.

Do this in O(N) time.
*/

#include <iostream>
#include <vector>
using namespace std;

int findSmallestIntThatIsNotSubsetSum(vector<int>& A) {
    int res = 1;
    for (int i=0; i<A.size() && A[i]<=res; i++) {
        res += A[i];
    }
    return res;
}

int main() {
    vector<int> A = {1, 2, 3, 10};
    cout << findSmallestIntThatIsNotSubsetSum(A) << endl;
}
