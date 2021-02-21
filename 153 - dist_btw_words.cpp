/*
Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", 
return 1 because there's only one word "cat" in between the two words.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> find_all(string& sentence, string& word) {
    vector<int> res;

    int pos = sentence.find(word, 0);
    while (pos != string::npos) {
        res.push_back(pos);
        pos = sentence.find(word, pos + 1);
    }

    return res;
}

int num_words(string& sentence, int left, int right) {
    int res = 0;
    while (left < right) {
        if (sentence[left++] == ' ') {
            res++;
        }
    }
    return res;
}

int dist_btw_words(string sentence, string word1, string word2) {
    vector<int> word1_pos = find_all(sentence, word1);
    vector<int> word2_pos = find_all(sentence, word2);

    int res = INT32_MAX;
    for (int i=0; i<word1_pos.size(); i++) {
        for (int j=0; j<word2_pos.size(); j++) {
            int left, right;
            if (word1_pos[i] < word2_pos[j]) {
                left = word1_pos[i] + word1.size() + 1;
                right = word2_pos[j];
            } else {
                left = word2_pos[j] + word2.size() + 1;
                right = word1_pos[i];
            }
            int nw = num_words(sentence, left, right);
            res = min(res, nw);
        }
    }
    return res;
}

int main() {
    cout << dist_btw_words("dog cat hello cat dog dog hello cat world", "hello", "world") << endl;
}