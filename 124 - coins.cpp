/*
This problem was asked by Microsoft.

You have n fair coins and you flip them all at the same time. 
Any that come up tails you set aside. 
The ones that come up heads you flip again. 
How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
*/

#include <iostream>
#include <cmath>
using namespace std;

int num_rounds(int num_coins) {
    int res = 0;
    while (num_coins > 1) {
        res++;
        if (num_coins % 2 == 1) {
            num_coins++;
        }
        num_coins /= 2;
    }
    return res;
}

int num_rounds2(int num_coins) {
    return ceil(log2(num_coins));
}

int main() {
    cout << num_rounds2(1) << endl;
    cout << num_rounds2(2) << endl;
    cout << num_rounds2(100) << endl;
    cout << num_rounds2(200) << endl;
}