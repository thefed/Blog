// LC 13, roman to integer
// given string s,  return n (1 <= n <= 3999)
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <unordered_map>
using namespace std;

// six symbols in roman numeral
// I V X  L  C    D   M
// 1 5 10 50 100 500 1000
// substractive notation (to avoid repeated four chars)
//   4 9  40 90  400 900
int romanToInt(string s) {
    // process from the back, to better handle case as "IV": 4, "CM": 900
    unordered_map<char, int> charToInt = {{'I',1}, {'V',5}, {'X',10},
        {'L',50}, {'C',100},{'D',500},{'M',1000}};
    int sum = charToInt[s.back()];
    for (int i = s.size() - 2; i >= 0; i--) {
        if (charToInt[s[i]] < charToInt[s[i + 1]]) {
            sum -= charToInt[s[i]]; // e.g., CM, IV
        }
        else {
            sum += charToInt[s[i]];
        }
    }
    return sum;
}
int main() {
    string s = "MCMLIV";
    int res, exp = 1954;
    res = romanToInt(s);
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}
