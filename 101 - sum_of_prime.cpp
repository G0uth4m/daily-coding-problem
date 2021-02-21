/*
This problem was asked by Alibaba.

Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4

If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> prime_sum(int num) {
    vector<bool> isPrime(num, true);
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<=num; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<num; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i=2; i<isPrime.size(); i++) {
        if (isPrime[i] && isPrime[num - i]) {
            return {i, num - i};
        }
    }
    return {-1, -1};
}

int main() {
    cout << prime_sum(74).first << " " << prime_sum(74).second << endl;
    cout << prime_sum(4).first << " " << prime_sum(4).second << endl;
}