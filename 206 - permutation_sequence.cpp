/*
This problem was asked by Twitter.

A permutation can be specified by an array P, where P[i] represents the location of the element at i in the permutation. 
For example, [2, 1, 0] represents the permutation where elements at the index 0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. 
For example, given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> permutation_sequence(vector<string>& arr, vector<int>& permutation) {
    vector<string> res(arr.size());
    int j = 0;
    for (int i : permutation) {
        res[j++] = arr[i];
    }
    return res;
}

void print(vector<string>& A) {
    for (string& s : A) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<string> arr = {"a", "b", "c"};
    vector<int> permutation = {2, 1, 0};
    vector<string> res = permutation_sequence(arr, permutation);
    print(res);
}
