/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// O(n)
int helper(string s, int i, unordered_map<int, int>* cache) {
    if (cache->find(i) != cache->end()) {
        return cache->at(i);
    }
    if (i == s.size()) {
        return 1;
    }
    if (i > s.size()) {
        return 0;
    }
    int to_return = helper(s, i + 1, cache);
    if (i <= s.size() - 2 && stoi(s.substr(i, 2)) <= 26) {
        to_return += helper(s, i + 2, cache);
    }
    cache->insert({i, to_return});
    return to_return;
}

int numWays(string s) {
    unordered_map<int, int> cache;
    return helper(s, 0, &cache);
}

int main() {
    cout << numWays("111") << endl;
}