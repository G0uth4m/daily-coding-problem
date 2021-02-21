/*
This problem was asked by Microsoft.

Implement 3 stacks using a single list:
*/

#include <iostream>
#include <vector>
using namespace std;

class ThreeStacks {
private:
    vector<int> arr;
    vector<int> tops;
    vector<int> starts;
    vector<int> ends;
    size_t singleStackSize;

public:
    ThreeStacks(size_t size) {
        singleStackSize = size;
        arr.assign(3 * singleStackSize, 0);
        tops = {-1, (int)singleStackSize - 1, 2*(int)singleStackSize - 1};
        starts = {0, (int)singleStackSize, 2*(int)singleStackSize};
        ends = {(int)singleStackSize - 1, 2*(int)singleStackSize - 1, 3*(int)singleStackSize - 1};
    }

    void pop(int stackNum) {
        if (tops[stackNum] == starts[stackNum] - 1) {
            throw "Underflow";
        }
        tops[stackNum]--;
    }

    void push(int item, int stackNum) {
        if (tops[stackNum] == ends[stackNum]) {
            throw "Overflow";
        }
        arr[tops[stackNum]++] = item;
    }

    int top(int stackNum) {
        if (tops[stackNum] == starts[stackNum] - 1) {
            throw "Underflow";
        }
        return arr[tops[stackNum]];
    }
};