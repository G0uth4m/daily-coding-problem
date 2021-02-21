/*
This problem was asked by Dropbox.

Given a string s and a list of words words, where each word is the same length, 
find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], 
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], 
return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
*/

#include <iostream>
#include <vector>
using namespace std;

int rollHash(string& s, int left, int right) {
    int p = 31;
    int res = 0;
    int poww = 1;
    for (int i=left; i<right; i++) {
        res += (s[i] - 'a' + 1)*poww;
        poww *= p;
    }
    return res;
}

bool isComposition(string& s, int left, int right, int hashSum, int wordSize) {
    int currHashSum = 0;
    for (int i=left; i<right; i+=wordSize) {
        currHashSum += rollHash(s, i, i + wordSize);
        if (currHashSum > hashSum) {
            return false;
        }
    }
    return currHashSum == hashSum;
}

vector<int> substrings2(string& s, vector<string>& words) {
    int wordSize = words[0].size(); // 3
    int composedWordsSize = words.size()*words[0].size(); // 6

    int hashSum = 0;
    for (string& word : words) {
        hashSum += rollHash(word, 0, wordSize);
    }

    vector<int> res;
    for (int i=0; i<s.size()-composedWordsSize+1; i++) {
        if (isComposition(s, i, i + composedWordsSize, hashSum, wordSize)) {
            res.push_back(i);
        }
    }
    return res;
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    string s = "dogcatcatcodecatdog";
    vector<string> words = {"dog", "cat"};
    vector<int> res = substrings2(s, words);
    print(res);
}