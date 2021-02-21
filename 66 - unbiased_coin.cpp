/*
This problem was asked by Square.

Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 
50-50 (but also not 0-100 or 100-0). You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
*/

#include <iostream>
using namespace std;

// true - heads; false - tails
bool toss_biased() {
    int r = rand() % 100;
    return r > 70;
}

// prob of HT = prob of TH = prob of T x prob of H
bool toss_unbiased() {
    bool toss1 = toss_biased();
    bool toss2 = toss_biased();
    if (!toss1 && toss2) {
        return false;
    } else if (toss1 && !toss2) {
        return true;
    }
    return toss_unbiased();
}