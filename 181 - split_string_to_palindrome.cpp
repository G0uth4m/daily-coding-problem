/*
This problem was asked by Google.

Given a string, split it into as few strings as possible such that each string is a palindrome.

For example, given the input string "racecarannakayak", return ["racecar", "anna", "kayak"].

Given the input string "abc", return ["a", "b", "c"].
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string& s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

void backtrack(int start, vector<string>& res, vector<string>& curr, string& s) {
    if (start >= s.size()) {
        if (res.empty() || curr.size() < res.size()) {
            res = curr;
        }
    }
    for (int end=start; end<s.size(); end++) { 
        if (isPalindrome(s, start, end)) {
            curr.push_back(s.substr(start, end - start + 1));
            backtrack(end + 1, res, curr, s);
            curr.pop_back();
        }
    }
}

vector<string> minPalindromePartition(string s) {
    vector<string> res;
    vector<string> curr;
    backtrack(0, res, curr, s);
    return res;
}

void print(vector<string>& A) {
    for (string& s : A) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<string> res1 = minPalindromePartition("racecarannakayak");
    vector<string> res2 = minPalindromePartition("abc");
    vector<string> res3 = minPalindromePartition("aab");

    print(res1);
    print(res2);
    print(res3);
}