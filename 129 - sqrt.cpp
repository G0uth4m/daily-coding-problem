/*
Given a real number n, find the square root of n. For example, given n = 9, return 3.
*/

#include <iostream>
using namespace std;

double square(double n, double i, double j) {
    double mid = i + (j - i)/2;
    double mul = mid * mid;

    if (mul == n || abs(mul - n) < 0.00001) {
        return mid;
    } else if (mul < n) {
        return square(n, mid, j);
    }
    return square(n, i, mid);
}

double findSqrt(double n) {
    double i = 1;
    while (true) {
        if (i * i == n) {
            return i;
        } else if (i * i > n) {
            return square(n, i - 1, i);
        }
        i++;
    }
}

int main() {
    cout << findSqrt(3) << endl;
    cout << findSqrt(25) << endl;
}