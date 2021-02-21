/*
This problem was asked by Microsoft.

Let's represent an integer in a linked list format by having each node represent a digit in the number. 
The nodes make up the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5 is the number 54321.

Given two linked lists in this format, return their sum in the same linked list format.

For example, given

9 -> 9 5 -> 2 return 124 (99 + 25) as:

4 -> 2 -> 1
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

void append(ListNode* &head, ListNode* &tail, int data) {
    ListNode* newNode = new ListNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

ListNode* add(ListNode* l1, ListNode* l2) {
    ListNode* res_head = nullptr;
    ListNode* res_tail = nullptr;
    bool carry = 0;
    while (l1 && l2) {
        int temp = l1->data + l2->data + carry;
        append(res_head, res_tail, temp % 10);
        carry = temp > 9;
        l1 = l1->next;
        l2 = l2->next;
    }
    l1 = l1 ? l1 : l2;
    while (l1) {
        int temp = l1->data + carry;
        append(res_head, res_tail, temp % 10);
        carry = temp > 9;
        l1 = l1->next;
    }
    if (carry) {
        append(res_head, res_tail, 1);
    }
    return res_head;
}

void print(ListNode* l) {
    while (l) {
        cout << l->data << " ";
        l1 = l1->next;
    }
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(9);
    ListNode* node2 = new ListNode(9);

    ListNode* node3 = new ListNode(5);
    ListNode* node4 = new ListNode(2);

    ListNode* res = add(node1, node2);
    print(res);
}