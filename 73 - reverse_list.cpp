/*
This problem was asked by Google.

Given the head of a singly linked list, reverse it in-place.
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

void reverse_list(ListNode* &head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void print(ListNode* head) {
    ListNode* iter = head;
    while (iter) {
        cout << iter->data << " ";
        iter = iter->next;
    }
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    print(node1);
    reverse_list(node1);
    print(node1);
}