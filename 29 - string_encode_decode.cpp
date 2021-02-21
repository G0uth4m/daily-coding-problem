/*
This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. 
The basic idea is to represent repeated successive characters as a single count and character. 
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. 
You can assume the string to be encoded have no digits and consists solely of alphabetic characters. 
You can assume the string to be decoded is valid.
*/
#include <iostream>
using namespace std;

string encode(string s) {
    int temp = 1;
    string res = "";
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == s[i + 1]) {
            temp++;
        } else {
            res += to_string(temp);
            res.push_back(s[i]);
            temp = 1;
        }
    }
    res += to_string(temp);
    res.push_back(s.back());
    return res;
}

string decode(string s) {
    string res = "";
    int c = 0;
    for (int i=0; i<s.size(); i++) {
        if (isdigit(s[i])) {
            c = c*10 + (s[i] - '0');
        } else {
            for (int j=0; j<c; j++) {
                res.push_back(s[i]);
            }
            c = 0;
        }
    }
    return res;
}

int main() {
    cout << encode("AAAAAAAAAAAABBBCCDAA") << endl;
    cout << decode(encode("AAAAAAAAAAAABBBCCDAA")) << endl;
}