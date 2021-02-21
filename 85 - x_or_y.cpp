/*
This problem was asked by Facebook.

Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, 
using only mathematical or bit operations. You can assume b can only be 1 or 0.
*/

#include <iostream>
using namespace std;

int x_or_y(int x, int y, int b) {
    return (x * b) + (y * (1 - b));
}

int x_or_y2(int x, int y, int b) {
    int mask = -b; // all set bits if b=1 else 0
    return (x & mask) | (y & ~mask);
}

int main() {
    cout << x_or_y2(2, 3, 1) << endl;
    cout << x_or_y2(2, 3, 0) << endl;
}