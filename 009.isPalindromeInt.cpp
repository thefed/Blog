// LC 9, Determine whether an integer is a palindrome. Do this without extra space.
// negative integers? No
// convert the integer to string? No extra space!
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
// return true if an integer is palindrome
// return false if negative or ending with '0', e.g. '1210'
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
    vector<int> nums = {-1, 110, 0, 1, 121, 1221, 1000000001, 1234554321};
    vector<int> exp  = {0, 0, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < nums.size(); i++) {
        assert(isPalindrome(nums[i]) == exp[i]);
    }
	return 0;
}
