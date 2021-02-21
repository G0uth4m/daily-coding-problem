/*
This problem was asked by Bloomberg.

Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
*/

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

bool isIsomorphic(string s1, string s2) {
    bitset<256> visited;
    vector<char> map(256, -1);
    
    for (int i=0; i<s1.size(); i++) {
        if (map[s1[i]] == -1) {
            if (visited[s2[i]]) {
                return false;
            }
            visited[s2[i]] = 1;
            map[s1[i]] = s2[i];
        } else if (map[s1[i]] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isIsomorphic("abc", "bcd") << endl;
    cout << isIsomorphic("foo", "bar") << endl;
}