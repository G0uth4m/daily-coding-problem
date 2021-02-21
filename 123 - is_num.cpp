/*
This problem was asked by LinkedIn.

Given a string, return whether it represents a number. Here are the different kinds of numbers:

    "10", a positive integer
    "-10", a negative integer
    "10.1", a positive real number
    "-10.1", a negative real number
    "1e5", a number in scientific notation

And here are examples of non-numbers:

    "a"
    "x 1"
    "a -2"
    "-"
*/

#include <iostream>
using namespace std;

bool is_num(string s) {
    bool flag1 = false;
    bool flag2 = false;
    for (int i=0; i<s.size(); i++) {
        if (!isdigit(s[i])) {
            if (s[i] == '.' && !flag1) {
                flag1 = true;
                continue;
            } else if (s[i] == '-' && i == 0) {
                if (s.size() == 1) {
                    return false;
                }
                continue;
            } else if (s[i] == 'e' && !flag2) {
                flag2 = true;
                continue;
            }
            return false;
        }
    }
    return true;
}

int main() {
    cout << is_num("10") << endl;
    cout << is_num("-10") << endl;
    cout << is_num("10.1") << endl;
    cout << is_num("-10.1") << endl;
    cout << is_num("1e5") << endl;
    cout << is_num("a") << endl;
    cout << is_num("x 1") << endl;
    cout << is_num("a -2") << endl;
    cout << is_num("-") << endl;
}