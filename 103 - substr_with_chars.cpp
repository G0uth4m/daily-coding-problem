/*
Given a string and a set of characters, return the shortest substring containing all the characters in the set.

For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".

If there is no substring containing all the characters in the set, return null.
*/

#include <iostream>
#include <vector>
using namespace std;

string sub_string(string s, string t) {
    if (s.size() < t.size()) {
        return "";
    }
    vector<int> s_set(256, 0);
    vector<int> t_set(256, 0);

    for (char c : t) {
        t_set[c]++;
    }

    int start = 0;
    int start_idx = -1;
    int min_len = INT32_MAX;
    int count = 0;
    for (int i=0; i<s.size(); i++) {
        s_set[s[i]]++;

        if (t_set[s[i]] != 0 && s_set[s[i]] <= t_set[s[i]]) {
            count++;
        }

        if (count == t.size()) {
            while (s_set[s[start]] > t_set[s[start]] || t_set[s[start]] == 0) {
                if (s_set[s[start]] > t_set[s[start]]) {
                    s_set[s[start]]--;
                }
                start++;
            }
            if (i - start + 1 < min_len) {
                min_len = i - start + 1;
                start_idx = start;
            }
        }
    }
    return start_idx == -1 ? "" : s.substr(start_idx, min_len);
}

int main() {
    cout << sub_string("figehaeci", "aei") << endl;
}