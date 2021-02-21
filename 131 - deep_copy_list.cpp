/*
This question was asked by Snapchat.

Given the head to a singly linked list, 
where each node also has a 'random' pointer that points to anywhere in the linked list, deep clone the list.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode* random;

    ListNode(int data) {
        this->data = data;
        next = nullptr;
        random = nullptr;
    }
};

ListNode* deep_copy(ListNode* head) {
    unordered_map<ListNode*, ListNode*> map;
    
    ListNode* iter = head;
    while (iter) {
        map[iter] = new ListNode(iter->data);
        iter = iter->next;
    }

    iter = head;
    while (iter) {
        map[iter]->next = map[iter->next];
        map[iter]->random = map[iter->random];
        iter = iter->next;
    }
    return map[head];
}

void print(ListNode* head) {
    while (head) {
        cout << "(" << head->data << ", ";
        if (head->random) {
            cout << head->random->data << ") ";
        } else {
            cout << "nullptr)";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    ListNode* node1 = new ListNode(7);
    ListNode* node2 = new ListNode(13);
    ListNode* node3 = new ListNode(11);
    ListNode* node4 = new ListNode(10);
    ListNode* node5 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    ListNode* res = deep_copy(node1);
    print(res);
}