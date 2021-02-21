/*
This problem was asked by Amazon.

Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each index.

    init(size): initialize the array with size
    set(i, val): updates index at i with val where val is either 1 or 0.
    get(i): gets the value at index i.

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class BitArray {
private:
    size_t intSize;
    vector<unsigned int> arr;

public:
    BitArray(size_t size) {
        intSize = 8 * sizeof(int);
        arr.assign(ceil(size/intSize), 0);
    }

    void set(int i, bool val) {
        if (i < 0 || i >= size()) {
            throw "IndexError";
        }
        unsigned int pos = i / intSize;
        unsigned int loc = intSize - (i % intSize);
        unsigned int mask = 1 << (loc - 1);
        if (val) {
            arr[pos] |= mask;
        } else {
            arr[pos] &= ~mask;
        }
    }

    bool get(int i) {
        if (i < 0 || i >= size()) {
            throw "IndexError";
        }
        unsigned int pos = i / intSize;
        unsigned int loc = intSize - (i % intSize);
        unsigned int mask =  1 << (loc - 1);
        return (arr[pos] & mask) != 0;
    }

    size_t size() {
        return arr.size() * 8 * sizeof(int);
    }
};

int main() {
    BitArray bitArray(96);

    cout << bitArray.get(95) << endl;
    bitArray.set(95, 1);
    cout << bitArray.get(95) << endl;
    bitArray.set(95, 0);
    cout << bitArray.get(95) << endl;
}