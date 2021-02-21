/*
This problem was asked by Facebook.

Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. 
For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse_delimiters(string& s, vector<bool>& delimiters_set, int left, int right) {
    while (left < right) {
        if (delimiters_set[s[left]] && delimiters_set[s[right]]) {
            swap(s[left], s[right]);
            left++;
            right--;
        } else if (delimiters_set[s[left]]) {
            right--;
        } else if (delimiters_set[s[right]]) {
            left++;
        } else {
            left++;
            right--;
        }
    }
}

// O(n)
void reverse_words(string& s, vector<bool>& delimiters_set) {
    int l = 0;
    int r = s.size() - 1;
    while (delimiters_set[s[l]]) l++;
    while (delimiters_set[s[r]]) r--;
    reverse(s.begin() + l, s.begin() + r + 1);
    
    int left = l;
    int right = l;
    for (; right<=r; right++) {
        if (delimiters_set[s[right]]) {
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
        }
    }
    reverse(s.begin() + left, s.begin() + right);
    reverse_delimiters(s, delimiters_set, l, r);
}

int main() {
    string s = "hello/world:here";
    vector<bool> delimiters_set(256, false);
    delimiters_set['/'] = true;
    delimiters_set[':'] = true;
    reverse_words(s, delimiters_set);
    cout << s << endl;

    string s2 = "hello/world:here/";
    reverse_words(s2, delimiters_set);
    cout << s2 << endl;
}