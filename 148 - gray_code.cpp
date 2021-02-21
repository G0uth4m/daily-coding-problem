/*
This problem was asked by Apple.

Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> grayCode(int n) {
    if (n == 0) {
        return {"0"};
    }
    vector<string> l1 = {"0", "1"};
    for (int i=1; i<n; i++) {
        vector<string> l2 = l1;
        reverse(l2.begin(), l2.end());
        for (string& s : l1) {
            s = "0" + s;
        }
        for (string& s : l2) {
            s = "1" + s;
        }
        l1.insert(l1.end(), l2.begin(), l2.end());
    }
    return l1;
}

vector<string> grayCode2(int n) {
    if (n == 0) {
        return {"0"};
    }
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> grayCodePrev = grayCode2(n - 1);
    vector<string> res;
    for (int i=0; i<grayCodePrev.size(); i++) {
        res.push_back("0" + grayCodePrev[i]);
    }
    for (int i=grayCodePrev.size()-1; i>=0; i--) {
        res.push_back("1" + grayCodePrev[i]);
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
    vector<string> res = grayCode2(3);
    print(res);
}