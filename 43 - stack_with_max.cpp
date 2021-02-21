/*
This problem was asked by Amazon.

Implement a stack that has the following methods:

> push(val), which pushes an element onto the stack
> pop(), which pops off and returns the topmost element of the stack. 
  If there are no elements in the stack, then it should throw an error or return null.
> max(), which returns the maximum value in the stack currently. 
  If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.
*/

#include <iostream>
#include <stack>
using namespace std;

class StackWithMax {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data) {
        s1.push(data);
        if (s2.empty() || data >= s2.top()) {
            s2.push(data);
        }
    }

    int pop() {
        if (s1.empty()) {
            throw "Stack underflow";
        }
        if (s1.top() == s2.top()) {
            s2.pop();
        }
        int to_return = s1.top();
        s1.pop();
        return to_return;
    }

    int max() {
        if (s2.empty()) {
            throw "Stack underflow";
        }
        return s2.top();
    }
};