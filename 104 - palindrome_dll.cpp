/*
This problem was asked by Google.

Determine whether a doubly linked list is a palindrome. What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns true while 1 -> 4 returns false.
*/

#include <iostream>
using namespace std;

class DoublyListNode {
public:
    int data;
    DoublyListNode* prev;
    DoublyListNode* next;

    DoublyListNode(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

bool is_palindrome(DoublyListNode* head) {
    DoublyListNode* tail = head;
    int len = 1;
    while (tail->next) {
        len++;
        tail = tail->next;
    }
    int i = 0;
    while (i++ < len/2) {
        if (head->data != tail->data) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

class SinglyListNode {
public:
    int data;
    SinglyListNode* next;

    SinglyListNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

void reverse(SinglyListNode* &head) {
    SinglyListNode* prev = nullptr;
    SinglyListNode* curr = head;
    SinglyListNode* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

pair<SinglyListNode*, SinglyListNode*> partition(SinglyListNode* head) {
    SinglyListNode* prev_slow = nullptr;
    SinglyListNode* slow = head;
    SinglyListNode* fast = head;
    while (fast && fast->next) {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev_slow->next = nullptr;
    return {head, slow};
}

bool is_palindrome(SinglyListNode* head) {
    pair<SinglyListNode*, SinglyListNode*> p = partition(head);
    reverse(p.second);
    SinglyListNode* iter1 = p.first;
    SinglyListNode* iter2 = p.second;

    while (iter1 && iter2) {
        if (iter1->data != iter2->data) {
            return false;
        }
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    return true;
}

int main() {
    DoublyListNode* node1 = new DoublyListNode(1);
    DoublyListNode* node2 = new DoublyListNode(4);
    DoublyListNode* node3 = new DoublyListNode(3);
    DoublyListNode* node4 = new DoublyListNode(4);
    DoublyListNode* node5 = new DoublyListNode(1);

    node1->next = node2;

    node2->next = node3;
    node2->prev = node1;

    node3->next = node4;
    node3->prev = node2;

    node4->next = node5;
    node4->prev = node3;

    node5->prev = node4;

    cout << is_palindrome(node1) << endl;

    SinglyListNode* n1 = new SinglyListNode(1);
    SinglyListNode* n2 = new SinglyListNode(4);
    SinglyListNode* n3 = new SinglyListNode(3);
    SinglyListNode* n4 = new SinglyListNode(4);
    SinglyListNode* n5 = new SinglyListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << is_palindrome(n1) << endl;
}