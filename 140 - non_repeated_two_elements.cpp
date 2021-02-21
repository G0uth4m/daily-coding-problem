/*
This problem was asked by Facebook.

Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.

For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

Follow-up: Can you do this in linear time and constant space?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n); O(n)
pair<int, int> non_repeated_el(vector<int>& A) {
    unordered_map<int, int> map;
    for (int i : A) {
        map[i]++;
    }
    pair<int, int> res = {-1, -1};
    for (auto i : map) {
        if (i.second == 1) {
            if (res.first == -1) {
                res.first = i.first;
            } else {
                res.second = i.first;
                return res;
            }
        }
    }
    return res;
}

// O(n); O(1)
pair<unsigned int, unsigned int> non_repeated_el2(vector<unsigned int>& A) {
    unsigned int Xor = 0;
    for (unsigned int i : A) {
        Xor ^= i;
    }
    unsigned int last_set_bit = Xor & ~(Xor - 1);

    pair<unsigned int, unsigned int> res = {0, 0};
    for (unsigned int i : A) {
        if (i & last_set_bit) {
            res.first = res.first ^ i;
        } else {
            res.second = res.second ^ i;
        }
    }
    return res;
}

int main() {
    vector<unsigned int> A = {2, 4, 6, 8, 10, 2, 6, 10};
    pair<unsigned int, unsigned int> res = non_repeated_el2(A);
    cout << res.first << " " << res.second << endl;
}