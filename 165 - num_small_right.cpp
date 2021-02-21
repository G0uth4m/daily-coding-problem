/*
This problem was asked by Google.

Given an array of integers, return a new array where each element in the new array 
is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// O(n^2)
vector<int> numSmallRight(vector<int>& A) {
    vector<int> res;
    for (int i=0; i<A.size(); i++) {
        int curr = 0;
        for(int j=i+1; j<A.size(); j++) {
            if (A[j] < A[i]) {
                curr++;
            }
        }
        res.push_back(curr);
    }
    return res;
}

class Node {
public:
    int data;
    int count;
    Node* left;
    Node* right;

    Node(int data, int count) {
        this->data = data;
        this->count = count;
        left = nullptr;
        right = nullptr;
    }
};

int addNode(Node* &root, int data, int countSmaller) {
    if (root == nullptr) {
        root = new Node(data, 0);
        return countSmaller;
    }
    if (root->data < data) {
        return root->count + addNode(root->right, data, countSmaller + 1);
    }
    root->count++;
    return addNode(root->left, data, countSmaller);
}

// O(n log n); O(n)
vector<int> numSmallRight2(vector<int>& A) {
    Node* root = nullptr;
    vector<int> res(A.size(), 0);

    for (int i=A.size()-1; i>=0; i--) {
        res[i] = addNode(root, A[i], 0);
    }
    return res;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {3, 4, 9, 6, 1};
    vector<int> res = numSmallRight2(A);
    print(res);
}