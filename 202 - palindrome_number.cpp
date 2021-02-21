/*
This problem was asked by Palantir.

Write a program that checks whether an integer is a palindrome. 
For example, 121 is a palindrome, as well as 888. 678 is not a palindrome. 
Do not convert the integer into a string.
*/

#include <iostream>
using namespace std;

int reverse(int n) {
    int res = 0;
    while (n) {
        res = (res * 10) + (n % 10);
        n /= 10;
    }
    return res;
}

bool isPalindrome(int n) {
    if (n < 0) {
        return false;
    }
    return n == reverse(n);
}

int main() {
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(678) << endl;
}