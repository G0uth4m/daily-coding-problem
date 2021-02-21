/*
This problem was asked by Amazon.

Implement a stack API using only a heap. A stack implements the following methods:
    push(item), which adds an element to the stack
    pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:
    push(item), which adds a new key to the heap
    pop(), which removes and returns the max value of the heap
*/

#include <iostream>
#include <queue>
using namespace std;

struct Item {
    int val;
    int timestamp;

    bool operator<(Item const& item) const {
        return this->timestamp < item.timestamp;
    }
};

class StackUsingHeap {
private:
    priority_queue<Item, vector<Item>, less<Item>> max_heap;
    int timestamp;

    void __check_underflow() {
        if (empty()) {
            throw "Stack Underflow";
        }
    }

public:
    StackUsingHeap() {
        timestamp = 0;
    }

    void push(int item) {
        max_heap.push({item, timestamp++});
    }

    void pop() {
        __check_underflow();
        max_heap.pop();
    }

    int top() {
        __check_underflow();
        return max_heap.top().val;
    }

    bool empty() {
        return max_heap.empty();
    }
};

int main() {
    StackUsingHeap s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}