// LC 12, integer to roman
// given n,  1 <= n <= 3999
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <string>
using namespace std;

// six symbols in roman numeral
// I V X  L  C    D   M
// 1 5 10 50 100 500 1000
// substractive notation (to avoid repeated four chars)
//   4 9  40 90  400 900
string intToRoman(int num) {
    // enumerate all num patterns
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10,9,5,4,1};
    string strs[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    const int size = sizeof(nums) / sizeof(int);
    string res;
    for (int i = 0; i < size; i++) {
        while (num >= nums[i]) {
            res += strs[i];
            num -= nums[i];
        }
    }
    return res;
}
int main() {
    int num = 800;
    string res, exp;
    res = intToRoman(num);
    cout << res << endl;
    assert(res == "DCCC");
    return 0;
}