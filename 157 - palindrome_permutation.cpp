/*
This problem was asked by Amazon.

Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome. 
daily should return false, since there's no rearrangement that can form a palindrome.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n); O(1)
bool can_form_palindrome(string s) {
    vector<bool> char_set(256);
    for (char c : s) {
        char_set[c] = !char_set[c];
    }
    bool foundOneOdd = false;
    for (bool i : char_set) {
        if (i) {
            if (foundOneOdd) {
                return false;
            }
            foundOneOdd = true;
        }
    }
    return true;
}

int main() {
    cout << can_form_palindrome("carrace") << endl;
    cout << can_form_palindrome("daily") << endl;
}