/*
This problem was asked by Apple.

Implement the function fib(n), which returns the nth number in the Fibonacci sequence, 
using only O(1) space.
*/

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i=2; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int i = 0;
    while (i < 10) {
        cout << fib(i) << endl;
        i++;
    }
}
