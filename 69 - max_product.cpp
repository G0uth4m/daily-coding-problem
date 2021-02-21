/*
This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// O(N^3)
int max_product(vector<int> A) {
    int res = INT32_MIN;
    for (int i=0; i<A.size(); i++) {
        for (int j=i+1; j<A.size(); j++) {
            for (int k=j+1; k<A.size(); k++) {
                res = max(res, A[i] * A[j] * A[k]);
            }
        }
    }
    return res;
}

// O(NlogN); O(NlogN)
int max_product2(vector<int> A) {
    sort(A.begin(), A.end());
    return max(A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3], A[0] * A[1] * A[A.size() - 1]);
}

// O(N); O(1)
int max_product3(vector<int> A) {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i=0; i<3; i++) {
        min_heap.push(A[i]);
    }
    for (int i=0; i<2; i++) {
        max_heap.push(A[i]);
    }
    for (int i=3; i<A.size(); i++) {
        if (min_heap.top() < A[i]) {
            min_heap.pop();
            min_heap.push(A[i]);
        }
    }

    for (int i=2; i<A.size(); i++) {
        if (max_heap.top() > A[i]) {
            max_heap.pop();
            max_heap.push(A[i]);
        }
    }
    int res1 = 1;
    int maxi;
    while (!min_heap.empty()) {
        if (min_heap.size() == 1) {
            maxi = min_heap.top();
        }
        res1 *= min_heap.top();
        min_heap.pop();
    }

    int res2 = 1;
    while (!max_heap.empty()) {
        res2 *= max_heap.top();
        max_heap.pop();
    }
    return max(res1, maxi * res2);
}

int main() {
    cout << max_product3({-10, -10, 5, 2}) << endl;
}