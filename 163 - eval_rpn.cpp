/*
This problem was asked by Jane Street.

Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

The expression is given as a list of numbers and operands. For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, 
since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (string& s : tokens) {
        if (s != "+" && s != "-" && s != "*" && s != "/") {
            stk.push(stoi(s));
        } else {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();

            if (s == "+") {
                stk.push(num1 + num2);
            } else if (s == "-") {
                stk.push(num2 - num1);
            } else if (s == "*") {
                stk.push(num1 * num2);
            } else {
                stk.push(num2 / num1);
            }
        }
    }
    return stk.top();
}

int main() {
    vector<string> tokens = {"15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"};
    cout << evalRPN(tokens) << endl;
}