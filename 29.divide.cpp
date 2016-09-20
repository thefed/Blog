#include<iostream>
#include<limits.h>
#include<assert.h>
using namespace std;
int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }
    if (dividend == 0) return 0;
    
    bool isDiffsign = (dividend > 0) ^ (divisor > 0);  // check signs
    // use long int to avoid int type overflow
    long dividendL = labs(dividend);
    long divisorL = labs(divisor);
    
    if (dividendL < divisorL) {
    	return 0;	// 6/7
    }
    else if (dividendL == divisorL) {
    	return isDiffsign ? -1 : 1;
    }
    
    // left shift divisor until it is greater than divident
    int res = 0;
    while (dividendL >= divisorL) {
        int multiple = divisorL;  // current multiple 
        int tmpRes = 1;
        while (multiple < dividendL - multiple) {
            multiple <<= 1; // 14, 28
            tmpRes <<= 1; // 2, 4
        }
        // update
        dividendL -= multiple;    // 50/7, 50 - 28 = 22, dvd = 1, quit outer while
        res += tmpRes;  // +4 +2 +1, 
    }
    return isDiffsign ? -res: res;
}
void test() {
	int actual = divide(1, 2);
	assert(actual == 0 && "wrong output");

	actual = divide(2, 2);
	assert(actual == 1 && "wrong output");

	actual = divide(36, 7);
	assert(actual == 5 && "wrong output");

	actual = divide(-6, 7);
	assert(actual == 0 && "wrong output");

	actual = divide(-6, -7);
	assert(actual == 0 && "wrong output");

	actual = divide(-10, -7);
	assert(actual == 1 && "wrong output");

	actual = divide(0, -7);
	assert(actual == 0 && "wrong output");

	actual = divide(-1, 1);
	assert(actual == -1 && "wrong output");

	actual = divide(2147483647, 1);
	assert(actual == 2147483647 && "wrong output");

	actual = divide(-2147483648, -2147483648);
	assert(actual == 1 && "wrong output");
}
int main() {
	test();
}