/*
This question was asked by ContextLogic.

Implement division of two positive integers without using the division, multiplication, or modulus operators. 
Return the quotient as an integer, ignoring the remainder.
*/

#include <iostream>
using namespace std;

int mydiv(int a, int b) {
    if (b == 0) return -1;
    if (a == 0) return 0;
    int quotient = 0;
    int curr_sum = 0;
    while (curr_sum <= a) {
        quotient++;
        curr_sum += b;
    }
    return quotient - 1;
}

int main() {
    cout << mydiv(14, 3) << endl;
    cout << mydiv(12, 0) << endl;
    cout << mydiv(1, 2) << endl;
    cout << mydiv(100, 20) << endl;
    cout << mydiv(100, 100) << endl;
}