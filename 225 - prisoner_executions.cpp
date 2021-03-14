/*
This problem was asked by Bloomberg.

There are N prisoners standing in a circle, waiting to be executed. 
The executions are carried out starting with the kth person, 
and removing every successive kth person going clockwise until there is no one left.

Given N and k, write an algorithm to determine where a prisoner should stand in order to be the last survivor.

For example, if N = 5 and k = 2, the order of executions would be [2, 4, 1, 5, 3], so you should return 3.

Bonus: Find an O(log N) solution if k = 2.
*/
// 1 2 3 4 5
#include <iostream>
using namespace std;

int lastExecutingPrisoner(int N, int k) {
    if (N == 1) {
        return 1;
    }
    return ((lastExecutingPrisoner(N - 1, k) + k - 1) % N) + 1;
}

int main() {
    cout << lastExecutingPrisoner(5, 2) << endl;
}
