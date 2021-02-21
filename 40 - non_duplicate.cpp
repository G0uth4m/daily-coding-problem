/*
This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, 
which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
*/

#include <iostream>
#include <vector>
using namespace std;

unsigned int non_duplicate(vector<unsigned int> A) {
    unsigned int res = 0;
    for (int i=0; i<32; i++) {
        unsigned int x = 1 << i;
        int temp = 0;
        for (auto j : A) {
            if (j & x) {
                temp++;
            }
        }
        if (temp % 3 == 1) {
            res |= x;
        }
    }
    return res;
}

int main() {
    cout << non_duplicate({6, 1, 3, 3, 3, 6, 6}) << endl;
    cout << non_duplicate({13, 9, 13, 13}) << endl;
}