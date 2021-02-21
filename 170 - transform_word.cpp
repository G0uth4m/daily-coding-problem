/*
This problem was asked by Facebook.

Given a start word, an end word, and a dictionary of valid words, 
find the shortest transformation sequence from start to end 
such that only one letter is changed at each step of the sequence, 
and each transformed word exists in the dictionary. 
If there is no possible transformation, return null. 
Each word in the dictionary have the same length as start and end and is lowercase.

For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"}, return ["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"}, 
return null as there is no possible transformation from dog to cat.
*/

#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

bool isEditDistanceOne(string& s1, string& s2) {
    bool foundMismatch = false;
    for (int i=0; i<s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (foundMismatch) {
                return false;
            }
            foundMismatch = true;
        }
    }
    return true;
}

int gettransformationSequence(unordered_set<string>& dictionary, string& start, string& end) {
    if (dictionary.find(end) == dictionary.end()) {
        return 0;
    }

    queue<string> q;
    q.push(start);

    int level = 0;
    while (!q.empty()) {
        level++;
        int x = q.size();
        while (x--) {
            string word = q.front();
            q.pop();
            bool flag = false;
            for (int pos=0; pos<start.size(); pos++) {
                char temp = word[pos];
                for (char c='a'; c<='z'; c++) {
                    word[pos] = c;
                    if (word == end) {
                        return level + 1;
                    }
                    if (dictionary.find(word) != dictionary.end()) {
                        flag = true;
                        dictionary.erase(word);
                        q.push(word);
                    }
                }
                word[pos] = temp;
            }
        }
    }
    return level;
}

int main() {
    unordered_set<string> dictionary = {"hot","dot","dog","lot","log","cog"};
    string start = "hit";
    string end = "cog";
    cout <<  gettransformationSequence(dictionary, start, end) << endl;
}