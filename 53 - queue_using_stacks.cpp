#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1;
    stack<int> s2;
    int front;

public:
    void push(int data) {
        if (empty()) {
            front = data;
        }
        s1.push(data);
    }

    void pop() {
        if (empty()) {
            throw "underflow";
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
        if (!s2.empty()) {
            front = s2.top();
        }
    }

    int front() {
        if (empty()) {
            throw "underflow";
        }
        return front;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

    size_t size() {
        return s1.size() + s2.size();
    }
};