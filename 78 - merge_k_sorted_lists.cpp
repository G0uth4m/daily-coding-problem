/*
This problem was asked by Google.

Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

// O(k)
ListNode* min_node(vector<ListNode*>& lists) {
    int res = INT32_MAX;
    for (auto i : lists) {
        if (i && i->data < res) {
            res = i->data;
        }
    }
    if (res == INT32_MAX) {
        return nullptr;
    }
    for (int i=0; i<lists.size(); i++) {
        if (lists[i] && lists[i]->data == res) {
            ListNode* temp = lists[i];
            lists[i] = lists[i]->next;
            temp->next = nullptr;
            return temp;
        }
    }
    return nullptr;
}

void push_back(ListNode* &head, ListNode* &tail, ListNode* &node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

// O(NK); O(1)
ListNode* merge(vector<ListNode*>& lists) {
    ListNode* resHead = nullptr;
    ListNode* resTail = nullptr;

    ListNode* mini = min_node(lists);
    while (mini) {
        push_back(resHead, resTail, mini);
        mini = min_node(lists);
    }
    return resHead;
}

// O(N log K); O(K)
ListNode* merge2(vector<ListNode*>& lists) {
    ListNode* resHead = nullptr;
    ListNode* resTail = nullptr;

    auto comp = [](ListNode* a, ListNode* b) {
        return a->data > b->data;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);

    for (auto i : lists) {
        if (i) min_heap.push(i);
    }
    while (!min_heap.empty()) {
        ListNode* temp = min_heap.top();
        min_heap.pop();
        if (temp->next) {
            min_heap.push(temp->next);
        }
        temp->next = nullptr;
        push_back(resHead, resTail, temp);
    }
    return resHead;
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
    ListNode* node1 = new ListNode(7);
    ListNode* node2 = new ListNode(8);
    ListNode* node3 = new ListNode(9);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(2);
    ListNode* node6 = new ListNode(3);
    ListNode* node7 = new ListNode(4);
    ListNode* node8 = new ListNode(5);
    ListNode* node9 = new ListNode(6);

    node1->next = node2;
    node2->next = node3;

    node4->next = node5;
    node5->next = node6;

    node7->next = node8;
    node8->next = node9;

    vector<ListNode*> lists = {node1, node4, node7};
    ListNode* res = merge2(lists);
    print(res);
}