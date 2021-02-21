/*
This problem was asked by Microsoft.

A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/

#include <iostream>
using namespace std;

bool sum_of_digits_equals_10(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        if (res > 10) {
            return false;
        }
        n /= 10;
    }
    return res == 10;
}

int nth_perfect_no(int n) {
    int res = 19;
    while (n > 1) {
        res += 9;
        if (sum_of_digits_equals_10(res)) {
            n--;
        }
    }
    return res;
}

int main() {
    for (int i=1; i<30; i++) {
        cout << nth_perfect_no(i) << endl;
    }
}