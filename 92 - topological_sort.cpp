/*
This problem was asked by Airbnb.

We're given a hashmap associating each courseId key with a list of courseIds values, 
which represents that the prerequisites of courseId are courseIds. 
Return a sorted ordering of courses such that we can finish all courses.

Return null if there is no such ordering.

For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []}, 
should return ['CSC100', 'CSC200', 'CSCS300'].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<string> topological_sort(unordered_map<string, vector<string>>& map) {
    unordered_map<string, bool> visited;
    for (auto i : map) {
        visited[i.first] = false;
    }
    vector<string> res;
    while (res.size() != map.size()) {
        string course = "";
        for (auto i : map) {
            if (visited[i.first] == false) {
                bool flag = true;
                for (auto j : i.second) {
                    if (visited[j] == false) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    course = i.first;
                    res.push_back(course);
                    visited[i.first] = true;
                }
            }
        }
        if (course == "") {
            return {};
        }
    }
    return res;
}

void print(vector<string>& A) {
    for (string i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    unordered_map<string, vector<string>> map = {
        {"CSC300", {"CSC100", "CSC200"}},
        {"CSC200", {"CSC100"}},
        {"CSC100", {}},
        {"CSC400", {}}
    };

    vector<string> res = topological_sort(map);
    print(res);
}