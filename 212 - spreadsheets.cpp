/*
This problem was asked by Dropbox.

Spreadsheets often use this alphabetical encoding for its columns: 
"A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. 
For example, given 1, return "A". Given 27, return "AA".
*/

#include <iostream>
#include <algorithm>
using namespace std;

string decode(int columnNum) {
    string res = "";
    while (columnNum) {
        int offset = columnNum % 26;
        if (offset == 0) {
            res.push_back('Z');
            columnNum--;
        } else {
            res.push_back('A' + offset - 1);
        }
        columnNum /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << decode(26) << endl;
    cout << decode(27) << endl;
    cout << decode(28) << endl;
}
