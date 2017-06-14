// LC 67, add binary 
// Given two binary strings, return their sum (also a binary string).
// a = "11"
// b = "1"
// Return "100".

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string res;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        carry += i >= 0 ? a[i--] - '0' : 0;
        carry += j >= 0 ? b[j--] - '0' : 0;
        res = char(carry % 2 + '0') + res;
        carry /= 2;
    }
    return res;
}

int main() {
    vector<string> strs1 = {"11","10"};
    vector<string> strs2 = {"1","11"};
    vector<string> exps = {"100","101"};
    for (int i = 0; i < strs1.size(); i++) {
        string res = addBinary(strs1[i], strs2[i]);
        printf("test %d, res: %s\n", i + 1, res.c_str());
        assert(res == exps[i]);
    }
    return 0;
}