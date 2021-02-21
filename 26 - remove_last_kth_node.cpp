/*
This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. 
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void remove_last_kth_node(Node* head, int k) {
    Node* iter1 = head;
    int i = 0;
    while (i < k) {
        iter1 = iter1->next;
        i++;
    }
    Node* iter2 = head;
    Node* prev = nullptr;
    while (iter1) {
        iter1 = iter1->next;
        prev = iter2;
        iter2 = iter2->next;
    }
    prev->next = iter2->next;
    free(iter2);
}

void print(Node* head) {
    Node* iter = head;
    while (iter) {
        cout << iter->data << " ";
        iter = iter->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    print(node1);
    remove_last_kth_node(node1, 1);
    print(node1);
}