/*
This problem was asked by Two Sigma.

Using a function rand7() that returns an integer from 1 to 7 (inclusive) with uniform probability, 
implement a function rand5() that returns an integer from 1 to 5 (inclusive).
*/

#include <iostream>
using namespace std;

int rand7() {
    return 1 + rand() % 7;
}

int rand5() {
    int res = rand7();
    if (res > 5) {
        return rand7();
    }
    return res;
}