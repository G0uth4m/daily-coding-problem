/*
This problem was asked by Zillow.

Let's define a "sevenish" number to be one which is either a power of 7, or the sum of unique powers of 7. 
The first few sevenish numbers are 1, 7, 8, 49, and so on. 
Create an algorithm to find the nth sevenish number.
*/

#include <iostream>
using namespace std;

int nthSevenishNumber(int n) {
    int pow = 1;
    int res = 0;
    while (n) {
        res += (n & 1) * pow;
        pow *= 7;
        n >>= 1;
    }
    return res;
}

int main() {
    for (int i=1; i<=4; i++) {
        cout << nthSevenishNumber(i) << endl;
    }
}
