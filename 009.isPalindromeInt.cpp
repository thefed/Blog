// LC 9, Determine whether an integer is a palindrome. Do this without extra space.
// negative integers? No
// convert the integer to string? No extra space!
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
#include <iostream>
#include <cassert>
using namespace std;
// return if an integer is palindrome
bool isPalindrome(int x) {
	// x is negative or ends with 0
	if (x < 0 || (x > 0 && x % 10 == 0))	return false;

	int reversed = 0;	// partially reversed integer
	while (x > reversed) {
		reversed = reversed * 10 + x % 10;
		x /= 10;
	}
	return (reversed == x || x == reversed / 10);	// can avoid int overflow
}	

int main() {
	assert(!isPalindrome(-1));
	assert(isPalindrome(0));
	assert(isPalindrome(1));
	assert(isPalindrome(121));
	assert(isPalindrome(1221));
	assert(!isPalindrome(100));

	assert(isPalindrome(1234554321));
	return 0;
}