/*
This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array 
so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

#include <iostream>
#include <vector>
using namespace std;

void rgb_sort(vector<char>& A) {
    int r_count = 0;
    int g_count = 0;
    int b_count = 0;
    for (char i : A) {
        if (i == 'R') {
            r_count++;
        } else if (i == 'G') {
            g_count++;
        } else {
            b_count++;
        }
    }
    for (int i=0; i<r_count; i++) {
        A[i] = 'R';
    }
    for (int i=r_count; i<r_count+g_count; i++) {
        A[i] = 'G';
    }
    for (int i=r_count+g_count; i<A.size(); i++) {
        A[i] = 'B';
    }
}

void print(vector<char> A) {
    for (char  i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<char> A = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    rgb_sort(A);
    print(A);
}