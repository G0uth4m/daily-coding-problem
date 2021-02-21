/*
his problem was asked by Quora.

Given a string, find the palindrome that can be made by inserting the 
fewest number of characters as possible anywhere in the word. 
If there is more than one palindrome of minimum length that can be made, 
return the lexicographically earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", 
since we can add three letters to it (which is the smallest amount to make a palindrome). 
There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".
*/
#include <iostream>
using namespace std;

bool is_palindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string make_palindrome(string s) {
    int i = 0;
    int j = 1;
    while (!is_palindrome(s)) {
        s.insert(s.begin() + i, s[s.size() - j]);
        i++;
        j++;
    }
    return s;
}

int main() {
    cout << make_palindrome("google") << endl;
}
