/*
This problem was asked by Glassdoor.

An imminent hurricane threatens the coastal town of Codeville. 
If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is k, 
determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80] and a boat limit of 200, 
the smallest number of boats required will be three.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minBoatsForRescue(vector<int>& weights, int boatLimit) {
    sort(weights.begin(), weights.end());
    int res = 0;
    int left = 0;
    int right = weights.size() - 1;
    while (left <= right) {
        if (weights[left] + weights[right] > boatLimit) {
            right--;
        } else {
            left++;
            right--;
        }
        res++;
    }
    return res;
}

int main() {
    vector<int> weights = {100, 200, 150, 80};
    cout << minBoatsForRescue(weights, 200) << endl;
}
