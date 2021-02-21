/*
This problem was asked by Google.

Given a stack of N elements, interleave the first half of the stack with the second half reversed using only one other queue. 
This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3]. If the stack is [1, 2, 3, 4], 
it should become [1, 4, 2, 3].

Hint: Try working backwards from the end state.
*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void interleave_stack(stack<int>& s) {
    queue<int> q;
    int n = s.size()/2;
    for (int i=0; i<n; i++) {
        q.push(s.top());
        s.pop();
    }

    stack<int> s2;
    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }

    bool q_turn = false;
    while (!s2.empty() && !q.empty()) {
        if (q_turn) {
            s.push(q.front());
            q.pop();
            q_turn = false;
        } else {
            s.push(s2.top());
            s2.pop();
            q_turn = true;
        }
    }

    if (!q.empty()) {
        s.push(q.front());
        q.pop();
    } else if (!s2.empty()) {
        s.push(s2.top());
        s2.pop();
    }
}

void fillStack(stack<int>& s, vector<int> A) {
    for (int i : A) {
        s.push(i);
    }
}

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void interleave_stack2(stack<int>& s) {
    queue<int> q;
    for (int i=1; i<s.size()-1; i++) {
        int x = s.size() - i;
        for (int j=0; j<x; j++) {
            q.push(s.top());
            s.pop();
        }
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
    }
}

int main() {
    stack<int> s;
    fillStack(s, {1, 2, 3, 4, 5});
    interleave_stack2(s);
    print(s);
}