/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.
[5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int helper(vector<int> A, int i, unordered_map<int, int>* cache) {
    if (cache->find(i) != cache->end()) {
        return cache->at(i);
    }
    if (i == A.size() - 1) {
        return A.back();
    }
    if (i >= A.size()) {
        return 0;
    }
    int x = A[i] + helper(A, i + 2, cache);
    int y = A[i + 1] + helper(A, i + 3, cache);
    int to_return = max(x, y);
    cache->insert({i, to_return});
    return to_return;
}

int largest_sum_of_non_adjacent(vector<int> A) {
    unordered_map<int, int> cache;
    return helper(A, 0, &cache);
}

int main() {
    vector<int> A = {2, 4, 6, 2, 5};
    cout << largest_sum_of_non_adjacent(A) << endl;
    vector<int> B = {5, 5, 10, 100, 10, 5};
    cout << largest_sum_of_non_adjacent(B) << endl;
}