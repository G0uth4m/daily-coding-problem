/*
This problem was asked by Yelp.

Given a mapping of digits to letters (as in a phone number), and a digit string, 
return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then 
“23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> possibilities(string num) {
    if (num == "") {
        return {};
    }

    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res = {""};

    for (int i=0; i<num.size(); i++) {
        int x = res.size();
        for (int j=0; j<x; j++) {
            for (int k=0; k<map[num[i] - '0'].size(); k++) {
                string temp = res[0];
                temp.push_back(map[num[i] - '0'][k]);
                res.push_back(temp);
            }
            res.erase(res.begin());
        }
    }
    return res;
}

void print(vector<string> A) {
    for (auto i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<string> res = possibilities("23");
    print(res);
}