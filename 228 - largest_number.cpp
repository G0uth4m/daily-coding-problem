/*
This problem was asked by Twitter.

Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. 
For example, given [10, 7, 76, 415], you should return 77641510.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string largestInt(vector<int>& A) {
    auto comp = [](int a, int b) {
        string a1 = to_string(a);
        string b1 = to_string(b);
        return a1 + b1 > b1 + a1;
    };
    sort(A.begin(), A.end(), comp);
    if (A[0] == 0) {
        return "0";
    }
    string res = "";
    for (int i : A) {
        res += to_string(i);
    }
    return res;
}

int main() {
    vector<int> A = {10, 7, 79, 415};
    cout << largestInt(A) << endl;
}
