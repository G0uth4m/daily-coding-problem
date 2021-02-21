/*
This problem was asked by Facebook.

Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2]. 
Try solving this without creating a copy of the list. How many swap or move operations do you need?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse2(vector<int>::iterator first, vector<int>::iterator last) {
    last--;
    while (first < last) {
        swap(*first, *last);
        first++;
        last--;
    }
}

void reverse3(vector<int>::iterator first, vector<int>::iterator last) {
    last--;
    while (first < last) {
        iter_swap(first++, last--);
    }
}

// O(n); O(1); no. of swaps = n
void left_rotate(vector<int>& A, int k) {
    k = k % A.size();
    reverse(A.begin(), A.end());
    reverse(A.begin(), A.end() - k);
    reverse(A.end() - k, A.end());
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6};
    left_rotate(A, 2);
    print(A);
}