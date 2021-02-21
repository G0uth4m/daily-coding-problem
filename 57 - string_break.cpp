/*
This problem was asked by Amazon.

Given a string s and an integer k, break up the string into multiple lines such that 
each line has a length of k or less. You must break it up so that words don't break across lines. 
Each line has to have the maximum possible amount of words. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, 
you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. 
No string in the list has a length of more than 10.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> break_string(string s, int K) {
    int i = 0;
    int c = 0;
    int j = 0;
    int k = 0;
    vector<string> res;
    while (i < s.size() - 1) {
        c++;
        if (s[i + 1] == ' ') {
            k = i;
        }
        if (c == K) {
            if (s[i + 1] == ' ') {
                res.push_back(s.substr(j, i - j + 1));
                i = i + 2;
                j = i;
                c = 0;
            } else {
                res.push_back(s.substr(j, k - j + 1));
                i = k + 2;
                j = i;
                c = 0;
            }
        } else {
            i++;
        }
    }
    res.push_back(s.substr(j, i - j + 1));
    return res;
}

void print(vector<string>& A) {
    for (auto i : A) {
        cout << '`' << i  << '`' << endl;
    }
}

int main() {
    vector<string> res = break_string("the quick brown fox jumps over the lazy dog", 9);
    print(res);
}