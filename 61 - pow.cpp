/*
This problem was asked by Google.

Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/
#include <iostream>
using namespace std;

bool is_pow_of_2(int num) {
    return (num & (num - 1)) == 0;
}

int last_bit_pos(int num) {
    int res = 0;
    while (num) {
        if (num & 1 == 1) {
            return res;
        }
        res++;
        num >>= 1;
    }
    return -1;
}

// O(N)
int pow(int num, int raise) {
    if (is_pow_of_2(num)) {
        return 1 << (raise * last_bit_pos(num));
    }
    int res = 1;
    for (int i=0; i<raise; i++) {
        res *= num;
    }
    return res;
}

// O(logN)
int pow2(int num, int raise) {
    if (raise == 0) {
        return 1;
    }
    int temp = pow2(num, raise/2);
    temp = temp * temp;
    if (raise % 2 == 0) {
        return temp;
    }
    return num * temp;
}

int main() {
    cout << pow2(9, 3) << endl;
}