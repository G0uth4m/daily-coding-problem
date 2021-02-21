/*
This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. 
That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void insert_to_sorted_arr(vector<int>& A, int num) {
    int idx = lower_bound(A.begin(), A.end(), num) - A.begin();
    A.insert(A.begin() + idx, num);
}

// O(n^2); O(n)
vector<double> running_median(vector<int> A) {
    vector<double> res;
    vector<int> temp;
    for (int i=0; i<A.size(); i++) {
        insert_to_sorted_arr(temp, A[i]);
        if (temp.size() % 2 == 1) {
            res.push_back(temp[temp.size()/2]);
        } else {
            res.push_back((temp[temp.size()/2] + temp[temp.size()/2 - 1])/2.0);
        }
    }
    return res;
}

// O(nlogn); O(n)
vector<double> running_median2(vector<int> A) {
    vector<double> res;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i=0; i<A.size(); i++) {
        max_heap.push(A[i]);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        if (max_heap.size() > min_heap.size()) {
            res.push_back(max_heap.top());
        } else {
            res.push_back((max_heap.top() + min_heap.top())/2.0);
        }
    }
    return res;
}

void print(vector<double> A) {
    for (auto i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {2, 1, 5, 7, 2, 0, 5};
    vector<double> res = running_median2(A);
    print(res);
}