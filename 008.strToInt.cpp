// LC 8, string to integer (atoi)
// return INT_MAX or INT_MIN if overflow
// if no conversion is possible, return 0
// ignore non-digit chars and leading spaces
#include <iostream>
#include <climits>
#include <cassert>
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
    
    long res = 0;   // in case of overflow
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
	assert(myAtoi("-11") == -11);

	assert(myAtoi("123") == 123);

	assert(myAtoi("  123") == 123);

	assert(myAtoi("  123abc") == 123);

	assert(myAtoi("123456789000") == INT_MAX);

	assert(myAtoi("-123456789000") == INT_MIN);
	return 0;
}