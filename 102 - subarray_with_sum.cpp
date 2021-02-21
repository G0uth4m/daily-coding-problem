/*
This problem was asked by Lyft.

Given a list of integers and a number K, return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> subarray_sum(vector<int> A, int K) {
    int left = 0;
    int right = 0;
    int resu = 0;
    while (right < A.size()) {
        resu += A[right++];
        while (resu > K) {
            resu -= A[left++];
        }
        if (resu == K) 
            return vector<int>(A.begin() + left, A.begin() + right);
    }
    return {};
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> res = subarray_sum({1, 2, 3, 4, 5}, 9);
    print(res);
}