/*
This problem was asked by Google.

We can determine how "out of order" an array A is by counting the number of inversions it has. 
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. 
That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. 
The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). 
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> A, vector<int> B, int* inversion_count) {
    vector<int> res;
    int i = 0;
    int j = 0;
    while (i < A.size() || j < B.size()) {
        if (i >= A.size()) {
            res.push_back(B[j++]);
        } else if (j >= B.size()) {
            res.push_back(A[i++]);
        } else {
            if (A[i] <= B[j]) {
                res.push_back(A[i++]);
            } else {
                (*inversion_count)+=(A.size() - i);
                res.push_back(B[j++]);
            }
        }
    }
    return res;
}

vector<int> merge_sort(vector<int> A, int* inversion_count) {
    if (A.size() == 1) {
        return A;
    }
    int mid = A.size()/2;
    vector<int> left(A.begin(), A.begin() + mid);
    vector<int> right(A.begin() + mid, A.end());
    vector<int> left_sorted = merge_sort(left, inversion_count);
    vector<int> right_sorted = merge_sort(right, inversion_count);
    return merge(left_sorted, right_sorted, inversion_count);
}

// O(NlogN)
int no_of_inversions(vector<int> A) {
    int res = 0;
    vector<int> sorted_arr = merge_sort(A, &res);
    return res;
}

int main() {
    cout << no_of_inversions({2, 4, 1, 3, 5}) << endl;
    cout << no_of_inversions({5, 4, 3, 2, 1}) << endl;
    cout << no_of_inversions({1, 2, 3, 4, 5}) << endl;
}