/*
/*
This problem was asked by Airbnb.

Given a linked list and a positive integer k, rotate the list to the right by k places.

For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.

Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

pair<int, ListNode*> sizeAndTail(ListNode* head) {
    int res = 0;
    ListNode* prev = nullptr;
    while (head) {
        res++;
        prev = head;
        head = head->next;
    }
    return {res, prev};
}

ListNode* rotate(ListNode* head, int k) {
    pair<int, ListNode*> p = sizeAndTail(head);
    k = p.first - k;
    ListNode* tail = p.second;

    while (k--) {
        tail->next = head;
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        tail = temp;
    }
    return head;
}

void print(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
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

    ListNode* res = rotate(node1, 3);
    print(res);
}