#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* intersection(Node* head1, Node* head2) {
    int len1 = 0;
    Node* iter1 = head1;
    while (iter1) {
        len1++;
        iter1 = iter1->next;
    }

    int len2 = 0;
    Node* iter2 = head2;
    while (iter2) {
        len2++;
        iter2 = iter2->next;
    }
    iter1 = head1;
    iter2 = head2;

    if (len2 > len1) {
        swap(iter1, iter2);
    }

    int i = 0;
    while (i < abs(len1 - len2)) {
        iter1 = iter1->next;
        i++;
    }

    while (iter1) {
        if (iter1 == iter2) {
            return iter1;
        }
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    return nullptr;
}