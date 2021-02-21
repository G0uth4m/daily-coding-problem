/*
This problem was asked by Google.

You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string. Determine whether the parentheses are balanced.

For example, (()* and (*) are balanced. )*( is not balanced
*/

#include <iostream>
#include <stack>
using namespace std;

// O(N*3^N)
bool helper(string s, stack<int> stk, int i) {
    if (i >= s.size()) {
        return stk.empty();
    }
    for (int j=i; j<s.size(); j++) {
        if (s[j] == '(') {
            stk.push('(');
        } else if (s[j] == ')') {
            if (stk.empty()) {
                return false;
            }
            stk.pop();
        } else {
            stk.push('(');
            if (helper(s, stk, j+1)) {
                return true;
            }
            stk.pop();
            if (helper(s, stk, j+1)) {
                return true;
            }
            if (stk.empty()) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

bool valid_parenthesis(string s) {
    stack<int> stk;
    return helper(s, stk, 0);
}

// O(N)
bool valid_parenthesis2(string s) {
    int lo = 0;
    int hi = 0;
    for (char c : s) {
        if (c == '(') {
            lo++;
        } else {
            lo--;
        }
        if (c != ')') {
            hi++;
        } else {
            hi--;
        }
        if (hi < 0) {
            break;
        }
        lo = max(lo, 0);
    }
    return lo == 0;
}

int main() {
    cout << valid_parenthesis("(()*") << endl;
    cout << valid_parenthesis("(*)") << endl;
    cout << valid_parenthesis(")*(") << endl;
}