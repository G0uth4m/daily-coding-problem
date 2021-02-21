/*
This problem was asked by Amazon.

Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x Ordering within a part can be arbitrary.
For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14]
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n); O(n)
void partition(vector<int>& nums, int pivot) {
    vector<int> temp(nums.size());
    int k = 0;
    for (int i : nums) {
        if (i < pivot) {
            temp[k++] = i;
        }
    }
    for (int i : nums) {
        if (i == pivot) {
            temp[k++] = i;
        }
    }
    for (int i : nums) {
        if (i > pivot) {
            temp[k++] = i;
        }
    }
    nums = temp;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {9, 12, 3, 5, 14, 10, 10};
    partition(A, 10);
    print(A);
}