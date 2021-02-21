/*
This problem was asked by Apple.

Suppose you have a multiplication table that is N by N. That is, a 2D array where the value at the i-th row and j-th column is 
(i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).

Given integers N and X, write a function that returns the number of times X appears as a value in an N by N multiplication table.

For example, given N = 6 and X = 12, you should return 4, since the multiplication table looks like this:

| 1 | 2 | 3 | 4 | 5 | 6 |

| 2 | 4 | 6 | 8 | 10 | 12 |

| 3 | 6 | 9 | 12 | 15 | 18 |

| 4 | 8 | 12 | 16 | 20 | 24 |

| 5 | 10 | 15 | 20 | 25 | 30 |

| 6 | 12 | 18 | 24 | 30 | 36 |

And there are 4 12's in the table.
*/
// Alter question - number of factors of X which are less than or equal to N.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// O(N^2)
int frequency(int N, int X) {
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if ((i + 1) * (j + 1) == X) {
                res++;
            }
        }
    }
    return res;
}

// O(N)
int frequency2(int N, int X) {
    if (X > N*N || X < 1) {
        return 0;
    }
    int res = 0;
    for (int i=1; i<=sqrt(X); i++) {
        if (X % i == 0 && i <= N && (X/i) <= N) {
            if (i == (X/i)) {
                res++;
            } else {
                res += 2;
            }
        }
    }
    return res;
}

int main() {
    cout << frequency2(6, 12) << endl;
}