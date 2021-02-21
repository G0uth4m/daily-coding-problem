/*
This problem was asked by Google.

Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

void append(ListNode* &head, ListNode* &tail, ListNode* node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

// O(n); O(1)
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            append(head, tail, l1);
            l1 = l1->next;
        } else {
            append(head, tail, l2);
            l2 = l2->next;
        }
    }

    while (l1) {
        append(head, tail, l1); 
        l1 = l1->next;
    }

    while (l2) {
        append(head, tail, l2);
        l2 = l2->next;
    }

    return head;
}

// O(n)
pair<ListNode*, ListNode*> partition(ListNode* head) {
    ListNode* fast = head;
    ListNode* prevSlow = nullptr;
    ListNode* slow = head;

    while (fast && fast->next) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prevSlow->next = nullptr;
    return {head, slow};
}

// O(n logn); O(logn) stack space
ListNode* mergeSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    pair<ListNode*, ListNode*> p = partition(head);
    ListNode* leftSorted = mergeSort(p.first);
    ListNode* rightSorted = mergeSort(p.second);

    return merge(leftSorted, rightSorted);
}

void sort(ListNode* &head) {
    head = mergeSort(head);
}

void print(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(-3);
    ListNode* node4 = new ListNode(99);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    sort(node1);
    print(node1);
}