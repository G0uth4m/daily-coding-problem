/*
This problem was asked by Facebook.

Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000, 
return 0000 1111 0000 1111 0000 1111 0000 1111.
*/

#include <iostream>
using namespace std;

// O(1); O(1)
unsigned int reverseBits(unsigned int num) {
    int left = 0;
    int right = 31;
    while (left < right) {
        bool left_bit = num & (1 << left);
        bool right_bit = num & (1 << right);

        if (left_bit && !right_bit) {
            num &= ~(1 << left);
            num |= (1 << right);
        } else if (!left_bit && right_bit) {
            num &= ~(1 << right);
            num |= (1 << left);
        }

        left++;
        right--;
    }
    return num;
}

int main() {
    cout << reverseBits(4042322160) << endl;
}