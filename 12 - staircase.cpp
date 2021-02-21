/*
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. 
Given N, write a function that returns the number of unique ways you can climb the staircase. 
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, 
you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int helper(int N, unordered_map<int, int> *cache) {
    if (cache->find(N) != cache->end()) {
        return cache->at(N);
    }
    if (N == 0) {
        return 1;
    }
    if (N < 0) {
        return 0;
    }
    int to_return = helper(N - 1, cache) + helper(N - 2, cache);
    cache->insert({N, to_return});
    return to_return;
}

int num_ways_to_climb(int N) {
    unordered_map<int, int> cache;
    return helper(N, &cache);
}

int helper2(int N, vector<int> A, unordered_map<int, int>* cache) {
    if (cache->find(N) != cache->end()) {
        return cache->at(N);
    }
    if (N == 0) {
        return 1;
    }
    if (N < 0) {
        return 0;
    }
    int to_return = 0;
    for (int i=0; i<A.size(); i++) {
        to_return += helper2(N - A[i], A, cache);
    }
    cache->insert({N, to_return});
    return to_return;
}

int num_ways_to_climb2(int N, vector<int> A) {
    unordered_map<int, int> cache;
    return helper2(N, A, &cache);
}

int main() {
    cout << num_ways_to_climb(4) << endl;
    cout << num_ways_to_climb2(5, {1, 3, 5}) << endl;
}