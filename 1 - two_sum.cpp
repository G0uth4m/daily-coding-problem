/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// O(n)
bool two_sum(vector<int> A, int sum) {
    unordered_set<int> int_set;

    for (int i=0; i<A.size(); i++) {
        if (int_set.find(sum - A[i]) != int_set.end()) {
            return true;
        }
        int_set.insert(A[i]);
    }
    return false;
}

int main() {
    cout << two_sum({10, 15, 3, 7}, 17) << endl;
}