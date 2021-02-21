#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Wrong - should use DP
vector<string> construct_sentence(unordered_set<string> dictionary, string s) {
    vector<string> res;
    int j = 0;
    for (int i=0; i<s.size(); i++) {
        if (dictionary.find(s.substr(j, i - j + 1)) != dictionary.end()) {
            res.push_back(s.substr(j, i - j + 1));
            j = i + 1;
        }
    }
    return res;
}

int main() {
    unordered_set<string> dictionary = {"bed", "bath", "bedbath", "and", "beyond"};
    string s = "bedbathandbeyond";
    vector<string> res = construct_sentence(dictionary, s);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}