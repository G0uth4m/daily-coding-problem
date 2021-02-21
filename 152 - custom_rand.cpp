/*
This problem was asked by Triplebyte.

You are given n numbers as well as n probabilities that sum up to 1. 
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2], 
your function should return 1 10% of the time, 2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// O(n); O(n)
int custom_rand(vector<int>& nums, vector<double>& probabilities) {
    vector<double> prefix_sum(nums.size() + 1, 0);
    for (int i=0; i<probabilities.size(); i++) {
        prefix_sum[i + 1] = prefix_sum[i] + probabilities[i];
    }

    double r = (double)rand()/(double)RAND_MAX;

    vector<double>::iterator iter = lower_bound(prefix_sum.begin(), prefix_sum.end(), r);
    int idx = iter - prefix_sum.begin();

    if (*iter == r) {
        return nums.at(idx);
    }
    return nums.at(idx - 1);
}

int main() {
    srand(time(0));
    vector<int> nums = {1, 2, 3, 4};
    vector<double> probabilities = {0.1, 0.5, 0.2, 0.2};
    cout << custom_rand(nums, probabilities) << endl;
}