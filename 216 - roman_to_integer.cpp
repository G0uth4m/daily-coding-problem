/*
This problem was asked by Facebook.

Given a number in Roman numeral format, convert it to decimal.

The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}

In addition, note that the Roman numeral system uses subtractive notation for numbers such as IV and XL.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(n); O(1)
int romanToInt(string s) {
    vector<int> map(22);
    map['M' - 'C'] = 1000;
    map['D' - 'C'] = 500;
    map['C' - 'C'] = 100;
    map['L' - 'C'] = 50;
    map['X' - 'C'] = 10;
    map['V' - 'C'] = 5;
    map['I' - 'C'] = 1;
    
    int res = 0;
    int prev = 0;
    for (int i=s.size()-1; i>=0; i--) {
        int curr = map[s[i] - 'C'];
        if (curr < prev) {
            res -= curr;
        } else {
            res += curr;
        }
        prev = curr;
    }
    return res;
}

int main() {
    cout << romanToInt("MCMXCIV") << endl;
}
