#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

// O(n*k)
vector<int> max_of_subarrays(vector<int> A, int k) {
    vector<int> res;
    for (int i=0; i<=A.size() - k; i++) {
        res.push_back(*max_element(A.begin() + i, A.begin() + i + k));
    }
    return res;
}

// O(k + (n-k)logk); O(k)
vector<int> max_of_subarrays2(vector<int> A, int k) {
    multiset<int> set;
    for (int i=0; i<k; i++) {
        set.insert(A[i]);
    }
    vector<int> res = {*set.rbegin()};
    for (int i=k; i<A.size(); i++) {
        set.erase(set.lower_bound(A[i - k]));
        set.insert(A[i]);
        res.push_back({*set.rbegin()});
    }
    return res;
}

int main() {
    vector<int> A = {10, 5, 2, 7, 8, 7};
    vector<int> res = max_of_subarrays2(A, 3);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}