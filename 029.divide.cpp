// LC 29, divide two integers, without using multiplication, division and mod operator.
// If it is overflow, return MAX_INT.
#include <iostream>
#include <climits>
#include <cassert>
#include <vector>
using namespace std;
// method: binary search + bit manipulation
// check operands sign, divide by 0 error
// convert to long type to handle overflow
// dividend = divisor * (1 + 2 + 4 + 8 + ... + 2^k), find k = 1 or 0

// e.g. 50/7
int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {   // result overflow
        return INT_MAX;
    }
    if (dividend == 0) return 0;

    bool isDiffsign = (dividend > 0) ^ (divisor > 0);  // check signs
    // use long type to in case of int overflow (e.g. divisor = INT_MIN)
    long dividendL = labs(dividend);
    long divisorL = labs(divisor);

    // left shift divisor (*2) until it is greater than divident
    int res = 0;
    while (dividendL >= divisorL) {
        // int multiple = divisorL;  // current multiple = x * divisorL, x=1,2,4,8...
        // int tmpRes = 1;
        // while (multiple < dividendL - multiple) {
        //     multiple <<= 1;
        //     tmpRes <<= 1;
        // }
        // // update remaining dividend
        // dividendL -= multiple;
        // res += tmpRes;
        int shift = 0;  // num of bits to shift left
        while (dividendL >= (divisorL << shift)) {
            shift++;
        }
        dividendL -= divisorL << (shift - 1);
        res += 1 << (shift - 1);
    }
    return isDiffsign ? -res: res;
}
int main() {
    vector<int> dividends = {1,      1,2,36,-6,-6,-10,-1, INT_MAX, INT_MIN};
    vector<int> divisors =  {0,      2,2,7, 7, -7,-7,  1, INT_MAX, INT_MIN};
    vector<int> exps =      {INT_MAX,0,1,5, 0, 0, 1,  -1, 1, 1};
    for (int i = 0; i < dividends.size(); i++) {
        int res = divide(dividends[i], divisors[i]);
        assert(res == exps[i]);
    }
}
