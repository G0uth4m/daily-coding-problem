/*
This problem was asked by Google.

Given a string of words delimited by spaces, reverse the words in string. 
For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation in-place?
*/

#include <iostream>
#include <algorithm>
using namespace std;

void reverse_words(string& s) {
    reverse(s.begin(), s.end());
    int left = 0;
    for (int right=0; right<s.size(); right++) {
        if (s[right] == ' ') {
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
        }
    }
    reverse(s.begin() + left, s.end());
}

int main() {
    string s = "hello world here";
    reverse_words(s);
    cout << s << endl;
}