/*
This problem was asked by Snapchat.

Given a string of digits, generate all possible valid IP address combinations.

IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers between 0 and 255. 
Zero-prefixed numbers, such as 01 and 065, are not allowed, except for 0 itself.

For example, given "2542540123", you should return ['254.25.40.123', '254.254.0.123'].
*/

#include <iostream>
#include <vector>
using namespace std;

int convertToInt(string& s, int start, int end) {
    int res = 0;
    for (int i=start; i<=end; i++) {
        res = (res * 10) + (s[start] - '0');
    }
    return res;
}

bool isValidBlock(string& s, int start, int end) {
    int blockSize = end - start + 1;
    if (blockSize > 3) {
        return false;
    }
    if (blockSize > 1 && s[start] == '0') {
        return false;
    }
    int blockInt = convertToInt(s, start, end);
    return blockInt >= 0 && blockInt <= 255;
}

bool isValid(string& s, int i, int j, int k) {
    return isValidBlock(s, 0, i)
        && isValidBlock(s, i + 1, j)
        && isValidBlock(s, j + 1, k)
        && isValidBlock(s, k + 1, s.size()-1);
}

string constructIp(string s, int i, int j, int k) {
    s.insert(s.begin() + k + 1, '.');
    s.insert(s.begin() + j + 1, '.');
    s.insert(s.begin() + i + 1, '.');
    return s;
}

vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4) {
        return {};
    }
    vector<string> res;
    for (int i=0; i<s.size()-3; i++) {
        for (int j=i+1; j<s.size()-2; j++) {
            for (int k=j+1; k<s.size()-1; k++) {
                if (isValid(s, i, j, k)) {
                    res.push_back(constructIp(s, i, j, k));
                }
            }
        }
    }
    return res;
}

void print(vector<string>& A) {
    for (string& s : A) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<string> res1 = restoreIpAddresses("2542540123");
    vector<string> res2 = restoreIpAddresses("25525511135");
    print(res1);
    print(res2);
}
