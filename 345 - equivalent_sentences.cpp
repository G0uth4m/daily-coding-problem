/*
This problem was asked by Google.

You are given a set of synonyms, such as (big, large) and (eat, consume). 
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."

Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c): 
consider the case of (coach, bus) and (coach, teacher).
*/

#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

bool isEquivalent(unordered_set<string>& synonyms, string& sentence1, string& sentence2) {
    stringstream s1(sentence1);
    stringstream s2(sentence2);

    string word1;
    string word2;

    while (s1 >> word1 && s2 >> word2) {
        if (word1 != word2 
            && synonyms.find(word1 + "#" + word2) == synonyms.end()
            && synonyms.find(word2 + "#" + word1) == synonyms.end()) {
                return false;
        }
    }
    return true;
}

int main() {
    unordered_set<string> synonyms = {"big#large", "eat#consume"};
    string sentence1 = "He wants to eat food";
    string sentence2 = "He wants to consume food";
    cout << isEquivalent(synonyms, sentence1, sentence2) << endl;
}
