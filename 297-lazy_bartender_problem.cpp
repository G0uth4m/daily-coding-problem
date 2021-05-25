/*
This problem was asked by Amazon.

At a popular bar, each customer has a set of favorite drinks, 
and will happily accept any drink among this set. 
For example, in the following situation, 
customer 0 will be satisfied with drinks 0, 1, 3, or 6.

preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}

A lazy bartender working at this bar is trying to 
reduce his effort by limiting the drink recipes he must memorize. 
Given a dictionary input such as the one above, 
return the fewest number of drinks he must learn 
in order to satisfy all customers.

For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void makeColumnZero(vector<vector<int>>& A, int col) {
    for (int row=0; row<A.size(); row++) {
        if (A[row][col] == 1) {
            A[row][col] = 0;
            A[row][A[0].size() - 1]--;
        }
    }
}

int minDrinksToLearn(vector<vector<int>>& preferences, int numCustomers, int numDrinks) {
    vector<vector<int>> A(numDrinks, vector<int>(numCustomers + 1));
    for (int i=0; i<preferences.size(); i++) {
        for (int j=0; j<preferences[i].size(); j++) {
            A[preferences[i][j]][i] = 1;
            A[preferences[i][j]][numCustomers]++;
        }
    }

    int satisfiedCustomers = 0;
    int res = 0;
    while (satisfiedCustomers != numCustomers) {
        int maxi = 0;
        int maxiRow = 0;
        for (int i=0; i<numDrinks; i++) {
            if (A[i].back() > maxi) {
                maxi = A[i].back();
                maxiRow = i;
            }
        }
        satisfiedCustomers += maxi;
        for (int j=0; j<numCustomers; j++) {
            if (A[maxiRow][j] == 1) {
                makeColumnZero(A, j);
            }
        }
        res++;
    }
    return res;
}

int main() {
    vector<vector<int>> preferences = {
        {0, 1, 3, 6},
        {1, 4, 7},
        {2, 4, 7, 5},
        {3, 2, 5},
        {5, 8}
    };
    cout << minDrinksToLearn(preferences, 5, 9) << endl;
}
