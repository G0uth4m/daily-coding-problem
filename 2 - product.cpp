/*
This problem was asked by Uber.

Given an array of integers, return a new array such that 
each element at index i of the new array is the 
product of all the numbers in the original array except the one at i.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n)
vector<int> products(vector<int> A) {
    int product = 1;
    int num_zeroes = 0;
    for (int i=0; i<A.size(); i++) {
        if (A[i] == 0) {
            num_zeroes++;
        } else {
            product *= A[i];
        }
    }

    if (num_zeroes > 1) {
        vector<int> res(A.size(), 0);
        return res;
    }

    vector<int> res;
    for (int i=0; i<A.size(); i++) {
        if (A[i] == 0) {
            res.push_back(product);
        } else {
            if (num_zeroes == 0) {
                res.push_back(product/A[i]);
            } else {
                res.push_back(0);
            }
        }
    }
    return res;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

// O(n); O(n)
vector<int> products2(vector<int> A) {
    vector<int> left_products(A.size());
    vector<int> right_products(A.size());
    vector<int> res(A.size());

    left_products[0] = 1;
    right_products[A.size() - 1] = 1;
    for (int i=0; i<A.size() - 1; i++) {
        left_products[i + 1] = left_products[i] * A[i];
    }
    print(left_products);

    for (int i=A.size()-1; i>=1; i--) {
        right_products[i - 1] = right_products[i] * A[i];
    }
    print(right_products);

    for (int i=0; i<left_products.size(); i++) {
        res[i] = left_products[i] * right_products[i];
    }
    return res;
}

// O(n); O(1)
vector<int> products3(vector<int> A) {
    vector<int> res(A.size());

    res[0] = 1;
    for (int i=0; i<A.size() - 1; i++) {
        res[i + 1] = res[i] * A[i];
    }

    int r = 1;
    for (int i=A.size()-1; i>=0; i--) {
        res[i] *= r;
        r *= A[i];
    }
    return res;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> res = products3(A);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}