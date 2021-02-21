/*
This problem was asked by Google.

Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4 -> 5 -> 6, return 2 -> 1 -> 4 -> 3 -> 6 -> 5.
*/

#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

// O(n); O(n)
ListNode* swap_adj_nodes(ListNode* head) {
    vector<ListNode*> A;
    while (head && head->next) {
        A.push_back(head);
        head = head->next->next;
    }

    for (ListNode* &i : A) {
        i->next->next = i;
    }

    ListNode* res = A[0]->next;
    for (int i=0; i<A.size()-1; i++) {
        A[i]->next = A[i + 1]->next;
    }
    A.back()->next = nullptr;

    return res;
}

// O(n); O(1)
ListNode* swap_adj_nodes2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* res = head->next;
    while (head && head->next && head->next->next && head->next->next->next) {
        ListNode* temp = head->next->next;
        head->next->next = head;
        head->next = temp->next;
        head = temp;
    }
    ListNode* temp = head->next->next;
    head->next->next = head;
    head->next = temp;
    return res;
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
    ListNode* node6 = new ListNode(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    print(node1);
    ListNode* res = swap_adj_nodes2(node1);
    print(res);
}