/*
This problem was asked by Microsoft.

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

// O(n logn)
int longest_consecutive_sequence(vector<int>& A) {
    if (A.empty()) return 0;

    sort(A.begin(), A.end());
    int temp = 1;
    int res = 1;
    for (int i=0; i<A.size(); i++) {
        if (A[i] == A[i + 1]) {
            continue;
        }
        if (A[i] + 1 == A[i + 1]) {
            temp++;
        } else {
            res = max(res, temp);
            temp = 1;
        }
    }
    return max(res, temp);
}

// O(n logn); O(n)
int longest_consecutive_sequence2(vector<int>& A) {
    priority_queue<int, vector<int>, greater<int>> min_heap(A.begin(), A.end());
    int temp = 1;
    int res = 1;
    int t = min_heap.top();
    min_heap.pop();
    while (!min_heap.empty()) {
        if (t == min_heap.top()) {
            min_heap.pop();
            continue;
        }
        if (t + 1 == min_heap.top()) {
            temp++;
        } else {
            res = max(res, temp);
            temp = 1;
        }
        t = min_heap.top();
        min_heap.pop();
    }
    return max(res, temp);
}

// O(n); O(n)
int longest_consecutive_sequence3(vector<int>& A) {
    unordered_set<int> s(A.begin(), A.end());
    
    int res = 0;
    for (int i=0; i<A.size(); i++) {
        if (s.find(A[i] - 1) == s.end()) {
            int t = A[i];
            int temp = 1;
            while (s.find(t + 1) != s.end()) {
                temp++;
                t++;
            }
            res = max(res, temp);
        }
    }
    return res;
}

int main() {
    vector<int> A = {100, 4, 200, 1, 3, 2};
    cout << longest_consecutive_sequence(A) << endl;
}
