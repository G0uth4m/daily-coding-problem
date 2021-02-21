/*
This problem was asked by Google.

Given a set of distinct positive integers, find the largest subset such that 
every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. 
Given [1, 3, 6, 24], return [1, 3, 6, 24]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> powerSet(vector<int>& A) {
    vector<vector<int>> res = {{}};
    vector<int> temp;
    for (int i : A) {
        int x = res.size();
        for (int j=0; j<x; j++) {
            temp = res[j];
            temp.push_back(i);
            res.push_back(temp);
        }
    }
    return res;
}

bool isDivisibleSet(vector<int>& A) {
    for (int i=0; i<A.size(); i++) {
        for (int j=i+1; j<A.size(); j++) {
            if (!(A[i] % A[j] == 0 || A[j] % A[i] == 0)) {
                return false;
            }
        }
    }
    return true;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> largestDivisibleSubset(vector<int>& A) {
    vector<vector<int>> powerset = powerSet(A);
    int largestDivisibleSubsetSize = 0;
    int largestDivisibleSubsetIdx = 0;
    int i = 0;
    for (vector<int>& subset : powerset) {
        if (subset.size() > largestDivisibleSubsetSize && isDivisibleSet(subset)) {
            largestDivisibleSubsetSize = subset.size();
            largestDivisibleSubsetIdx = i;
        }
        i++;
    }
    return powerset[largestDivisibleSubsetIdx];
}

// O(n^2); O(n)
vector<int> largestDivisibleSubset2(vector<int>& A) {
    if (A.size() <= 1) {
        return A;
    }
    sort(A.begin(), A.end());
    vector<int> dp(A.size(), 1);
    int largestDivisibleSubsetSize = 1;
    int lastIdx = 0;
    for (int i=0; i<A.size(); i++) {
        for (int j=0; j<i; j++) {
            if (A[i] % A[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] > largestDivisibleSubsetSize) {
                    largestDivisibleSubsetSize = dp[i];
                    lastIdx = i;
                }
            }
        }
    }
    vector<int> res(largestDivisibleSubsetSize);
    int prev = A[lastIdx];
    while (largestDivisibleSubsetSize != 0 && lastIdx >= 0) {
        if (prev % A[lastIdx] == 0) {
            res[--largestDivisibleSubsetSize] = A[lastIdx];
            prev = A[lastIdx];
        }
        lastIdx--;
    }
    return res;
}

int main() {
    vector<int> A = {3, 5, 10, 20, 21};
    vector<int> res = largestDivisibleSubset2(A);
    print(res);
}
