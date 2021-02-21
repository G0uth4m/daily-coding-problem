/*
This problem was asked by Uber.

Implement a 2D iterator class. It will be initialized with an array of arrays, and should implement the following methods:

next(): returns the next element in the array of arrays. If there are no more elements, raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays. Some of the arrays can be empty.
*/

#include <iostream>
#include <vector>
using namespace std;

class Iterator {
private:
    vector<vector<int>> A;
    int i;
    int j;
    int lastVec;

public:
    Iterator(vector<vector<int>> A) {
        this->A = A;
        i = 0;
        while (i < A.size() && A[i].empty()) {
            i++;
        }
        j = 0;
        lastVec = A.size() - 1;
        while (A[lastVec].empty()) {
            lastVec--;
        }
    }

    int next() {
        int toReturn = A[i][j];
        if (j == A[i].size() - 1) {
            i++;
            while (i < A.size() && A[i].empty()) {
                i++;
            }
            j = 0;
        } else {
            j++;
        }
        return toReturn;
    }

    bool hasNext() {
        return i < A.size() && j < A[lastVec].size();
    }
};

int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3},
        {},
        {4, 5, 6}
    };

    Iterator iterator(A);
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;
}