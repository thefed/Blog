// LC 69, impl int sqrt(int)
#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
using namespace std;
int mySqrt(int x) {
	if (x < 0) return 0;
	if (x <= 1) return x;
	if (x < 4) return 1;

	int low = 1, high = x / 2;
	long xL = x;	// 4, 5, 8
	long root;
	while (low < high) {
		root = low + (high - low) / 2;
		if ((root + 1) * (root + 1) <= xL) {
			low = root + 1;
		}
		else if (root * root <= xL) {
			return root;
		} 
		else {
			high = root;
		}
	}
	return low;
}
int main() {
	assert(mySqrt(0) == 0);
	for (int i = 1; i < 4; i++) assert(mySqrt(i) == 1);
	
	for (int i = 4; i < 9; i++) assert(mySqrt(i) == 2);

	assert(mySqrt(17) == 4);

	assert(mySqrt(INT_MAX) == (int)sqrt(INT_MAX));

	return 0;
}