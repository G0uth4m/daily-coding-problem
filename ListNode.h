#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

#endif