/*
This problem was asked by Goldman Sachs.

Given a list of numbers L, implement a method sum(i, j) which returns the sum from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step.
*/
// 0 1 3 6 10 15

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> prefix_sum;
public:
    Solution(vector<int>& nums) {
        prefix_sum.push_back(0);
        for (int i=0; i<nums.size(); i++) {
            prefix_sum.push_back(prefix_sum.back() + nums[i]);
        }
    }

    int sum(int i, int j) {
        return prefix_sum[j] - prefix_sum[i];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution sol(nums);
    cout << sol.sum(1, 3) << endl;
    cout << sol.sum(2, 4) << endl;
}