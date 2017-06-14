// LC 166, fraction to recurring recimal
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.
// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>
#include <cmath>
using namespace std;
// hash table, simulate long division, 
string fractionToDecimal(int numerator, int denominator) {
    string res;
    if (denominator == 0) return res;
    if (numerator == 0) return "0";

    // check sign
    if (numerator < 0 ^ denominator < 0) res += "-";

    // convert to a / b
    long a = labs(numerator);   // dividend
    long b = labs(denominator); // divisor

    // divisable, remain is 0, no fraction
    if (a % b == 0) return res + to_string(a / b);

    // calc integral part
    int integral = a / b;
    res += to_string(integral);

    // calc fraction part
    res += ".";
    unordered_map<int, int> map; // key: digit, val: position in result string
    
    long r = a % b; // r: remainder
    for (; r != 0; r %= b) {
        // meet a recorded remainder
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '('); // insert 1 '(' at the position
            res += ')';
            break;
        }

        // printf("r: %d\n", int(r));
        // remainder is new, add position
        map[int(r)] = res.size();

        r *= 10;

        // append quotient digit
        res += to_string(r / b);
    }
    return res;
}
int main() {
    vector<int> numerators =   {0,4,-4,7,-2,1,2,2,1, INT_MIN,0};
    vector<int> denominators = {0,2,2, 5,5, 4,3,9,7, -1,    -3};
    vector<string> exps = {"","2","-2","1.4","-0.4","0.25","0.(6)","0.(2)","0.(142857)", "2147483648","0"};
    for (int i = 0; i < numerators.size(); i++) {
        string res = fractionToDecimal(numerators[i], denominators[i]);
        printf("test %d, %2d / %d = %s\n\n", i + 1, numerators[i], denominators[i], res.c_str());
        assert(res == exps[i]);
    }
    return 0;
}
/*
test 1,  0 / 0 = 

test 2,  4 / 2 = 2

test 3, -4 / 2 = -2

r: 2
test 4,  7 / 5 = 1.4

r: 2
test 5, -2 / 5 = -0.4

r: 1
r: 2
test 6,  1 / 4 = 0.25

r: 2
test 7,  2 / 3 = 0.(6)

r: 2
test 8,  2 / 9 = 0.(2)

r: 1
r: 3
r: 2
r: 6
r: 4
r: 5
test 9,  1 / 7 = 0.(142857)
*/