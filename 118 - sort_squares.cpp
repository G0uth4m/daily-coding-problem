/*
This problem was asked by Google.

Given a sorted list of integers, square the elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
4 81 0 4 9
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// O(n)
vector<int> merge(vector<int>& A, vector<int>& B) {
    int i = 0;
    int j = 0;
    vector<int> res;
    while (i < A.size() || j < B.size()) {
        if (i >= A.size()) {
            res.push_back(B[j++]);
        } else if (j >= B.size()) {
            res.push_back(A[i++]);
        } else {
            if (A[i] < B[j]) {
                res.push_back(A[i++]);
            } else {
                res.push_back(B[j++]);
            }
        }
    }
    return res;
}

void square_array(vector<int>& A) {
    for (int& i : A) {
        i = i * i;
    }
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

// O(n); O(n)
vector<int> sort_squares(vector<int>& A) {
    int first_positive_idx = 0;
    while(A[first_positive_idx] < 0) {
        first_positive_idx++;
    }
    vector<int> neg_vals(A.begin(), A.begin() + first_positive_idx);
    reverse(neg_vals.begin(), neg_vals.end());
    vector<int> pos_vals(A.begin() + first_positive_idx, A.end());

    square_array(neg_vals);
    square_array(pos_vals);

    return merge(neg_vals, pos_vals);
}

// O(n); O(n)
vector<int> sort_squares2(vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;
    vector<int> res(A.size());
    int k = res.size() - 1;
    while (left < right) {
        if (abs(A[left]) > abs(A[right])) {
            res[k--] = pow(A[left++], 2);
        } else {
            res[k--] = pow(A[right--], 2);
        }
    }
    res[k] = pow(A[left], 2);
    return res;
}

int main() {
    vector<int> A = {-9, -2, 0, 2, 3};
    vector<int> res = sort_squares2(A);
    print(res);
}