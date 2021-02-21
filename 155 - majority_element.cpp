/*
Given a list of elements, find the majority element, which appears more than half the times (> floor(len(lst) / 2.0)).

You can assume that such an element exists.

For example, given [1, 2, 1, 1, 1, 3, 4, 0], return 1.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n); O(n)
int majority_element(vector<int>& A) {
    unordered_map<int, int> map;
    int threshold = A.size()/2;
    for(int i : A) {
        map[i]++;
        if (map[i] > threshold) {
            return i;
        }
    }
    return -1;
}

// Boyre-Moore Voting algorithm
// O(n); O(1)
int majority_element2(vector<int>& A) {
    int count = 0;
    int res = -1;
    for (int i : A) {
        if (count == 0) {
            res = i;
        }
        count += (i == res) ? 1 : -1;
    }
    return res;
}

int main() {
    vector<int> A = {1, 2, 1, 1, 1, 3, 4, 0};
    cout << majority_element2(A) << endl;
}