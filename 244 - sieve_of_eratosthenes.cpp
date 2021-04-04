/*
This problem was asked by Square.

The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N. 
The method is to take increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would first mark [4, 6, 8, ...] (multiples of two), 
then [6, 9, 12, ...] (multiples of three), and so on. 
Once we have done this for all primes less than N, the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely (that is, without taking N as an input).
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n log(log n))
vector<int> primes(int N) {
    vector<bool> prime(N + 1, true);

    for (int i=2; i*i<=N; i++) {
        if (prime[i]) {
            for (int j=i*i; j<=N; j+=i) {
                prime[j] = false;
            }
        }
    }
    vector<int> res;
    for (int i=2; i<prime.size(); i++) {
        if (prime[i]) {
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
    vector<int> res = primes(30);
    print(res);
}