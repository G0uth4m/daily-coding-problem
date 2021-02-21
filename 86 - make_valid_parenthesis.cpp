/*
This problem was asked by Google.

Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed 
to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. 
Given the string ")(", you should return 2, since we must remove all of them.
*/

#include <iostream>
#include <stack>
using namespace std;

int make_valid_parenthesis(string parens) {
    stack<char> s;
    for (char c : parens) {
        if (s.empty() || c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.top() == '(') {
                s.pop();
            } else {
                s.push(c);
            }
        }
    }
    return s.size();
}

int main() {
    cout << make_valid_parenthesis("()())()") << endl;
    cout << make_valid_parenthesis(")(") << endl;
    cout << make_valid_parenthesis("()(((") << endl;
    cout << make_valid_parenthesis(")()(((") << endl;
    cout << make_valid_parenthesis("))))()") << endl;
}