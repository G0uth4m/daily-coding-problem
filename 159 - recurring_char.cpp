/*
This problem was asked by Google.

Given a string, return the first recurring character in it, or null if there is no recurring chracter.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null.
*/

#include <iostream>
#include <bitset>
using namespace std;

// O(n); O(1)
char first_recurring_char(string s) {
    bitset<256> char_set;
    for (char c : s) {
        if (char_set[c]) {
            return c;
        }
        char_set[c] = 1;
    }
    return '0';
}

int main() {
    cout << first_recurring_char("abbac") << endl;
    cout << first_recurring_char("abcdef") << endl;
}