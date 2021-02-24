/*
This problem was asked by LinkedIn.

Given a linked list of numbers and a pivot k, 
partition the linked list so that all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3, 
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

void append(pair<ListNode*, ListNode*>& list, ListNode* node) {
    if (list.first == nullptr) {
        list.first = node;
        list.second = node;
    } else {
        list.second->next = node;
        list.second = node;
    }
}

// O(n); O(1)
ListNode* partition(ListNode* head, int pivot) {
    pair<ListNode*, ListNode*> list1 = {nullptr, nullptr};
    pair<ListNode*, ListNode*> list2 = {nullptr, nullptr};

    while (head) {
        ListNode* node = head;
        head = head->next;
        node->next = nullptr;
        if (node->data < pivot) {
            append(list1, node);
        } else {
            append(list2, node);
        }
    }
    if (list1.first == nullptr) {
        return list2.first;
    }
    list1.second->next = list2.first;
    return list1.first;
}

void print(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(5);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(8);
    ListNode* node4 = new ListNode(0);
    ListNode* node5 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* res = partition(node1, 3);
    print(res);
}
