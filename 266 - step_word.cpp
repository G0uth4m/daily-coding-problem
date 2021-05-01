/*
This problem was asked by Pivotal.

A step word is formed by taking a given word, adding a letter, and anagramming the result. 
For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word, create a function that returns all valid step words.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> constructCharSet(string& word) {
    vector<int> set(26);
    for (char c : word) {
        set[c - 'a']++;
    }
    return set;
}

vector<string> stepWords(string word, vector<string>& dictionary) {
    vector<int> wordCharSet = constructCharSet(word);
    vector<string> res;
    for (string& s : dictionary) {
        vector<int> sCharSet = constructCharSet(s);
        bool valid = false;
        for (int i=0; i<26; i++) {
            if (abs(sCharSet[i] - wordCharSet[i]) > 1) {
                valid = false;
                break;
            }
            if (sCharSet[i] - wordCharSet[i] == 1) {
                valid = true;
            }
        }
        if (valid) {
            res.push_back(s);
        }
    }
    return res;
}
