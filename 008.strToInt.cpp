// LC 8, string to integer (atoi)
// return INT_MAX or INT_MIN if overflow
// if no conversion is possible, return 0
// ignore non-digit chars and leading spaces
#include <iostream>
#include <climits>
#include <cassert>
#include <vector>
using namespace std;
int myAtoi(string str) {
    // rm leading spaces
    int i = 0;
    int n = str.size();
    while (i < n && str[i] == ' ') i++;

    int sign = 1;
    if (str[i] == '+') i++;
    else if (str[i] == '-') {
        sign = -1;
        i++;
    }

    long res = 0;   // use long to handle int overflow
    // exit loop once int overflow happens in the process
    while (i < n && isdigit(str[i])) {
        res = res * 10 + str[i] - '0';
        if (res * sign > INT_MAX) return INT_MAX;
        else if (res * sign < INT_MIN) return INT_MIN;
        i++;
    }
    res *= sign;
    return res > INT_MAX ? INT_MAX : (res < INT_MIN ? INT_MIN : res);
}

int main() {
    vector<string> strs = {"-11", "123", "+123", "  123", "123abc", "123456789000", "-123456789000"};
    vector<int> exp = {-11, 123, 123, 123, 123, INT_MAX, INT_MIN};
    for (int i = 0; i < strs.size(); i++) {
        assert(myAtoi(strs[i]) == exp[i]);
    }
	return 0;
}
