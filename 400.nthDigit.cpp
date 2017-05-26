// LC 400, return n-th digit of the sequence 1,2,...,10,11,..100,..
// n=3 => 3
// n=11 => 0 (the 0 in '10')
#include <iostream>
#include <cassert>
using namespace std;

int findNthDigit(int n) {
	if (n <= 9) return n;
    // 1-digit 9, start [1..9]
    // 2-digit 100-1 - 9 = 90, start [10..99]
    // 3-digit 1000-1 -9 - 90 = 900, start[100..999]
    
    int len = 1;	// length of num
    long cnt = 9;	// cnt of numbers with given len
    int start = 1;	// 1st len-digit num
    while (n > cnt * len) {
        n -= cnt * len;
        len++;
        cnt *= 10;
        start *= 10;	// 1,10,100...
    }
    
    // mv start to the number that contains the n-th digit
    start += ((n - 1) / len);   // 10, if n in [1..len]

    int remain = (n - 1) % len;	// 1
    // find k-th digit of number start, 12345, find 2nd digit?
    for (int i = 1; i < len - remain; i++) {
        start /= 10;
    }
    return start % 10;
}
int main() {
	for (int i = 1; i <= 9; i++) assert(findNthDigit(i) == i);
	
	assert(findNthDigit(10) == 1);
	assert(findNthDigit(11) == 0);

	assert(findNthDigit(12) == 1);
	assert(findNthDigit(13) == 1);

	int n = 1000000000;
	assert(findNthDigit(n) == 1);
	return 0;
}
