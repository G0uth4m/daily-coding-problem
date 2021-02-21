/*
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node. 
Implement an XOR linked list; it has an add(element) which adds the element to the end,
and a get(index) which returns the node at index.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* both;

    Node(int data) {
        this->data = data;
        both = nullptr;
    }
};

class XORLinkedList {
private:
    Node* XOR(Node* node1, Node* node2) {
        return (Node*)((uintptr_t)node1 ^ (uintptr_t)node2);
    }

public:
    Node* head;
    Node* tail;

    XORLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data); 
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->both = XOR(tail->both, newNode);
            newNode->both = tail;
            tail = newNode;
        }
    }

    int get(int idx) {
        Node* iter = head;
        Node* prev = nullptr;
        Node* next;
        int i = 0;
        while (i < idx) {
            next = XOR(iter->both, prev);
            prev = iter;
            iter = next;
            if (iter == nullptr) {
                throw "Index out of range";
            }
            i++;
        }
        return iter->data;
    }

    void print() {
        Node* iter = head;
        Node* prev = nullptr;
        Node* next;
        while (iter != nullptr) {
            cout << iter->data << " ";
            next = XOR(iter->both, prev);
            prev = iter;
            iter = next;
        }
        cout << endl;
    }
};

int main() {
    XORLinkedList l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.print();
    cout << l.get(0) << endl;
    cout << l.get(2) << endl;
    cout << l.get(4) << endl;
}