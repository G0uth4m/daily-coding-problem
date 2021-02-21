/*
This problem was asked by Two Sigma.

Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, 
implement a function rand7() that returns an integer from 1 to 7 (inclusive).
*/

#include <iostream>
using namespace std;

int rand5() {
    return 1 + rand() % 5;
}

/* Concept :
rand10 : 0 to 9
rand100 : 0 to 99
Wkt, rand10 outcomes 0 to 9 which is one digit
rand100 outcomes 2 digits
So we can do rand100 = 10*rand10 + rand10;
Similarly, rand1000 = 100*rand10 + 10*rand10 + rand10;
*/
int rand7() {
    int rand25 = 5*(rand5() - 1) + (rand5() - 1) + 1;
    if (rand25 < 22) {
        return 1 + rand25 % 7;
    }
    return rand7();
}