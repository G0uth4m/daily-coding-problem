/*
This problem was asked by Cisco.

Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, 
the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101. 11100010 should be 11010001.

Bonus: Can you do this in one line?
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<bool>& A) {
    for (bool i : A) {
        cout << i << " ";
    }
    cout << endl;
}

vector<bool> int_to_bin(unsigned char num) {
    vector<bool> bin;
    while (num) {
        bin.insert(bin.begin(), num % 2);
        num /= 2;
    }
    return bin;
}

unsigned char bin_to_int(vector<bool>& bin) {
    unsigned char res = 0;
    for (bool i : bin) {
        res = (res * 2) + i;
    }
    return res;
}

unsigned char swap_adj_bits(unsigned char num) {
    vector<bool> bin = int_to_bin(num);
    for (int i=0; i<bin.size(); i+=2) {
        swap(bin[i], bin[i + 1]);
    }
    return bin_to_int(bin);
}

// one line
unsigned char swap_adj_bits2(unsigned char num) {
    return ((num & 0b10101010) >> 1) | ((num & 0b01010101) << 1);
}

unsigned char swap_adj_bits3(unsigned char num) {
    return ((num & 0xaa) >> 1) | ((num & 0x55) << 1);
}

int main() {
    cout << (unsigned int)swap_adj_bits2(170) << endl;
    cout << (unsigned int)swap_adj_bits2(226) << endl;
}