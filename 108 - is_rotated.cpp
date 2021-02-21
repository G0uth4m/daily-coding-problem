/*
This problem was asked by Google.

Given two strings A and B, return whether or not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
*/
#include <iostream>
using namespace std;

bool is_rotated(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    string temp = s2 + s2;
    return temp.find(s1) != string::npos;
}

int main() {
    cout << is_rotated("abcde", "cdeab") << endl;
}