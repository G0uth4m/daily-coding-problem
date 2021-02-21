/*
This problem was asked by IBM.

Given an integer, find the next permutation of it in absolute order. 
For example, given 48975, the next permutation would be 49578.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void next_permutation(string& s) {
    int j = -1;
    for (int i=s.size()-1; i>=1; i--) {
        if (s[i] > s[i - 1]) {
            j = i - 1;
            break;
        }
    }
    if (j != -1) {
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
                break;
            }
        }
    }
    reverse(s.begin() + j + 1, s.end());
}

int next_permutation(int n) {
    string s = to_string(n);
    next_permutation(s);
    return stoi(s);
}

int main() {
    cout << next_permutation(48975) << endl;
}
