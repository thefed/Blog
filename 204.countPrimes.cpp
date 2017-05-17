// LC 204, count the num of primes < n (n >= 0)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int countPrimes(int n) {
	vector<char> isPrime(n, 1);
	int cnt = 0;	// num of primes
	for (int i = 2; i < n; i++) {
		if (isPrime[i]) {	// find i, mark i, 2i, 3i, ...
			cnt++;
			for (int j = 2; j * i < n; j++) {
				isPrime[i*j] = 0;
			}
		}
	}
	return cnt;
}
int main() {
	// 9: 2 3 5 7
	// find 2, mark 4,6,8 
	// find 3, mark 6,9,..
	// find 5, mark 10..
	// find 7, mark 14..
	assert(countPrimes(9) == 4);
	return 0;
}