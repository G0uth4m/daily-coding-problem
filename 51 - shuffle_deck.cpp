/*
This problem was asked by Facebook.

Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, 
write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*/

#include <iostream>
#include <vector>
using namespace std;

int randk(int k) {
    return 1 + (rand() % k);
}

void shuffle(vector<int>& deck) {
    for (int i=0; i<deck.size(); i++) {
        int r = i + randk(deck.size() - i);
        swap(deck[i], deck[r - 1]);
    }
}

void print(vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> deck(52);
    for (int i=1; i<=52; i++) {
        deck[i - 1] = i;
    }
    print(deck);
    shuffle(deck);
    print(deck);
}