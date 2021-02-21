/*
his problem was asked by Amazon.

Given an integer k and a string s, 
find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, 
the longest substring with k distinct characters is "bcb".
*/

#include <iostream>
#include <unordered_map>
using namespace std;

string longest_substring_with_atmost_k_distinct_chars(string s, int k) {
    int j = 0;
    unordered_map<char, int> map;
    string res = "";
    int resu = 0;
    for (int i=0; i<s.size(); i++) {
        map[s[i]]++;

        if (map.size() <= k) {
            resu = max(resu, i - j + 1);
            res = s.substr(j, resu);
        } else {
            while (map.size() > k) {
                if (map[s[j]] == 1) {
                    map.erase(s[j]);
                } else {
                    map[s[j]]--;
                }
                j++;
            }
        }
    }
    return res;
}

int main() {
    string s = "abcb";
    cout << longest_substring_with_atmost_k_distinct_chars(s, 2) << endl;
}